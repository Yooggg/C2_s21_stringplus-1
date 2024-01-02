#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long double ld_round(long double num, int precision) {
  double mult = pow(10.0, precision);
  double ret = round(num * mult) / mult;
  return ret;
}

long double ld_pow(long double num, int precision) {
  for (int i = 0; i < precision; i++) {
    num /= 10;
  }
  return num;
}

int custom_itoa(char *str, long int value) {
  long int count = 0;
  long int temp = value;
  long int length = 0;
  long int is_negative = 0;

  if (value < 0) {
    is_negative = 1;
    temp = -temp;
  }

  if (temp == 0) {
    length = 1;
  } else {
    length = (long int)log10(temp) + 1;
  }

  if (is_negative) {
    str[count++] = '-';
  }

  for (int i = length - 1; i >= 0; i--) {
    char tmp = '0' + ((value < 0 ? -value : value) / (long int)pow(10, i)) % 10;
    str[count++] = tmp;
  }

  // str[count] = '\0';
  return count;
}

int custom_utoa(char *str, long int value) {
  int count = 0;
  unsigned long int temp = value;
  int length = 0;

  if (temp == 0) {
    length = 1;
  } else {
    length = (long int)log10(temp) + 1;
  }

  for (int i = length - 1; i >= 0; i--) {
    str[count++] = '0' + (temp / (long int)pow(10, i)) % 10;
  }

  // str[count] = '\0';
  return count;
}

int custom_utohex(char *str, unsigned long int value) {
  int count = 0;

  if (value == 0) {
    str[count++] = '0';
  }

  while (value != 0) {
    unsigned long int digit = value % 16;
    str[count++] = (digit < 10) ? ('0' + digit) : ('a' + digit - 10);
    value /= 16;
  }

  // str[count] = '\0';

  int start = 0;
  int end = count - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
  return count;
}

int custom_ftoa(char *str, long double num, int precision) {
  int count = 0;
  int fl = num < 0 ? 1 : 0;
  if (fl) {
    num = fabsl(num);
    *str++ = '-';
    // count++; //возможно ошибка
  }
  long int intPart = (long int)num;

  count += custom_itoa(str, intPart);
  str += count;

  *str++ = '.';
  count++;
  num = ld_round(num, precision);
  long double fractionalPart = num - intPart;

  for (int i = 0; i < precision; i++) {
    fractionalPart *= 10;
    long int digit = (long int)(fractionalPart + ld_pow(1.0, precision));
    *str++ = '0' + digit;
    count++;
    fractionalPart -= digit;
  }
  if (fl) count++;

  return count;
}

int custom_etoa(char *str, long double num, int precision) {
  int exp_value = 0;
  int count = 0;
  int fl = num < 0 ? 1 : 0;
  if (fl) {
    num = fabsl(num);
    *str++ = '-';
    // count++; //возможно ошибка
  }

  int exp_fl = num >= 1 ? 1 : 0;
  long int intPart = (long int)num;

  while (intPart >= 10 && num != 0 && exp_fl) {
    intPart /= 10;
    num /= 10;
    exp_value++;
  }
  while (num <= 1 && num != 0 && !exp_fl) {
    num *= 10;
    exp_value--;
  }
  if (exp_value < 0) intPart = (long int)num;

  count += custom_itoa(str, intPart);
  str += count;

  *str++ = '.';
  count++;

  num = ld_round(num, precision);
  long double fractionalPart = num - intPart;

  for (int i = 0; i < precision; i++) {
    fractionalPart *= 10;
    long int digit = (long int)(fractionalPart + ld_pow(1.0, precision));
    *str++ = '0' + digit;
    count++;
    fractionalPart -= digit;
  }

  *str++ = 'e';
  count++;

  *str++ = exp_value >= 0 ? '+' : '-';
  count++;
  if (abs(exp_value) < 10) {
    *str++ = '0';
    count++;
  }
  count += custom_itoa(str, abs(exp_value));
  if (fl) count++;

  return count;
}

