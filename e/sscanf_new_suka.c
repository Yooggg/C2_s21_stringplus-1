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
  } else if (s21_strcmp(type, "unsigned int") == 0) {
    unsigned int *uIntPtr = (unsigned int *)numPtr;
    result = snprintf(NULL, 0, "%u", *uIntPtr);
  } else if (s21_strcmp(type, "unsigned short int") == 0) {
    unsigned short int *uhIntPtr = (unsigned short int *)numPtr;
    result = snprintf(NULL, 0, "%hu", *uhIntPtr);
  } else if (s21_strcmp(type, "unsigned long int") == 0) {
    unsigned long int *ulIntPtr = (unsigned long int *)numPtr;
    result = snprintf(NULL, 0, "%lu", *ulIntPtr);
  }

  else {
    // Обработка неверного типа
    printf("Неверный тип данных\n");
    result = -1;
  }

  return result;  // Возвращаем результат
}

int check_na_NULL(void *ptr) {
  int flag = 0;
  if (ptr == NULL) {
    flag = 1;
  }
  return flag;
}
char *s21_strchr(const char *str, int c) {
  while (*str != '\0') {
    if (*str == (char)c) {
      return (char *)str;  // нашли char, вернули адрес
    }
    str++;
  }

  // ну, коль не нашли, вернем NULL
  return NULL;
}
int *podgon_pod_znachenie_int(int *int_ptr, int width) {
  int flag = check_na_NULL(int_ptr);
  if (flag != 1) {
    int number = countDigits(int_ptr, "int");

    while (width < number) {
      *int_ptr /= 10;
      width++;
    }
  }
  return int_ptr;
}

long int *podgon_pod_znachenie_long_int(long int *long_ptr, int width) {
  int flag = check_na_NULL(long_ptr);
  if (flag != 1) {
    int number = countDigits(long_ptr, "int");
    while (width < number) {
      *long_ptr /= 10;
      width++;
    }
  }
  return long_ptr;
}

unsigned short int *podgon_pod_znachenie_unsigned_short_int(
    unsigned short int *ushort_ptr, int width) {
  int flag = check_na_NULL(ushort_ptr);
  if (flag != 1) {
    int number = countDigits(ushort_ptr, "unsigned short int");
    while (width < number) {
      *ushort_ptr /= 10;
      width++;
    }
  }
  return ushort_ptr;
}

