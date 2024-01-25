#include <ctype.h>
#include <math.h>
#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

#include "s21_string.h"

int flag_arr[5] = {0};    // [-, +, ' ', #, 0]
int length_arr[3] = {0};  // [h,l,L]

char *sprintf_strcpy(char *destination, const char *source) {
  char *dest = destination;
  while ((*dest++ = *source++) != '\0') {
  }
  return destination;
}

long double ld_round(long double num, int precision) {
  long double mult = pow(10.0, precision);
  long double ret = round(num * mult) / mult;
  return ret;
}

int find_g_precision(long double num, int precision, int is_e) {
  int first_prec = precision;
  num = ld_round(num, precision);
  long double temp_num = ld_round(num, precision);
  while (num == temp_num && precision != 0) {
    precision--;
    temp_num = ld_round(num, precision);
  }
  return precision + 1 * (is_e || first_prec != 0);
}

long double ld_pow(long double num, int precision) {
  for (int i = 0; i < precision; i++) {
    num /= 10;
  }
  return num;
}

int custom_itoa(char *str, long int value, int prec_val) {
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
  } else if (flag_arr[1]) {
    str[count++] = '+';
    flag_arr[1] = 0;
  } else if (flag_arr[2]) {
    str[count++] = ' ';
    flag_arr[2] = 0;
  }
  if (prec_val != -1) {
    while (prec_val > length) {
      str[count++] = '0';
      prec_val--;
    }
  }

  for (int i = length - 1; i >= 0; i--) {
    char tmp = '0' + ((value < 0 ? -value : value) / (long int)pow(10, i)) % 10;
    str[count++] = tmp;
  }

  // str[count] = '\0';
  return count;
}

