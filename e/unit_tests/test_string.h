#ifndef test_string_h
#define test_string_h
#include "../s21_string.h"
#include <string.h>
#include <check.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <limits.h>

Suite *strlen_suite(void);
Suite *to_upper_suite(void);
Suite *to_lower_suite(void);

#endif 