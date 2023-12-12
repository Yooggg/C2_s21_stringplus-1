#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>

void *s21_memchr (const void *str, int c, size_t n);



size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);
void s21_to_upper(const char *str);
void s21_to_lower(const char *str);
int s21_memcmp(const void *str1, const void *str2, size_t n);

char *s21_strchr(const char *str, int c);
size_t s21_strcspn(const char *str1, const char *str2);

int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strpbrk(const char *str1, const char *str2);



#endif