int custom_utoa(char *str, long int value, int prec_val) {
  int count = 0;
  unsigned long int temp = value;
  int length = 0;

  if (temp == 0) {
    length = 1;
  } else {
    length = (long int)log10(temp) + 1;
  }

  if (prec_val != -1) {
    while (prec_val > length) {
      str[count++] = '0';
      prec_val--;
    }
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

int custom_ftoa(char *str, long double num, int precision, int is_g) {
  int count = 0;
  int fl = num < 0 ? 1 : 0;
  int flag_plus = 0;
  if (fl) {
    num = fabsl(num);
    *str++ = '-';
    // count++; //возможно ошибка
  } else if (flag_arr[1]) {
    *str++ = '+';
    flag_plus = 1;
  } else if (flag_arr[2]) {
    *str++ = ' ';
    flag_plus = 1;
  }
  flag_arr[1] = 0, flag_arr[2] = 0;

  long int intPart = (long int)num;

  count += custom_itoa(str, intPart > 0 ? intPart : -intPart, -1);
  str += count;

  long int temp_int_part = intPart;
  int int_cnt = 0;
  while (temp_int_part > 0) {
    temp_int_part /= 10;
    int_cnt++;
  }
  long double num_copy = num;
  int diff = 0;
  if (int_cnt == 0 && is_g && num != 0) {
    while (num_copy < 1) {
      num_copy *= 10;
      diff++;
    }
  }
  if (is_g)
    precision = find_g_precision(
        num, precision - int_cnt + (diff - 1) * (diff != 0), 0);
  num = ld_round(num, precision);

  if (is_g && precision == 1 && num == (long long int)num) precision = 0;
  if (precision != 0 || !is_g) {
    *str++ = '.';
    count++;
  }
  long double fractionalPart = num - intPart;
  for (int i = 0; i < precision; i++) {
    fractionalPart *= 10;
    long int digit = (long int)(fractionalPart + ld_pow(1.0, precision));
    *str++ = '0' + digit;
    count++;
    fractionalPart -= digit;
  }
  if (fl || flag_plus == 1) count++;

  return count;
}

int custom_etoa(char *str, long double num, int precision, int is_g) {
  int exp_value = 0;
  int count = 0;
  int flag_plus = 0;
  int fl = num < 0 ? 1 : 0;
  if (fl) {
    num = fabsl(num);
    *str++ = '-';
    // count++; //возможно ошибка
  } else if (flag_arr[1]) {
    *str++ = '+';
    flag_plus = 1;
  } else if (flag_arr[2]) {
    *str++ = ' ';
    flag_plus = 1;
  }
  flag_arr[1] = 0, flag_arr[2] = 0;

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

  count += custom_itoa(str, intPart, -1);
  str += count;

  if (is_g) precision = find_g_precision(num, precision, 1);
  num = ld_round(num, precision);
  long double fractionalPart = num - intPart;

  if (num != (long long int)num || !is_g) {
    *str++ = '.';
    count++;
    for (int i = 0; i < precision; i++) {
      fractionalPart *= 10;
      long int digit = (long int)(fractionalPart + ld_pow(1.0, precision));
      *str++ = '0' + digit;
      count++;
      fractionalPart -= digit;
    }
  }

  *str++ = 'e';
  count++;

  *str++ = exp_value >= 0 ? '+' : '-';
  count++;
  if (abs(exp_value) < 10) {
    *str++ = '0';
    count++;
  }
  count += custom_itoa(str, abs(exp_value), -1);
  if (fl || flag_plus == 1) count++;

  return count;
}

int d_sprintf(char *str, va_list args, int width_val, int prec_val) {
  long int value = va_arg(args, long int);
  char temp[400] = {'0'};
  int count = 0;
  if (length_arr[1]) {
    count = custom_itoa(temp, (long int)value, prec_val);
  } else if (length_arr[0]) {
    count = custom_itoa(temp, (short int)value, prec_val);
  } else {
    count = custom_itoa(temp, (int)value, prec_val);
  }

  int length = s21_strlen(temp);
  while ((width_val != -1) & (width_val > length)) {
    if (flag_arr[0])
      temp[count] = ' ';
    else
      *str++ = ' ';
    count++;
    width_val--;
  }
  sprintf_strcpy(str, temp);
  return count;
}

int f_sprintf(char *str, va_list args, int width_val, int prec_val) {
  char temp[400] = {'0'};
  int count = 0;
  if (prec_val == -1) prec_val = 6;
  if (length_arr[2]) {
    long double value = va_arg(args, long double);
    count = custom_ftoa(temp, value, prec_val, 0);
  } else {
    double value = va_arg(args, double);
    count = custom_ftoa(temp, value, prec_val, 0);
  }

  int length = s21_strlen(temp);
  while ((width_val != -1) & (width_val > length)) {
    if (flag_arr[0])
      temp[count] = ' ';
    else
      *str++ = ' ';
    count++;
    width_val--;
  }
  sprintf_strcpy(str, temp);
  return count;
}

int g_sprintf(char *str, va_list args, int width_val, int prec_val) {
  char temp[400] = {'0'};
  int count = 0;
  if (prec_val == -1) prec_val = 6;
  if (length_arr[2]) {
    long double value = va_arg(args, long double);
    if ((fabsl(value) < pow(10, -(prec_val - 2)) ||
         fabsl(value) >= pow(10, prec_val)) &&
        fabsl(value) != 0.0)
      count = custom_etoa(temp, value, prec_val - 1, 1);
    else
      count = custom_ftoa(temp, value, prec_val, 1);
  } else {
    double value = va_arg(args, double);
    if ((fabs(value) < pow(10, -(prec_val - 2)) ||
         fabs(value) >= pow(10, prec_val)) &&
        fabsl(value) != 0.0)
      count = custom_etoa(temp, value, prec_val - 1, 1);
    else
      count = custom_ftoa(temp, value, prec_val, 1);
  }

  int length = s21_strlen(temp);
  while ((width_val != -1) & (width_val > length)) {
    if (flag_arr[0])
      temp[count] = ' ';
    else
      *str++ = ' ';
    count++;
    width_val--;
  }
  sprintf_strcpy(str, temp);
  return count;
}

int s_sprintf(char *str, va_list args, int width_val, int prec_val) {
  char *svalue = va_arg(args, char *);
  int count = 0;
  int abs_length = s21_strlen(svalue);
  if (prec_val != -1) {
    if (prec_val < (int)s21_strlen(svalue)) abs_length = prec_val;
  }

  if (flag_arr[0]) {
    for (int i = 0; i < abs_length; i++) {
      *str++ = *svalue++;
      count++;
    }
  }

  while ((width_val != -1) & (width_val > abs_length)) {
    *str++ = ' ';
    count++;
    width_val--;
  }

  if (!flag_arr[0]) {
    for (int i = 0; i < abs_length; i++) {
      *str++ = *svalue++;
      count++;
    }
  }

  return count;
}

int e_sprintf(char *str, va_list args, int width_val, int prec_val) {
  char temp[400] = {'0'};
  int count = 0;
  if (prec_val == -1) prec_val = 6;
  if (length_arr[2]) {
    long double value = va_arg(args, long double);
    count = custom_etoa(temp, value, prec_val, 0);
  } else {
    double value = va_arg(args, double);
    count = custom_etoa(temp, value, prec_val, 0);
  }

  int length = s21_strlen(temp);
  while ((width_val != -1) & (width_val > length)) {
    if (flag_arr[0])
      temp[count] = ' ';
    else
      *str++ = ' ';
    count++;
    width_val--;
  }
  sprintf_strcpy(str, temp);
  return count;
}

int o_sprintf(char *str, va_list args, int width_val, int prec_val) {
  int count = 0;
  unsigned long int value = va_arg(args, unsigned long int);
  if (length_arr[1]) {
    value = (unsigned long int)value;
  } else if (length_arr[0]) {
    value = (unsigned short int)value;
  } else {
    value = (unsigned int)value;
  }

  char octalStr[400];
  int idx = 0;

  if (value == 0) {
    octalStr[idx++] = '0';
  } else {
    while (value != 0) {
      octalStr[idx++] = (value % 8) + '0';
      value /= 8;
    }
  }
  int prec_add = 0;
  if (prec_val != -1) {
    prec_add = prec_val - idx;
    if (prec_add < 0) prec_add = 0;
  }
  int prec_add_cpy = prec_add;

  if (!flag_arr[0]) {
    while ((width_val != -1) & ((width_val - prec_add) > idx)) {
      str[count++] = ' ';
      width_val--;
    }
  }

  while (prec_add > 0) {
    str[count++] = '0';
    prec_add--;
  }
  int idx_cpy = idx;
  while (idx > 0) {
    str[count++] = octalStr[--idx];
  }

  if (flag_arr[0]) {
    while ((width_val != -1) & ((width_val - prec_add_cpy) > idx_cpy)) {
      str[count++] = ' ';
      width_val--;
    }
  }

  return count;
}

int u_sprintf(char *str, va_list args, int width_val, int prec_val) {
  char temp[400] = {'0'};
  int count = 0;

  unsigned long int value = va_arg(args, unsigned long int);

  if (length_arr[1]) {
    count = custom_utoa(temp, (unsigned long int)value, prec_val);
  } else if (length_arr[0]) {
    count = custom_utoa(temp, (unsigned short int)value, prec_val);
  } else {
    count = custom_utoa(temp, (unsigned int)value, prec_val);
  }

  int length = s21_strlen(temp);
  while ((width_val != -1) & (width_val > length)) {
    if (flag_arr[0])
      temp[count] = ' ';
    else
      *str++ = ' ';
    count++;
    width_val--;
  }
  sprintf_strcpy(str, temp);
  return count;
}

int x_sprintf(char *str, va_list args, int width_val, int prec_val) {
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

  int prec_add = 0;
  if (prec_val != -1) {
    prec_add = prec_val - s21_strlen(temp);
    if (prec_add < 0) prec_add = 0;
  }

  if (!flag_arr[0]) {
    while ((width_val != -1) & (width_val - prec_add > (int)s21_strlen(temp))) {
      *str++ = ' ';
      count++;
      width_val--;
    }
  }

  int prec_add_cpy = prec_add;
  while (prec_add > 0) {
    *str++ = '0';
    count++;
    prec_add--;
  }

  sprintf_strcpy(str, temp);
  for (int i = 0; i < (int)s21_strlen(temp); i++) str++;  // было *str++

  if (flag_arr[0]) {
    while ((width_val != -1) &
           (width_val - prec_add_cpy > (int)s21_strlen(temp))) {
      *str++ = ' ';
      count++;
      width_val--;
    }
  }
  return count;
}

int p_sprintf(char *str, va_list args, int width_val, int prec_val) {
  char temp[400] = {'0'};
  int count = 0;
  int null_flag = 0;
  const uintptr_t ptr = (uintptr_t)va_arg(args, void *);
  int prec_add = 0;
  if ((void *)ptr == s21_NULL) {
    null_flag = 1;
    char *ret = "(nil)";
    for (int i = 0; i < 5; i++) {
      temp[count++] = ret[i];
    }
  } else {
    const uintptr_t base = 16;
    const char *hex = "0123456789abcdef";

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
  char temp_2[400] = {'0'};
  int cnt = 2;
  if (flag_arr[1] && (void *)ptr != s21_NULL) {
    temp_2[0] = '+';
    count++;
    cnt++;
  } else if (flag_arr[2] && (void *)ptr != s21_NULL) {
    temp_2[0] = ' ';
    count++;
    cnt++;
  }
  if (!null_flag) {
    temp_2[cnt - 2] = '0';
    temp_2[cnt - 1] = 'x';
    count += 2;
  } else
    cnt = 0;
  if (prec_val != -1) {
    prec_add = prec_val - s21_strlen(temp);
    if (prec_add < 0) prec_add = 0;
  }
  while (prec_add > 0) {
    temp_2[cnt++] = '0';
    count++;
    prec_add--;
  }
  for (int i = 0; i < (int)s21_strlen(temp); i++) {
    temp_2[i + cnt] = temp[i];
  }
  int length = s21_strlen(temp_2);
  while ((width_val != -1) & (width_val > length)) {
    if (flag_arr[0])
      temp_2[count] = ' ';
    else
      *str++ = ' ';
    count++;
    width_val--;
  }
  sprintf_strcpy(str, temp_2);
  return count;
}

int percent_sprintf(char *str) {
  *str = '%';
  return 1;
}

int c_sprintf(char *str, va_list args, int width_val) {
  char value = va_arg(args, int);
  int count = 0;
  if (flag_arr[0]) *str++ = value;
  while ((width_val != -1) & (width_val > 1)) {
    *str++ = ' ';
    count++;
    width_val--;
  }
  if (!flag_arr[0]) *str++ = value;
  count++;
  return count;
}

int s21_sprintf(char *str, char *format, ...) {
  va_list args;
  va_start(args, format);
  int width_val = -1;
  int prec_val = -1;
  int count = 0;
  char *start = str;

  while (*format != '\0') {
    if (*format == '%') {
      format++;
      while (*format == '-' || *format == '+' || *format == ' ' ||
             *format == '#' || *format == '0') {
        if (*format == '-') {
          flag_arr[0] = 1;
          format++;
          continue;
        }
        if (*format == '+') {
          flag_arr[1] = 1;
          format++;
          continue;
        }
        if (*format == ' ') {
          flag_arr[2] = 1;
          format++;
          continue;
        }
        if (*format == '#') {
          flag_arr[3] = 1;
          format++;
          continue;
        }
        if (*format == '0') {
          flag_arr[4] = 1;
          format++;
          continue;
        }
      }
      if (flag_arr[1]) flag_arr[2] = 0;
      if (*format == '*') {
        width_val = va_arg(args, int);
        format++;
      } else
        while (*format >= 48 && *format <= 57) {
          if (width_val == -1)
            width_val = *format - 48;
          else
            width_val = width_val * 10 + *format - 48;
          format++;
        }
      if (*format == '.') {
        format++;
        if (*format == '*') {
          prec_val = va_arg(args, int);
          format++;
        } else {
          while (*format >= 48 && *format <= 57) {
            if (prec_val == -1)
              prec_val = *format - 48;
            else
              prec_val = prec_val * 10 + *format - 48;
            format++;
          }
        }
      }
      if (*format == 'h') {
        length_arr[0] = 1;
        format++;
      } else if (*format == 'l') {
        length_arr[1] = 1;
        format++;
      } else if (*format == 'L') {
        length_arr[2] = 1;
        format++;
      }
      switch (*format) {
        case 'd': {
          int temp_count = d_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'f': {
          int temp_count = f_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 's': {
          int temp_count = s_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'i': {
          int temp_count = d_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'E': {
          int temp_count = e_sprintf(str, args, width_val, prec_val);
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
          int temp_count = e_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'G': {
          int temp_count = g_sprintf(str, args, width_val, prec_val);
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
          int temp_count = g_sprintf(str, args, width_val, prec_val);
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
          int temp_count = o_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'u': {
          int temp_count = u_sprintf(str, args, width_val, prec_val);
          count += temp_count;
          str += temp_count;
          format++;
          break;
        }
        case 'X': {
          int temp_count = x_sprintf(str, args, width_val, prec_val);

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
          int temp_count = x_sprintf(str, args, width_val, prec_val);
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
          int temp_count = p_sprintf(str, args, width_val, prec_val);
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
    flag_arr[0] = 0, flag_arr[1] = 0, flag_arr[2] = 0, flag_arr[3] = 0,
    flag_arr[4] = 0;
    width_val = -1;
    prec_val = -1;
  }

  *str = '\0';
  va_end(args);
  return str - start;
}
