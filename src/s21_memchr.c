#include "s21_string.h"

void *s21_memchr(const void *str, int c, size_t n) {
  void *res = s21_NULL;
  if (n > s21_strlen(str)) {
    n = s21_strlen(str) + 1;
  }
  for (size_t i = 0; i < n; i++) {
    char to_char = *((char *)(str) + i);
    if (c == to_char) {
      res = (char *)(str) + i;
      i = n;
    }
  }
  return res;
}
