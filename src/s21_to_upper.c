#include "s21_string.h"

void *s21_to_upper(const char *str) {
  char *up = s21_NULL;

  if (str != s21_NULL) {
    char *empty_str = calloc(1, sizeof(char));

    if (str[0] == '\0') {
      if (empty_str != s21_NULL) {
        empty_str[0] = '\0';
      }
      return (void *)empty_str;
    }
    free(empty_str);
    up = calloc(4 * s21_strlen(str) + 1, sizeof(char));
    if (up != s21_NULL) {
      for (size_t i = 0, j = 0; i < s21_strlen(str); i++) {
        if (str[i] == '\0') continue;
        if ('a' <= str[i] && str[i] <= 'z') {
          up[j] = str[i] - 32;
        } else if (str[i] == '\t') {
          // Заменяем табуляцию на 4 пробела
          up[j++] = ' ';
          up[j++] = ' ';
          up[j++] = ' ';
          up[j] = ' ';
        } else {
          up[j] = str[i];
        }
        j++;
      }
      up[4 * s21_strlen(str)] = '\0';
    }
  }
  return up;
}
