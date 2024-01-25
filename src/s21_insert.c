#include "s21_string.h"

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t size_src = s21_strlen(src);
  s21_size_t size_str = s21_strlen(str);
  char *inserted = s21_NULL;

  if ((size_str != 0 || size_src != 0) && start_index <= size_src) {
    s21_size_t i = 0;
    inserted = calloc(size_src + size_str + 2, 1);
    if (inserted != s21_NULL) {
      for (; i < start_index; i++) {
        inserted[i] = src[i];
      }
      int j = 0;
      for (; i < start_index + size_str; i++, j++) {
        inserted[i] = str[0 + j];
      }
      for (; i < size_src + size_str; i++) {
        inserted[i] = src[i - size_str];
      }
    }
  }
  return (void *)inserted;
}