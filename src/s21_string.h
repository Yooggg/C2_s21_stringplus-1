#ifndef S21_STRING_H
#define S21_STRING_H

#include <stdio.h>
#include <stdlib.h>

void *s21_memchr (const void *str, int c, size_t n);


int s21_memcmp(const void *str1, const void *str2, size_t n);

char *s21_strchr(const char *str, int c);


size_t s21_strcspn(const char *str1, const char *str2);

int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);
void *s21_insert(const char *src, const char *str, size_t start_index);

int c_sprintf(char *str, va_list args);
int percent_sprintf(char *str, va_list args);
int p_sprintf(char *str, va_list args);
int x_sprintf(char *str, va_list args, int length_arr[3]);
int u_sprintf(char *str, va_list args, int length_arr[3]);
int o_sprintf(char *str, va_list args, int length_arr[3]);
int g_sprintf(char *str, va_list args);
int e_sprintf(char *str, va_list args, int length_arr[3]);
int s_sprintf(char *str, va_list args);
int f_sprintf(char *str, va_list args, int length_arr[3]);
int d_sprintf(char *str, va_list args, int length_arr[3]);
int custom_gtoa(char *str, double num, int precision);
int custom_etoa(char *str, long double num, int precision);
int custom_ftoa(char *str, long double num, int precision);
int custom_utohex(char *str, unsigned long int value);
int custom_utoa(char *str, long int value);
int custom_itoa(char *str, long int value);
int s21_sprintf(char *str, char *format, ...);


size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);

int s21_sprintf(char *str, char *format, ...);


#endif