int custom_getoa(char *str, long double num, int precision) {
  int exp_value = 0;
  int count = 0;
  int fl = num < 0 ? 1 : 0;
  if (fl) {
    num = fabsl(num);
    *str++ = '-';
    // count++; возможно ошибка
  }
  long int intPart = (long int)num;

  while (intPart >= 10 && num != 0 && !fl) {
    intPart /= 10;
    num /= 10;
    exp_value++;
  }
  while (num <= 1 && num != 0 && fl) {
    num *= 10;
    exp_value--;
  }
  if (exp_value < 0) intPart = (long int)num;

  count += custom_itoa(str, intPart);
  str += count;

  *str++ = '.';
  count++;

  long double fractionalPart = num - intPart;

  for (int i = 0; i < precision; i++) {
    fractionalPart *= 10;
    long int digit = (long int)(fractionalPart + 1.0 / (precision + 1));
    *str++ = '0' + digit;
    count++;
    fractionalPart -= digit;
  }

  *str++ = 'e';
  count++;

  *str++ = exp_value >= 0 ? '+' : '-';
  count++;
  if (abs(exp_value) < 10) {
    *str++ = '0';
    count++;
  }
  count += custom_itoa(str, abs(exp_value));
  if (fl) count++;

  return count;
}

int custom_gftoa(char *str, long double num, int precision) {
  int count = 0;
  int fl = num < 0 ? 1 : 0;
  if (fl) {
    num = fabsl(num);
    *str++ = '-';
    // count++; возможно ошибка
  }
  long double cpy = num;
  long int intPart = (long int)num;

  int int_count = 0;
  while (cpy > 1) {
    cpy /= 10;
    int_count++;
  }

  count += custom_itoa(str, intPart);
  str += count;
  if ((num != intPart && ((num - intPart) >= 0.00005 && num > 0) &&
       int_count < precision)) {
    *str++ = '.';
    count++;

    long double fractionalPart = num - intPart;

    for (int i = 0; i < precision - int_count; i++) {
      fractionalPart *= 10;
      long int digit = (long int)(fractionalPart + 1.0 / (precision + 1));
      *str++ = '0' + digit;
      count++;
      fractionalPart -= digit;
    }
  }  // else if ((num != intPart && ((num - intPart) >= 0.00005 && num > 0) &&
     // int_count < precision))
  if (fl) count++;
  return count;
}

int d_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  long int value = va_arg(args, long int);
  char temp[400] = {'0'};
  int count = 0;
  if (length_arr[1]) {
    count = custom_itoa(temp, (long int)value);
  } else if (length_arr[0]) {
    count = custom_itoa(temp, (short int)value);
  } else {
    count = custom_itoa(temp, (int)value);
  }

  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  strcpy(str, temp);
  return count;
}

int f_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  char temp[400] = {'0'};
  int count = 0;
  if (length_arr[2]) {
    long double value = va_arg(args, long double);
    count = custom_ftoa(temp, value, 6);
  } else {
    double value = va_arg(args, double);
    count = custom_ftoa(temp, value, 6);
  }
  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  strcpy(str, temp);
  return count;
}

int g_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  char temp[400] = {'0'};
  int count = 0;
  if (length_arr[2]) {
    long double value = va_arg(args, long double);
    if (fabsl(value) < 0.0001 || fabsl(value) >= 1.0e+6)
      count = custom_getoa(temp, value, 5);
    else
      count = custom_gftoa(temp, value, 6);
  } else {
    double value = va_arg(args, double);
    if (fabs(value) < 0.0001 || fabs(value) >= 1.0e+6)
      count = custom_getoa(temp, value, 5);
    else
      count = custom_gftoa(temp, value, 6);
  }

  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  strcpy(str, temp);
  return count;
}

