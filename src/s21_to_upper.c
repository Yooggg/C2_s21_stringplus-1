#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_string.h"

void *s21_to_upper(const char *str) {
  if (str[0] == '\0') {
    char *empty_str = calloc(1, sizeof(char));
    if (empty_str != s21_NULL) {
      empty_str[0] = '\0';
    }
    return (void *)empty_str;
  }

  char *up = s21_NULL;
  up = calloc(4 * strlen(str) + 1, sizeof(char));
  if (up != s21_NULL) {
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
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
    up[4 * strlen(str)] = '\0';
  }
  return (void *)up;
}
