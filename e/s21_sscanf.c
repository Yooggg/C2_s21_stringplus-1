#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"
size_t s21_strlen(const char *str) {
  size_t count = 0;
  while (*str != '\0') {
    count++;
    str++;
  }
  return count;
}
int readNumberWithWidth(const char *str, int *int_ptr, int width) {
  int value = 0;
  int sign = 1;
  int i = 0;

  // Определяем знак числа
  if (str[i] == '-') {
    sign = -1;
    i++;
  }

  // Пропускаем нули перед числом (если они есть)
  while (str[i] == '0') {
    i++;
  }

  // Считываем число, учитывая указанную ширину поля
  int count = 0;
  while (*str >= '0' && *str <= '9' && count < width) {
    value = value * 10 + (str[i] - '0');
    i++;
    count++;
  }

  *int_ptr = value * sign;
  return i;
}

int int_counter(int a) {
  int count = 0;
  while (a > 0) {
    a = a / 10;
    count++;
  }
  return count;
}

int double_counter(double a) {
  char drob_buffer[1000];
  sprintf(drob_buffer, "%g", a);
  return strlen(drob_buffer);
}

int s21_sscanf(const char *str, const char *format, ...) {
  va_list args;
  int count = 0;
  size_t str_index = 0, format_index = 0;
  va_start(args, format);

  while (format[format_index] != '\0') {
    if (format[format_index] == '%' && format[format_index + 1] != '\0') {
      format_index++;  // переходим к символу после '%'
      int width = 0;
      if (format[format_index] >= '0' && format[format_index] <= '9') {
        width = format[format_index] - '0';  // получаем ширину поля
        if (width > s21_strlen(str)) {
          width = s21_strlen(str);
        }
        format_index++;
      }
      switch (format[format_index]) {
        case 'd': {
          int *int_ptr = va_arg(args, int *);
          *int_ptr = atoi(str + str_index);
          str_index += int_counter(*int_ptr);
          count++;
          break;
        }
        case 'f': {  // вещественное число
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtof(str + str_index, NULL);
          int double_width = double_counter(*float_ptr);
          str_index += (width > 0 && width > double_width)
                           ? width
                           : double_width;  // учитываем ширину поля
          count++;
          break;
        }
        case 'c': {
          char *char_ptr = va_arg(args, char *);
          *char_ptr = str[str_index];
          str_index++;
          count++;
          break;
        }
        case 's': {
          if (str[str_index] != '\0') {
            char *str_arg = va_arg(args, char *);
            int str_len = 0;
            while (str[str_index] != '\0' && str[str_index] != '\n' &&
                   str_len < width) {
              if (str[str_index] == ' ' && str_len == 0) {
                str_index++;
                continue;
              }
              str_arg[str_len] = str[str_index];
              str_len++;
              str_index++;
            }
            str_arg[str_len] = '\0';
            str_index += (width > str_len) ? width - str_len
                                           : 0;  // учитываем ширину поля
            count++;
          } else {
            printf("ERROR: Not enough characters in str.\n");
            break;
          }
          break;
        }
        case 'i': {
          char *endptr;
          int *int_ptr = va_arg(args, int *);
          *int_ptr = strtol(str + str_index, &endptr, 0);
          str_index = endptr - str;
          str_index += width;
          count++;
          break;
        }
        case 'e':
        case 'E': {
          char *endptr;
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtold(str + str_index, &endptr);
          str_index = endptr - str;
          str_index += width;
          count++;
          break;
        }
        case 'g':
        case 'G': {
          float *float_ptr = va_arg(args, float *);
          *float_ptr = strtod(str + str_index, NULL);
          str_index += double_counter(*float_ptr);
          str_index += width;
          count++;
          break;
        }
        case 'u': {
          char *endptr;
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 10);
          str_index = endptr - str;
          int digits = endptr - (str + str_index);
          str_index += width - digits;
          count++;
          break;
        }

        case 'o': {
          char *endptr;
          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 8);
          str_index = endptr - str;
          int digits = endptr - (str + str_index);
          str_index += width - digits;
          count++;
          break;
        }
        case 'x':
        case 'X': {
          char *endptr;

          unsigned int *uint_ptr = va_arg(args, unsigned int *);
          *uint_ptr = strtoul(str + str_index, &endptr, 16);
          str_index = endptr - str;
          int digits = endptr - (str + str_index);
          str_index += width - digits;
          count++;
          break;
        }
        case 'p': {
          char *endptr;
          void **void_ptr = va_arg(args, void **);
          *void_ptr = (void *)strtoul(str + str_index, &endptr, 16);
          str_index = endptr - str;
          int digits = endptr - (str + str_index);
          str_index += width - digits;
          count++;
          break;
        }
        case 'n': {
          int *int_ptr = va_arg(args, int *);
          *int_ptr = str_index;
          break;
        }
        case '%': {
          char *char_ptr = va_arg(args, char *);
          *char_ptr = '%';
          count++;
          break;
        }
        default:
          printf("ERROR: Unsupported format specifier.\n");
          break;
      }
      format_index++;
    } else {
      format_index++;
    }
  }

  va_end(args);

  return count;
}

int main() {
  // Тестовая строка
  // char input[] = "12345 67890 -54321 0";
  char input[] = "12345";

  int num1 = 0;
  // int num2 = 0;
  // int num3 = 0;
  // int num4 = 0;

  // Используем новую функцию s21_sscanf для чтения целых чисел с указанной
  // шириной поля
  s21_sscanf(input, "%d", &num1);

  // Вывод результатов
  printf("Test values: %d\n", num1);

  return 0;
}
