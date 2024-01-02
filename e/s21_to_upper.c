#include "s21_string.h"
#include <string.h>

// void* s21_memset(void* ptr, int value, size_t num) {
//     unsigned char *p = ptr;
//     unsigned char v = (unsigned char)value;

//     for (size_t i = 0; i < num; ++i) {
//         p[i] = v;
//     }

//     return ptr;
// }

void *s21_to_upper(const char *str) {
  char *empty_str = calloc(1, sizeof(char));
  if (str == s21_NULL || str[0] == '\0') {
    if (empty_str != s21_NULL) {
      empty_str[0] = '\0';
    }
    return (void *)empty_str;
  }

  char *up = s21_NULL;
  up = calloc(4 * s21_strlen(str) + 1, sizeof(char));
  if (up != s21_NULL) {
    for (int i = 0, j = 0; str[i] != '\0'; i++) {
      if ('a' <= str[i] && str[i] <= 'z') {
        up[j] = str[i] - 32;
      } else if (str[i] == '\t') {
        up[j++] = ' ';
        up[j++] = ' ';
        up[j++] = ' ';
        up[j] = ' ';
      } else if (str[0] == '\0') {
        memset(up, 0, 4 * s21_strlen(str) + 1);
        return (void *)up;
      } else {
        up[j] = str[i];
      }
      j++;
    }
    up[4 * s21_strlen(str)] = '\0';
  }
  return (void *)up;
}