unsigned long int *podgon_pod_znachenie_unsigned_long_int(
    unsigned long int *ulong_ptr, int width) {
  int flag = check_na_NULL(ulong_ptr);
  if (flag != 1) {
    int number = countDigits(ulong_ptr, "unsigned long int");
    while (width < number) {
      *ulong_ptr /= 10;
      width++;
    }
  }
  return ulong_ptr;
}
short int *podgon_pod_znachenie_short_int(short int *short_ptr, int width) {
  int flag = check_na_NULL(short_ptr);
  if (flag != 1) {
    int number = countDigits(short_ptr, "short int");
    while (width < number) {
      *short_ptr /= 10;
      width++;
    }
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

    if (Param.width < countDigits(int_ptr, "int") && Param.width != 0) {
      podgon_pod_znachenie_int(int_ptr, Param.width);
    }
  }
  (*count)++;
  return int_ptr;
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

unsigned int *JUST_U(SSCANF Param, va_list *args, int *count, const char *str) {
  unsigned int *uint_ptr = NULL;
  char *endptr = NULL;

  if (Param.length == 0) {
    uint_ptr = va_arg(*args, unsigned int *);
    *uint_ptr = (unsigned int)strtoul(str, &endptr, 10);

    if (Param.width < countDigits(uint_ptr, "int") && Param.width != 0) {
      // Если указана ширина, подгоняем значение
      podgon_pod_znachenie_int((int *)uint_ptr, Param.width);
    }
  }
  (*count)++;
  return uint_ptr;
}
unsigned short int *U_WITH_H(SSCANF Param, va_list *args, int *count,
                             const char *str) {
  unsigned short int *ushort_ptr = NULL;
  char *endptr = NULL;

  if (Param.length == 'h') {
    ushort_ptr = va_arg(*args, unsigned short int *);
    *ushort_ptr = (unsigned short int)strtoul(str, &endptr, 10);
    if (Param.width < countDigits(ushort_ptr, "unsigned short int") &&
        Param.width != 0) {
      podgon_pod_znachenie_unsigned_short_int(ushort_ptr, Param.width);
    }
  }
  (*count)++;
  return ushort_ptr;
}
unsigned long int *U_WITH_L(SSCANF Param, va_list *args, int *count,
                            const char *str) {
  unsigned long int *ulong_ptr = NULL;
  char *endptr = NULL;

  if (Param.length == 'l') {
    ulong_ptr = va_arg(*args, unsigned long int *);
    *ulong_ptr = strtoul(str, &endptr, 10);
    if (Param.width < countDigits(ulong_ptr, "unsigned long int") &&
        Param.width != 0) {
      podgon_pod_znachenie_unsigned_long_int(ulong_ptr, Param.width);
    }
  }
  (*count)++;
  return ulong_ptr;
}

int *O_SPEC(va_list *args, int *count, const char *str) {
  int *oint_ptr = va_arg(*args, int *);
  char *endptr = NULL;
  *oint_ptr = strtol(str, &endptr, 8);
  (*count)++;
  return oint_ptr;
}
unsigned int *X_SPEC(va_list *args, int *count, const char *str) {
  unsigned int *xint_ptr = va_arg(*args, unsigned int *);
  char *endptr = NULL;
  *xint_ptr = strtol(str, &endptr, 16);
  (*count)++;
  return xint_ptr;
}

void *P_SPEC(va_list *args, int *count, const char *str, int *a) {
  char *endptr;
  void **void_ptr = va_arg(*args, void **);
  *void_ptr = (void *)strtoul(str, &endptr, 16);
  *a += endptr - str;
  (*count)++;

  return void_ptr;
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
          int *answer = JUST_D(Param, &args, &count, str);
          str += countDigits(answer, "int");
        } else if (Param.length == 'h') {
          short int *answer = D_WITH_H(Param, &args, &count, str);
          str += countDigits(answer, "short int");
        } else if (Param.length == 'l') {
          long int *answer = D_WITH_L(Param, &args, &count, str);
          str += countDigits(answer, "long int");
        }
      } else if (Param.spec == 'u') {
        if (Param.length == 0) {
          unsigned int *answer = JUST_U(Param, &args, &count, str);
          str += countDigits(answer, "unsigned int");
        } else if (Param.length == 'h') {
          unsigned short int *answer = U_WITH_H(Param, &args, &count, str);
          str += countDigits(answer, "unsigned short int");
        } else if (Param.length == 'l') {
          unsigned long int *answer = U_WITH_L(Param, &args, &count, str);
          str += countDigits(answer, "unsigned long int");
        }
      } else if (Param.spec == 'o') {
        int *o_ptr = O_SPEC(&args, &count, str);
        str += countDigits(o_ptr, "int");
      } else if (Param.spec == 'x' || Param.spec == 'X') {
        unsigned int *x_ptr = X_SPEC(&args, &count, str);
        str += countDigits(x_ptr, "unsigned int");
      } else if (Param.spec == 'p') {
        int prohod = 0;
        P_SPEC(&args, &count, str, &prohod);
        str += prohod;
      }

      cleaning(&Param);
    }
  }
  va_end(args);
  return count;
}

int main() {
  void *ptr1 = NULL;
  void *ptr2 = NULL;
  const char *input = "0x7fff12345678 0x7fff87654321";
  int result = sscanf(input, "%p %p", &ptr1, &ptr2);
  printf("Результат: %d\n", result);
  printf("Первый адрес: %p\n", ptr1);
  printf("Второй адрес: %p\n", ptr2);
  return 0;
}
