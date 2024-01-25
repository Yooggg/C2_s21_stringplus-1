#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t i;
  s21_size_t j;

  i = 0;
  j = s21_strlen(dest);
  while (i < n && src[i]) {
    dest[j + i] = src[i];
    i++;
  }
  dest[j + i] = '\0';
  return (dest);
}
