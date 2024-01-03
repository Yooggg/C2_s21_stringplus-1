#include <stdio.h>

#include "read_width.h"

void readNumberWithWidth(const char *str, void *data_ptr, char type,
                         int width) {
  int int_value = 0;
  float float_value = 0.0;
  int sign = 1;
  int i = 0;
  int decimal_point = -1;

  if (str[i] == '-') {
    sign = -1;
    i++;
  }

  int count = 0;
  while ((str[i] >= '0' && str[i] <= '9' && count < width) || str[i] == '.') {
    if (str[i] == '.') {
      decimal_point = i;
    } else {
      if (decimal_point != -1) {
        count++;  // Учитываем символы после десятичной точки
      }
      if (type == 'd') {
        int_value = int_value * 10 + (str[i] - '0');
      } else if (type == 'f') {
        float_value = float_value * 10 + (str[i] - '0');
      }
    }
    i++;
  }

  if (type == 'd') {
    *(int *)data_ptr = int_value * sign;
  } else if (type == 'f') {
    float divisor = 1.0;
    if (decimal_point != -1) {
      divisor = 1.0;
      int fractional_digits = i - decimal_point - 1;
      while (fractional_digits > 0) {
        divisor *= 10.0;
        fractional_digits--;
      }
    }
    *(float *)data_ptr = (float_value * sign) / divisor;
  }
}
