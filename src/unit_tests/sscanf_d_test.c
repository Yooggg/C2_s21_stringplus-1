#include "test_string.h"

START_TEST(sscanf_test_1) {
  const char *input = "123";
  int value;
  int result = s21_sscanf(input, "%d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 123);
}
END_TEST

START_TEST(sscanf_test_2) {
  const char *input = "   -456";
  int value;
  int result = s21_sscanf(input, "%d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, -456);
}
END_TEST

START_TEST(sscanf_test_3) {
  const char *input = " 789 ";
  int value;
  int result = s21_sscanf(input, "%d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, 789);
}
END_TEST

START_TEST(sscanf_test_4) {
  const char *input = "12 34 56";
  int value1, value2, value3;
  int result = s21_sscanf(input, "%d %d %d", &value1, &value2, &value3);
  ck_assert_int_eq(result, 3);
  ck_assert_int_eq(value1, 12);
  ck_assert_int_eq(value2, 34);
  ck_assert_int_eq(value3, 56);
}
END_TEST

START_TEST(sscanf_test_5) {
  const char *input = "-789";
  int value;
  int result = s21_sscanf(input, "%3d", &value);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(value, -78);  // Ширина ограничена 3 символами
}
END_TEST

START_TEST(sscanf_test_6) {
  const char *input = "42  56";
  int value1, value2;
  int result = s21_sscanf(input, "%2d %d", &value1, &value2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(value1, 42);  // Ширина ограничена 2 символами
  ck_assert_int_eq(value2, 56);
}
END_TEST

START_TEST(sscanf_test_7) {
  const char *input = "   1000";
  short int shortValue;
  int result = s21_sscanf(input, "%5hd", &shortValue);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(shortValue, 1000);
}
END_TEST

START_TEST(sscanf_test_8) {
  const char *input = "   12345";
  long int longValue;
  int result = s21_sscanf(input, "%ld", &longValue);
  ck_assert_int_eq(result, 1);
  ck_assert_int_eq(longValue, 12345);
}
END_TEST

START_TEST(sscanf_test_9) {
  const char *input = "123 456 789";
  int value1, value2, value3;
  int result = s21_sscanf(input, "%2d %3d %d", &value1, &value2, &value3);
  ck_assert_int_eq(result, 3);
  ck_assert_int_eq(value1, 12);  // Ширина первого значения - 2
  ck_assert_int_eq(value2, 456);  // Ширина второго значения - 3
  ck_assert_int_eq(value3, 789);
}
END_TEST

START_TEST(sscanf_test_10) {
  const char *input = "42 56";
  short int shortValue1, shortValue2;
  int result = s21_sscanf(input, "%2hd %hd", &shortValue1, &shortValue2);
  ck_assert_int_eq(result, 2);
  ck_assert_int_eq(shortValue1, 42);  // Ширина первого значения - 2
  ck_assert_int_eq(shortValue2, 56);
}
END_TEST

Suite *sscanf_suite_d(void) {
  Suite *s = suite_create("SUITE_SSCANF");
  TCase *tc;
  tc = tcase_create("TC_SSCANF");
  tcase_add_test(tc, sscanf_test_1);
  tcase_add_test(tc, sscanf_test_2);
  tcase_add_test(tc, sscanf_test_3);
  tcase_add_test(tc, sscanf_test_4);
  tcase_add_test(tc, sscanf_test_5);
  tcase_add_test(tc, sscanf_test_6);
  tcase_add_test(tc, sscanf_test_7);
  tcase_add_test(tc, sscanf_test_8);
  tcase_add_test(tc, sscanf_test_9);
  tcase_add_test(tc, sscanf_test_10);
  suite_add_tcase(s, tc);
  return s;
}
