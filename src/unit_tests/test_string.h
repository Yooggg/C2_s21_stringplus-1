#ifndef test_string_h
#define test_string_h
#include <check.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../s21_string.h"

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
Suite *memcpy_suite(void);
Suite *to_upper_suite(void);
Suite *to_lower_suite(void);

Suite *sprintf_f_suite(void);
Suite *sprintf_i_suite(void);
Suite *sprintf_e_suite(void);
Suite *sprintf_E_suite(void);
Suite *sprintf_g_suite(void);
Suite *sprintf_G_suite(void);
Suite *sprintf_o_suite(void);
Suite *sprintf_s_suite(void);
Suite *sprintf_u_suite(void);
Suite *sprintf_x_suite(void);
Suite *sprintf_X_suite(void);
Suite *sprintf_p_suite(void);
Suite *sprintf_percent_suite(void);
Suite *sprintf_n_suite(void);
Suite *sprintf_d_suite(void);
Suite *sprintf_c_suite(void);
Suite *sprintf_percent_suite();
Suite *sprintf_all_suite(void);
Suite *sprintf_width_suite(void);
Suite *sprintf_length_suite(void);

Suite *sscanf_suite_d(void);

#endif