#include "test_string.h"

START_TEST(s21_sprintf_g_1) {
  char result[50];
  double value = 42.567;
  int standard_result = sprintf(result, "%g", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%g", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_g_2) {
  char result[50];
  double value = -123.456;
  int standard_result = sprintf(result, "%g", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%g", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_g_3) {
  char result[50];
  double value = 0.0;
  int standard_result = sprintf(result, "%g", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%g", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_g_4) {
  char result[50];
  double value = 9876.54321;
  int standard_result = sprintf(result, "%g", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%g", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_g_5) {
  char result[50];
  double value = DBL_MIN;
  int standard_result = sprintf(result, "%g", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%g", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_g_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_g");
  TCase *tc;
  tc = tcase_create("TC_sprintf_g");
  tcase_add_test(tc, s21_sprintf_g_1);
  tcase_add_test(tc, s21_sprintf_g_2);
  tcase_add_test(tc, s21_sprintf_g_3);
  tcase_add_test(tc, s21_sprintf_g_4);
  tcase_add_test(tc, s21_sprintf_g_5);
  suite_add_tcase(s, tc);
  return s;
}
