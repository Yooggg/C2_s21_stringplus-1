#include "s21_string.h"

void *s21_memset(void *str, int c, s21_size_t n) {
  int cnt = 0;
  for (s21_size_t i = 0; i < n; i++) {
    unsigned char *res = (unsigned char *)str;
    *res = (unsigned char)c;
    str++;
    cnt++;
  }
  return str - cnt;
}
