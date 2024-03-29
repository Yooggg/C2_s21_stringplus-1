#include "test_string.h"

START_TEST(test_to_lower_1) {
  const char str[] = "Hello, World!";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello, world!");
  free(result);
}
END_TEST

START_TEST(test_to_lower_2) {
  const char str[] = " ";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, " ");
  free(result);
}
END_TEST

START_TEST(test_to_lower_3) {
  const char str[] = "A";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "a");
  free(result);
}
END_TEST

START_TEST(test_to_lower_4) {
  const char str[] = "Hello\tWorld!";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "hello    world!");
  free(result);
}
END_TEST

START_TEST(test_to_lower_5) {
  const char str[] = "123!@#";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "123!@#");
  free(result);
}
END_TEST

START_TEST(test_to_lower_6) {
  const char str[] = "MiXeDCaSe";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "mixedcase");
  free(result);
}
END_TEST

START_TEST(test_to_lower_7) {
  const char str[] = "  Spaced  Out  ";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "  spaced  out  ");
  free(result);
}
END_TEST

START_TEST(test_to_lower_8) {
  const char *str = NULL;
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, NULL);
  free(result);
}
END_TEST

START_TEST(test_to_lower_9) {
  const char str[] = "    Long     Spaces    ";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "    long     spaces    ");
  free(result);
}
END_TEST

START_TEST(test_to_lower_10) {
  const char str[] = "Line1\nLine2";
  void *result = s21_to_lower(str);
  ck_assert_str_eq(result, "line1\nline2");
  free(result);
}
END_TEST

Suite *to_lower_suite(void) {
  Suite *s;
  TCase *tc_to_lower;

  s = suite_create("to_lower_suite");
  tc_to_lower = tcase_create("to_lower_tests");

  tcase_add_test(tc_to_lower, test_to_lower_1);
  tcase_add_test(tc_to_lower, test_to_lower_2);
  tcase_add_test(tc_to_lower, test_to_lower_3);
  tcase_add_test(tc_to_lower, test_to_lower_4);
  tcase_add_test(tc_to_lower, test_to_lower_5);
  tcase_add_test(tc_to_lower, test_to_lower_6);
  tcase_add_test(tc_to_lower, test_to_lower_7);
  tcase_add_test(tc_to_lower, test_to_lower_8);
  tcase_add_test(tc_to_lower, test_to_lower_9);
  tcase_add_test(tc_to_lower, test_to_lower_10);

  suite_add_tcase(s, tc_to_lower);

  return s;
}