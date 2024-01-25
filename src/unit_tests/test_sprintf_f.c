#include "test_string.h"

START_TEST(s21_sprintf_f_1) {
  char result[50];
  double value = 42.567;
  int standard_result = sprintf(result, "%f", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%f", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_f_2) {
  char result[50];
  double value = -123.456;
  int standard_result = sprintf(result, "%f", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%f", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_f_3) {
  char result[50];
  double value = 0.0;
  int standard_result = sprintf(result, "%f", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%f", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_f_4) {
  char result[50];
  double value = DBL_MIN;
  int standard_result = sprintf(result, "%f", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%f", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_f_5) {
  char result[50];
  double value = INT32_MAX;
  int standard_result = sprintf(result, "%f", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%f", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_f_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_f");
  TCase *tc;
  tc = tcase_create("TC_sprintf_f");
  tcase_add_test(tc, s21_sprintf_f_1);
  tcase_add_test(tc, s21_sprintf_f_2);
  tcase_add_test(tc, s21_sprintf_f_3);
  tcase_add_test(tc, s21_sprintf_f_4);
  tcase_add_test(tc, s21_sprintf_f_5);
  suite_add_tcase(s, tc);
  return s;
}
