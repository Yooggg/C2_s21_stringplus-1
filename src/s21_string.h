#ifndef S21_STRING_H
#define S21_STRING_H
#define BUFFSIZE 1024

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#define s21_NULL (void *)0

void *s21_memchr(const void *str, int c, size_t n);

int s21_memcmp(const void *str1, const void *str2, size_t n);

char *s21_strchr(const char *str, int c);

size_t s21_strcspn(const char *str1, const char *str2);

int s21_strncmp(const char *str1, const char *str2, size_t n);
char *s21_strpbrk(const char *str1, const char *str2);

char *s21_strrchr(const char *str, int c);

char *s21_strstr(const char *haystack, const char *needle);
void *s21_insert(const char *src, const char *str, size_t start_index);

char* sprintf_strcpy(char* destination, const char* source);
long double ld_round(long double num, int precision);
int find_g_precision(long double num, int precision, int is_e);
long double ld_pow(long double num, int precision);
int custom_itoa(char *str, long int value, int prec_val);
int custom_utoa(char *str, long int value, int prec_val);
int custom_utohex(char *str, unsigned long int value);
int custom_ftoa(char *str, long double num, int precision, int is_g);
int custom_etoa(char *str, long double num, int precision, int is_g);
int d_sprintf(char *str, va_list args, int width_val, int prec_val);
int f_sprintf(char *str, va_list args, int width_val, int prec_val);
int g_sprintf(char *str, va_list args, int width_val, int prec_val);
int s_sprintf(char *str, va_list args, int width_val, int prec_val);
int e_sprintf(char *str, va_list args, int width_val, int prec_val);
int o_sprintf(char *str, va_list args, int width_val, int prec_val);
int u_sprintf(char *str, va_list args, int width_val, int prec_val);
int x_sprintf(char *str, va_list args, int width_val, int prec_val);
int p_sprintf(char *str, va_list args, int width_val, int prec_val);
int percent_sprintf(char *str);
int c_sprintf(char *str, va_list args, int width_val);
int s21_sprintf(char *str, char *format, ...);

size_t s21_strlen(const char *str);
char *s21_strncpy(char *dest, const char *src, size_t n);
char *s21_strncat(char *dest, const char *src, size_t n);

int s21_sprintf(char *str, char *format, ...);

void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_memcpy(void *dest, const void *src, size_t n);
//Функции для sscanf
typedef struct {
  int spec;             // support Specifiers below
  int width;            // ширина
  int length;           // разные типы support [h] | [l] | [L]
  int sign;             // плюс или минус ширина
  char buff[BUFFSIZE];  // массив для мусора
  int i;                // индекс мусорного массива
  char zvezda;          // это игнор
} SSCANF;
int s21_sscanf(const char *str, const char *format, ...);

void *P_SPEC(va_list *args, int *count, const char *str, int *a);
unsigned int *X_SPEC(va_list *args, int *count, const char *str);
int *O_SPEC(va_list *args, int *count, const char *str);
unsigned long int *U_WITH_L(SSCANF Param, va_list *args, int *count,
                            const char *str);
unsigned short int *U_WITH_H(SSCANF Param, va_list *args, int *count,
                             const char *str);

unsigned int *JUST_U(SSCANF Param, va_list *args, int *count, const char *str);
long int *D_WITH_L(SSCANF Param, va_list *args, int *count, const char *str);
short int *D_WITH_H(SSCANF Param, va_list *args, int *count, const char *str);
int *JUST_D(SSCANF Param, va_list *args, int *count, const char *str);
char *CHAR_FUNC(va_list *args, int *count, const char *str);
int PARSER(const char *str, SSCANF *Param);
short int *podgon_pod_znachenie_short_int(short int *short_ptr, int width);
unsigned long int *podgon_pod_znachenie_unsigned_long_int(
    unsigned long int *ulong_ptr, int width);
unsigned short int *podgon_pod_znachenie_unsigned_short_int(
    unsigned short int *ushort_ptr, int width);
long int *podgon_pod_znachenie_long_int(long int *long_ptr, int width);
int *podgon_pod_znachenie_int(int *int_ptr, int width);
char *s21_strchr(const char *str, int c);
int s21_strcmp(const char *str1, const char *str2);
int check_na_NULL(void *ptr);
int countDigits(void *numPtr, const char *type);
void cleaning(SSCANF *params);

#endif
