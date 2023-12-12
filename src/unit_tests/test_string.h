#ifndef test_string_h
#define test_string_h
#include "../s21_string.h"
#include <string.h>
#include <check.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>

Suite *memchr_suite(void);
Suite *memcmp_suite(void);
Suite *strchr_suite(void);
Suite *strncmp_suite(void);
Suite *strcspn_suite(void);
Suite *strpbrk_suite(void);
Suite *strrchr_suite(void);
Suite *strstr_suite(void);
Suite *insert_suite(void);

Suite *strlen_suite(void);
Suite *strncat_suite(void);
Suite *strncpy_suite(void);
Suite *to_lower_suite(void);
Suite *to_upper_suite(void);

#endif 