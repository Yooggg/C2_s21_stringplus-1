#include <check.h>
#include <math.h>
#include <string.h>

#include "s21_string.h"

void *s21_memcpy(void *dest, const void *src, size_t n) {
  if (dest != NULL && src != NULL && s21_strcmp(src, "") != 0) {
    for (size_t i = 0; i < n; i++) {
      *((char *)dest + i) = *((const char *)src + i);
      if (i == n - 1) *((char *)dest + n) = '\0';
    }
  }
  return dest;
}
