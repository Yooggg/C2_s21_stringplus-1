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
int countDigits(
    int number) {  //исло цифр в int числе, надо для int спецификаторов
  // Обрабатываем случай отрицательных чисел
  if (number < 0) {
    number = -number;
  }

  int digitCount = 0;

  // Обрабатываем случай числа равного 0
  if (number == 0) {
    return 1;
  }

  // Считаем количество цифр в числе
  while (number > 0) {
    number /= 10;
    digitCount++;
  }

  return digitCount;
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
int *D_SSCNAF_SPEC(SSCANF Param, va_list *args, int *count, const char *str) {
  int *int_ptr;
  if (Param.spec == 'd') {
    if (Param.length == 0) {
      int_ptr = va_arg(*args, int *);
      *int_ptr = atoi(str + Param.width);
    } else if (Param.spec = 'h') {
    }
  }
  (*count)++;
  return int_ptr;
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
        int *int_ptr = D_SSCNAF_SPEC(Param, &args, &count, str);
        str += countDigits(*int_ptr);
      }

      cleaning(&Param);
    }
  }

  return count;
}

int main() {
  int number1 = 0;
  int number2 = 0;
  const char *input = "123456 3565";
  int result = s21_sscanf(input, "%d %d", &number1, &number2);

  printf("Result: %d\n", result);
  printf("Buffer: %d %d\n", number1, number2);

  return 0;
}
