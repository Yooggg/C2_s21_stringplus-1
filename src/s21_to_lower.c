#include "s21_string.h"
void *s21_to_lower(const char *str) {
  if (str[0] == '\0') {
    char *empty_str = calloc(1, sizeof(char));
    if (empty_str != s21_NULL) {
      empty_str[0] = '\0';
    }
    return (void *)empty_str;
  }

  char *low = s21_NULL;
  low = calloc(4 * s21_strlen(str) + 1, sizeof(char));
  if (low != s21_NULL) {
    for (int i = 0, j = 0; i < s21_strlen(str); i++) {
      if(str[i] == '\0')
        continue;
      if ('A' <= str[i] && str[i] <= 'Z') {
        low[j] = str[i] + 32;
      } else if (str[i] == '\t') {
        // Заменяем табуляцию на 4 пробела
        low[j++] = ' ';
        low[j++] = ' ';
        low[j++] = ' ';
        low[j] = ' ';
      } else {
        low[j] = str[i];
      }
      j++;
    }
    low[4 * s21_strlen(str)] = '\0';
  }
  return (void *)low;
}