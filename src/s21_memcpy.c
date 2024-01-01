#include <check.h>
#include <math.h>
#include <string.h>

#include "s21_string.h"
// Прототип вашей функции
int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }
  return (*str1 - *str2);
}

void *s21_memcpy(void *dest, const void *src, size_t n) {
  if (dest != NULL && src != NULL && s21_strcmp(src, "") != 0) {
    for (size_t i = 0; i < n; i++) {
      *((char *)dest + i) = *((const char *)src + i);
      if (i == n - 1) *((char *)dest + n) = '\0';
    }
  }
  return dest;
}
