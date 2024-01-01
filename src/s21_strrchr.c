#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *temp = NULL;
  while (*str != '\0') {
    if (*str == c) {
      temp = (char *)str;
    }
    str++;
  }
  if (c == '\0') {
    temp = (char *)str;
  }
  return temp;
}