int s_sprintf(char *str, va_list args, int width_val) {
  char *svalue = va_arg(args, char *);
  int count = 0;

  while (width_val != -1 && width_val > (int)strlen(svalue)) {
    *str++ = ' ';
    count++;
    width_val--;
  }

  while (*svalue != '\0') {
    *str++ = *svalue++;
    count++;
  }

  return count;
}

int e_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  char temp[400] = {'0'};
  int count = 0;

  if (length_arr[2]) {
    long double value = va_arg(args, long double);
    count = custom_etoa(temp, value, 6);
  } else {
    double value = va_arg(args, double);
    count = custom_etoa(temp, value, 6);
  }

  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }

  return count;
}

int o_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  int count = 0;
  unsigned long int value = va_arg(args, unsigned long int);
  if (length_arr[1]) {
    value = (unsigned long int)value;
  } else if (length_arr[0]) {
    value = (unsigned short int)value;
  } else {
    value = (unsigned int)value;
  }

  // Преобразование числа в восьмеричную строку
  char octalStr[400];
  int idx = 0;

  // Обработка особых случаев
  if (value == 0) {
    octalStr[idx++] = '0';
  } else {
    while (value != 0) {
      octalStr[idx++] = (value % 8) + '0';
      value /= 8;
    }
  }

  // Копирование результата в обратном порядке в строку str

  while (width_val != -1 && width_val > (int)strlen(octalStr)) {
    str[count++] = ' ';
    width_val--;
  }

  while (idx > 0) {
    str[count++] = octalStr[--idx];
  }

  return count;
}

int u_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  char temp[400] = {'0'};
  int count = 0;

  unsigned long int value = va_arg(args, unsigned long int);

  if (length_arr[1]) {
    count = custom_utoa(temp, (unsigned long int)value);
  } else if (length_arr[0]) {
    count = custom_utoa(temp, (unsigned short int)value);
  } else {
    count = custom_utoa(temp, (unsigned int)value);
  }

  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  strcpy(str, temp);
  return count;
}

int x_sprintf(char *str, va_list args, int length_arr[3], int width_val) {
  unsigned long int value = va_arg(args, unsigned long int);
  char temp[400] = {'0'};
  int count = 0;

  if (length_arr[1]) {
    count = custom_utohex(temp, (unsigned long int)value);
  } else if (length_arr[0]) {
    count = custom_utohex(temp, (unsigned short int)value);
  } else {
    count = custom_utohex(temp, (unsigned int)value);
  }

  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  strcpy(str, temp);
  return count;
}

