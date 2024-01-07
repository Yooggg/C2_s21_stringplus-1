#include "s21_string.h"
/* Спецификатор формата для сканирующих функций следует прототипу:
 %[*][ширина][длина]спецификатор. вот так вводить, по другому не вводить,хотя
 можно и ввести */
// Размер буфера по умолчанию
#define BUFFSIZE 1024
typedef struct {
  int spec;             // support Specifiers below
  int width;            // ширина
  int length;           // разные типы support [h] | [l] | [L]
  int sign;             // плюс или минус ширина
  char buff[BUFFSIZE];  // массив для мусора
  int i;                // индекс мусорного массива
  char zvezda;          // это игнор
} SSCANF;
int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 != '\0' && *str2 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }

  return (*str1 - *str2);
}
void cleaning(SSCANF *params) {
  params->spec = 0;
  params->width = 0;
  params->length = 0;
  params->sign = 0;
  params->i = 0;  //индекс массива
  params->zvezda = '\0';
  // Инициализация массива buff нулями
  for (int j = 0; j < BUFFSIZE; ++j) {
    params->buff[j] = 0;
  }
}
int countDigits(void *numPtr, const char *type) {
  int result = 0;  // Переменная для хранения результата

  if (s21_strcmp(type, "int") == 0) {
    int *intPtr = (int *)numPtr;
    result = snprintf(NULL, 0, "%d", *intPtr);
  } else if (s21_strcmp(type, "long int") == 0) {
    long int *longIntPtr = (long int *)numPtr;
    result = snprintf(NULL, 0, "%ld", *longIntPtr);
  } else if (s21_strcmp(type, "short int") == 0) {
    short int *shortIntPtr = (short int *)numPtr;
    result = snprintf(NULL, 0, "%hd", *shortIntPtr);
  } else {
    // Обработка неверного типа
    printf("Неверный тип данных\n");
    result = -1;
  }

  return result;  // Возвращаем результат
}

char *s21_strchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == (char)c) {
      return (char *)str;  // нашли char, вернули адрес
    }
    str++;
  }

  // If the character is not found, return NULL
  return NULL;
}
int *podgon_pod_znachenie_int(int *int_ptr, int width) {
  int number = countDigits(int_ptr, "int");
  printf("int ptr %d\n", *int_ptr);

  printf("digits %d\n", countDigits(int_ptr, "int"));

  while (width < number) {
    *int_ptr /= 10;
    width++;
    printf("chlen\n");
  }

  return int_ptr;
}

long int *podgon_pod_znachenie_long_int(long int *long_ptr, int width) {
  if (long_ptr == NULL) {
    printf("Ошибка: неверные аргументы\n");
    return NULL;
  }

  int number = countDigits(long_ptr, "int");
  while (width < number) {
    *long_ptr /= 10;
    width++;
  }

  return long_ptr;
}

short int *podgon_pod_znachenie_short_int(short int *short_ptr, int width) {
  if (short_ptr == NULL) {
    printf("Ошибка: неверные аргументы\n");
    return NULL;
  }
  printf("answer%hd\n", *short_ptr);
  int number = countDigits(short_ptr, "short int");
  while (width < number) {
    *short_ptr /= 10;
    width++;
  }

  return short_ptr;
}
int PARSER(const char *str,
           SSCANF *Param) {  //ЗДЕСЬ МЫ ПЕРЕДАЕМ ФОРМАТНУЮ СТРОКУ И
                             //ДВИЖЕМСЯ,ПОКА НЕ СОБЕРЕМ СЕЦИФИКАТОР
  int shift = 1;
  while (!Param->spec) {
    if (s21_strchr("GosexcdiuEfgXpn%", str[shift]))
      Param->spec = str[shift];
    else if (s21_strchr("hlL", str[shift]))
      Param->length = str[shift];
    else if ('0' <= str[shift] && str[shift] <= '9')
      Param->width = Param->width * 10 + str[shift] - '0';
    else if (str[shift] == '*')
      Param->zvezda = str[shift];
    if (!Param->spec) shift++;
  }
  return shift;
}
char *CHAR_FUNC(va_list *args, int *count, const char *str) {
  char *char_ptr = va_arg(*args, char *);
  *char_ptr = *str;
  (*count)++;
  return char_ptr;
}

