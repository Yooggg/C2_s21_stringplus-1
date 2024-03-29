#include "s21_string.h"

int s21_memcmp(const void* str1, const void* str2, size_t n) {
  const unsigned char* s1 = (const unsigned char*)str1;
  const unsigned char* s2 = (const unsigned char*)str2;
  int dif = 0;

  while (n-- > 0) {
    if (*s1 != *s2) {
      dif = (int)s1[0] - (int)s2[0];
      break;
    }
    s1++;
    s2++;
  }
  return dif;
}
