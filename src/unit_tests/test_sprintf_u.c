#include <check.h>
#include <stdio.h>
#include <string.h>

#include "test_string.h"

START_TEST(s21_sprintf_u_1) {
  char result[50];
  unsigned int value = 42;
  int standard_result = sprintf(result, "%u", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%u", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_u_2) {
  char result[50];
  unsigned int value = 0;
  int standard_result = sprintf(result, "%u", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%u", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_u_3) {
  char result[50];
  unsigned int value = UINT_MAX;
  int standard_result = sprintf(result, "%u", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%u", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_u_4) {
  char result[50];
  unsigned int value = 12345;
  int standard_result = sprintf(result, "%u", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%u", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_u_5) {
  char result[50];
  unsigned int value = 42;
  int standard_result = sprintf(result, "%u", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%u", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_u_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_u");
  TCase *tc;
  tc = tcase_create("TC_sprintf_u");
  tcase_add_test(tc, s21_sprintf_u_1);
  tcase_add_test(tc, s21_sprintf_u_2);
  tcase_add_test(tc, s21_sprintf_u_3);
  tcase_add_test(tc, s21_sprintf_u_4);
  tcase_add_test(tc, s21_sprintf_u_5);
  suite_add_tcase(s, tc);
  return s;
}
