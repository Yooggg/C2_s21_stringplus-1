#include "s21_string.h"

size_t s21_strcspn(const char *str1, const char *str2) {
  size_t size = 0;
  while ((*str1 != '\0') && (!s21_strchr(str2, (int)*str1))) {
    size += 1;
    str1++;
  }
  return size;
}
