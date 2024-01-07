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
void *podgon_pod_znachenie(void *numPtr, const char *type, int width) {
  if (numPtr == NULL || width <= 0) {
    printf("Ошибка: неверные аргументы\n");
    return NULL;
  }

  if (s21_strcmp(type, "int") == 0) {
    int *int_ptr = (int *)numPtr;
    while (width <= countDigits(numPtr, "int")) {
      *int_ptr /= 10;
      width++;
    }
  } else if (s21_strcmp(type, "long int") == 0) {
    long int *long_ptr = (long int *)numPtr;
    while (width <= countDigits(numPtr, "long int")) {
      *long_ptr /= 10;
      width++;
    }
  } else if (s21_strcmp(type, "short int") == 0) {
    short int *short_ptr = (short int *)numPtr;
    while (width <= countDigits(numPtr, "short int")) {
      *short_ptr /= 10;
      width++;
    }
  } else {
    printf("Неверный тип данных\n");
    return NULL;
  }

  return numPtr;
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

void *D_SSCNAF_SPEC(SSCANF Param, va_list *args, int *count, const char *str) {
  int *int_ptr = NULL;
  short int *short_ptr = NULL;
  char *endptr = NULL;
  int width = Param.width;
  void *answer_ptr = NULL;

  if (Param.spec == 'd') {
    if (Param.length == 0) {
      int temp_int;
      int_ptr = va_arg(*args, int *);
      temp_int = (int)strtol(str, &endptr, 10);
      *int_ptr = temp_int;
      if (width < countDigits(&temp_int, "int")) {
        podgon_pod_znachenie(&temp_int, "int", Param.width);
        answer_ptr = int_ptr;
      }
    } else if (Param.length == 'h') {
      short int temp_short;
      short_ptr = va_arg(*args, short int *);
      temp_short = (short int)strtol(str, &endptr, 10);
      *short_ptr = temp_short;
      if (width < countDigits(&temp_short, "short int")) {
        podgon_pod_znachenie(&temp_short, "short int", Param.width);
        answer_ptr = short_ptr;
      }
    }
  }
  (*count)++;
  return answer_ptr;
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
        // str += countDigits(D_SSCNAF_SPEC(Param, &args, &count, str), "int");
        int *answer = D_SSCNAF_SPEC(Param, &args, &count, str);
      }

      cleaning(&Param);
    }
  }
  va_end(args);
  return count;
}

int main() {
  int number1 = 0;
  char number2;
  const char *input = "123 3565";
  int result = s21_sscanf(input, "%3d %c", &number1, &number2);

  printf("Result: %d\n", result);
  printf("Buffer: %d %c\n", number1, number2);

  return 0;
}

// int *podgon_pod_znachenie(int *int_ptr, SSCANF Param) {
//   while (Param.width <= countDigits(*int_ptr) && Param.width != 0) {
//     *int_ptr /= 10;
//     Param.width++;
//   }
//   return int_ptr;
// }
