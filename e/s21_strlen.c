
#include "s21_string.h"

size_t s21_strlen(const char *str) {
  size_t count = 0;
  while (*str != '\0') {
    count++;
    str++;
  }
  return count;
}
