#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  while (*str1 != '\0' && !res) {
    res = s21_strchr(str2, (int)*str1);
    str1++;
  }
  if (res) {
    str1--;
    return (char *)str1;
  }
  return s21_NULL;
}
