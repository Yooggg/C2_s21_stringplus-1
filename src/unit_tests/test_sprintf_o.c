#include "test_string.h"

START_TEST(s21_sprintf_o_1) {
  char result[50];
  unsigned int value = 42;
  int standard_result = sprintf(result, "%o", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%o", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_o_2) {
  char result[50];
  int value = -123;
  int standard_result = sprintf(result, "%o", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%o", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_o_3) {
  char result[50];
  int value = 0;
  int standard_result = sprintf(result, "%o", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%o", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_o_4) {
  char result[50];
  unsigned int value = 4294967295U;
  int standard_result = sprintf(result, "%o", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%o", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

START_TEST(s21_sprintf_o_5) {
  char result[50];
  int value = -2147483647 - 1;
  int standard_result = sprintf(result, "%o", value);

  char s21_result[50];
  int s21_result_length = s21_sprintf(s21_result, "%o", value);

  ck_assert_int_eq(s21_result_length, standard_result);
  ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_o_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_o");
  TCase *tc;
  tc = tcase_create("TC_sprintf_o");
  tcase_add_test(tc, s21_sprintf_o_1);
  tcase_add_test(tc, s21_sprintf_o_2);
  tcase_add_test(tc, s21_sprintf_o_3);
  tcase_add_test(tc, s21_sprintf_o_4);
  tcase_add_test(tc, s21_sprintf_o_5);
  suite_add_tcase(s, tc);
  return s;
}
