#include "test_string.h"

START_TEST(test_to_upper_1) {
  const char str[] = "Hello, World!";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO, WORLD!");
  free(result);
}
END_TEST

START_TEST(test_to_upper_2) {
  const char str[] = "";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_upper_3) {
  const char str[] = "a";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "A");
  free(result);
}
END_TEST

START_TEST(test_to_upper_4) {
  const char str[] = "Hello\tWorld!";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "HELLO    WORLD!");
  free(result);
}
END_TEST

START_TEST(test_to_upper_5) {
  const char str[] = "123!@#";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "123!@#");
  free(result);
}
END_TEST

START_TEST(test_to_upper_6) {
  const char str[] = "mIxEdCaSe";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "MIXEDCASE");
  free(result);
}
END_TEST

START_TEST(test_to_upper_7) {
  const char str[] = "  spaced  out  ";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "  SPACED  OUT  ");
  free(result);
}
END_TEST

START_TEST(test_to_upper_8) {
  const char *str = NULL;
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, NULL);
  free(result);
}
END_TEST

START_TEST(test_to_upper_9) {
  const char str[] = "    long     spaces    ";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "    LONG     SPACES    ");
  free(result);
}
END_TEST

START_TEST(test_to_upper_10) {
  const char str[] = "Line1\nLine2";
  void *result = s21_to_upper(str);
  ck_assert_str_eq(result, "LINE1\nLINE2");
  free(result);
}
END_TEST

Suite *to_upper_suite(void) {
  Suite *s;
  TCase *tc_to_upper;

  s = suite_create("to_upper_suite");
  tc_to_upper = tcase_create("to_upper_tests");

  tcase_add_test(tc_to_upper, test_to_upper_1);
  tcase_add_test(tc_to_upper, test_to_upper_2);
  tcase_add_test(tc_to_upper, test_to_upper_3);
  tcase_add_test(tc_to_upper, test_to_upper_4);
  tcase_add_test(tc_to_upper, test_to_upper_5);
  tcase_add_test(tc_to_upper, test_to_upper_6);
  tcase_add_test(tc_to_upper, test_to_upper_7);
  tcase_add_test(tc_to_upper, test_to_upper_8);
  tcase_add_test(tc_to_upper, test_to_upper_9);
  tcase_add_test(tc_to_upper, test_to_upper_10);

  suite_add_tcase(s, tc_to_upper);

  return s;
}