int p_sprintf(char *str, va_list args, int width_val) {
  char temp[400] = {'0'};
  int count = 0;
  const uintptr_t ptr = (uintptr_t)va_arg(args, void *);

  if ((void *)ptr == NULL) {
    char *ret = "(nil)";
    for (int i = 0; i < 5; i++) {
      temp[count++] = ret[i];
    }
  } else {
    const uintptr_t base = 16;
    const char *hex = "0123456789abcdef";

    temp[count++] = '0';
    temp[count++] = 'x';
    const int size = sizeof(void *) * 2;
    int fl = 0;
    for (int i = size - 1; i >= 0; --i) {
      const uintptr_t mask = (base - 1) << (i * 4);
      const int shift = i * 4;
      char inp = hex[(ptr & mask) >> shift];
      if (inp == '0' && fl == 0)
        continue;
      else if (fl == 0)
        fl = 1;
      temp[count++] = inp;
    }
  }
  while (width_val != -1 && width_val > (int)strlen(temp)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  strcpy(str, temp);
  return count;
}

int percent_sprintf(char *str) {
  *str = '%';
  return 1;
}

int c_sprintf(char *str, va_list args, int width_val) {
  char value = va_arg(args, int);
  int count = 0;
  while (width_val != -1 && width_val > 1) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  *str++ = value;
  count++;
  return count;
}

int s21_sprintf(char *str, char *format, ...) {
  va_list args;
  va_start(args, format);
  int length_arr[3] = {0};  // [h,l,L]
  int width_val = -1;
  int count = 0;
  char *start = str;

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      while (*format >= 48 && *format <= 57) {
        if (width_val == -1)
          width_val = *format - 48;
        else
          width_val = width_val * 10 + *format - 48;
        format++;
      }
      if (*format == 'h') {
        length_arr[0] = 1;
        format++;
      }
      if (*format == 'l') {
        length_arr[1] = 1;
        format++;
      }
      if (*format == 'L') {
        length_arr[2] = 1;
        format++;
      }
      switch (*format) {
        case 'd': {
          int temp_count = d_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'f': {
          int temp_count = f_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 's': {
          int temp_count = s_sprintf(str, args, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'i': {
          int temp_count = d_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'E': {
          int temp_count = e_sprintf(str, args, length_arr, width_val);
          for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'f') {
              str[i] = toupper(str[i]);
            }
          }
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'e': {
          int temp_count = e_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'G': {
          int temp_count = g_sprintf(str, args, length_arr, width_val);
          for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'f') {
              str[i] = toupper(str[i]);
            }
          }
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'g': {
          int temp_count = g_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'n': {
          int *nvalue = va_arg(args, int *);
          *nvalue = count;
          count = 0;
          format++;
          break;
        }
        case 'o': {
          int temp_count = o_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'u': {
          int temp_count = u_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'X': {
          int temp_count = x_sprintf(str, args, length_arr, width_val);

          for (int i = 0; str[i] != '\0'; i++) {
            if (str[i] >= 'a' && str[i] <= 'f') {
              str[i] = toupper(str[i]);
            }
          }
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'x': {
          int temp_count = x_sprintf(str, args, length_arr, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case '%': {
          int temp_count = percent_sprintf(str);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'c': {
          int temp_count = c_sprintf(str, args, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'p': {
          int temp_count = p_sprintf(str, args, width_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        default:
          break;
      }
    } else {
      *str = *format;
      count++;
      str++;
      format++;
    }
    length_arr[0] = 0, length_arr[1] = 0, length_arr[2] = 0;
    width_val = -1;
  }

  *str = '\0';
  va_end(args);
  return str - start;
}

// int main() {
//   // char buffer1[100];
//   // char buffer2[100];

//   // double num = -123.521123321;

//   char buffer1[100];
//   sprintf(
//       buffer1, "Integer: %5d, Octal: %5o, Hex: %7x, Float: %f, String: %10s",
//       42, 42, 42, 3.14, "Hello");

//   char buffer2[100];
//   s21_sprintf(
//       buffer2, "Integer: %5d, Octal: %5o, Hex: %7x, Float: %f, String: %10s",
//       42, 42, 42, 3.14, "Hello");
//   // int abd = 0;

//   // s21_sprintf(buffer1,"%12c%d%c%c",'s',123,'s','g');
//   // s21_sprintf(buffer2,"%12f",num);

//   printf("%s\n", buffer1);
//   printf("%s\n", buffer2);

//   // char buffer1[100], buffer2[100000], buffer3[100], buffer4[100],
//   // buffer5[100], buffer6[100],
//   //     buffer7[100], buffer8[100], buffer9[100], buffer10[100], buffer11[100],
//   //     buffer12[100], buffer13[100], buffer14[100], buffer15[100],
//   //     buffer16[100];

//   // int printed_chars_n = 0;
//   // int printed_chars_p = 123;
//   // int *ukaz = &printed_chars_p;
//   // void *ptr = NULL;
//   // double (*func_ptr)(double, double) = pow;
//   // long double x = -123.456;
//   // // int x = 5;

//   // sprintf(buffer1, "%p\n",ptr);
//   // printf("%s", buffer1);

//   // s21_sprintf(buffer2, "%p\n",ptr);
//   // printf("%s", buffer2);

//   // // sprintf(buffer1, "%Le\n",x);
//   // // printf("%s", buffer1);

//   // // s21_sprintf(buffer2, "%Le\n",x);
//   // // printf("%s", buffer2);

//   // return 0;
// }