int *JUST_D(SSCANF Param, va_list *args, int *count, const char *str) {
  int *int_ptr = NULL;
  char *endptr = NULL;
  if (Param.length == 0) {
    int_ptr = va_arg(*args, int *);
    *int_ptr = (int)strtol(str, &endptr, 10);
    printf("otvet %d\n", *int_ptr);
    // printf("digits %d\n",countDigits(int_ptr, "int"));
    printf("int %d\n", Param.width);

    if (Param.width < countDigits(int_ptr, "int") && Param.width != 0) {
      podgon_pod_znachenie_int(int_ptr, Param.width);
    }
  }
  (*count)++;
  return int_ptr;
}
long int *D_SSCNAF_SPEC(SSCANF Param, va_list *args, int *count,
                        const char *str) {
  int *int_ptr = NULL;
  short int *short_ptr = NULL;
  char *endptr = NULL;
  int width = Param.width;
  long int *answer_ptr = NULL;

  if (Param.spec == 'd') {
    if (Param.length == 0) {
      int_ptr = va_arg(*args, int *);
      *int_ptr = (int)strtol(str, &endptr, 10);
      if (width < countDigits(int_ptr, "int")) {
        podgon_pod_znachenie_int(int_ptr, Param.width);
        // answer_ptr = int_ptr;
      }
    } else if (Param.length == 'h') {
      short_ptr = va_arg(*args, short int *);
      *short_ptr = (short int)strtol(str, &endptr, 10);
      if (width < countDigits(short_ptr, "short int")) {
        podgon_pod_znachenie_short_int(short_ptr, Param.width);
        // answer_ptr = short_ptr;
      }
    }
  }
  (*count)++;
  return answer_ptr;
}
short int *D_WITH_H(SSCANF Param, va_list *args, int *count, const char *str) {
  short int *short_ptr = NULL;
  char *endptr = NULL;

  if (Param.length == 'h') {
    short_ptr = va_arg(*args, short int *);
    *short_ptr = (short int)strtol(str, &endptr, 10);
    if (Param.width < countDigits(short_ptr, "short int") && Param.width != 0) {
      podgon_pod_znachenie_short_int(short_ptr, Param.width);
    }
  }
  (*count)++;
  return short_ptr;
}

long int *D_WITH_L(SSCANF Param, va_list *args, int *count, const char *str) {
  long int *long_ptr = NULL;
  char *endptr = NULL;

  if (Param.length == 'l') {
    long_ptr = va_arg(*args, long int *);
    *long_ptr = strtol(str, &endptr, 10);
    if (Param.width < countDigits(long_ptr, "long int") && Param.width != 0) {
      podgon_pod_znachenie_long_int(long_ptr, Param.width);
    }
  }
  (*count)++;
  return long_ptr;
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  int count = 0;
  va_start(args, format);
  SSCANF Param = {0};
  cleaning(&Param);
  while (*format != '\0') {
    if (*format == '%') {
      format += PARSER(format, &Param);
    } else {
      Param.buff[Param.i++] =
          *format;  // это увеличение индекса массива для ненужных символов
      if (*format == *str) {
        str++;
      }
      format++;
    }
    //движемся по форматной строке
    //теперь условие обработки благодаря нашей замечательной структуре
    if (Param.spec != 0) {
      if (Param.spec ==
          'c') {  // самая простая обработка, поэтому засунул в начало

        char *char_ptr = CHAR_FUNC(&args, &count, str);
        str += sizeof(*char_ptr);
      } else if (Param.spec == 'd' || Param.spec == 'i') {  // diuoxXp

        if (Param.length == 0) {
          format++;
          int *answer = JUST_D(Param, &args, &count, str);
          str += countDigits(answer, "int");
          printf("str %c\n", *str);
        } else if (Param.length == 'h') {
          short int *answer = D_WITH_H(Param, &args, &count, str);
          str += countDigits(answer, "short int");
        } else if (Param.length == 'l') {
          long int *answer = D_WITH_L(Param, &args, &count, str);
          str += countDigits(answer, "long int");
        }
      }

      cleaning(&Param);
    }
  }
  va_end(args);
  return count;
}

int main() {
  int number1 = 0;
  int number2 = 0;
  const char *input = "123456 789";
  int result = s21_sscanf(input, "%1ld %2hd", &number1, &number2);

  printf("Result: %d\n", result);
  printf("Buffer: %d %d\n", number1, number2);

  return 0;
}
