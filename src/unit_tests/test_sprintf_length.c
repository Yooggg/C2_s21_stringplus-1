#include "test_string.h"

START_TEST(s21_sprintf_length_1) {
  short value = 32767;
  char buffer[100];
  int standard_result = sprintf(buffer, "Short: %hd", value);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "Short: %hd", value);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_length_2) {
  long value = 2147483647L;
  char buffer[100];
  int standard_result = sprintf(buffer, "Long: %ld", value);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "Long: %ld", value);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_length_3) {
  unsigned long value = 4294967295UL;
  char buffer[100];
  int standard_result = sprintf(buffer, "Unsigned Long: %lu", value);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "Unsigned Long: %lu", value);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_length_4) {
  long double value = 3.141592653589793238462643383279502884L;
  char buffer[100];
  int standard_result = sprintf(buffer, "Long Double: %Lf", value);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "Long Double: %Lf", value);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_length_5) {
  void *pointer = (void *)0xabcdef;
  char buffer[100];
  int standard_result = sprintf(buffer, "Pointer: %p", pointer);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "Pointer: %p", pointer);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

Suite *sprintf_length_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_length");
  TCase *tc;
  tc = tcase_create("TC_sprintf_length");
  tcase_add_test(tc, s21_sprintf_length_1);
  tcase_add_test(tc, s21_sprintf_length_2);
  tcase_add_test(tc, s21_sprintf_length_3);
  tcase_add_test(tc, s21_sprintf_length_4);
  tcase_add_test(tc, s21_sprintf_length_5);
  suite_add_tcase(s, tc);
  return s;
}
