#include "test_string.h"

START_TEST(strcmp_1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  size_t n = 13;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_2) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello!";
  size_t n = 13;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_3) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello,!";
  size_t n = 6;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_4) {
  char str1[] = "";
  char str2[] = "";
  size_t n = 1;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_5) {
  char str1[] = "CommonPrefix123";
  char str2[] = "CommonPrefix456";
  size_t n = 13;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_6) {
  char str1[] = "LongerString123";
  char str2[] = "Short123";
  size_t n = 16;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_7) {
  char str1[] = "Short123";
  char str2[] = "LongerString123";
  size_t n = 16;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_8) {
  char str1[] = "Apple";
  char str2[] = "Banana";
  size_t n = 6;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_9) {
  char str1[] = "Programming";
  char str2[] = "Programmers";
  size_t n = 11;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

START_TEST(strcmp_10) {
  char str1[] = "End123";
  char str2[] = "End456";
  size_t n = 7;

  ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *strncmp_suite(void) {
  Suite *s = suite_create("SUITE_STRCMP");
  TCase *tc;
  tc = tcase_create("TC_STRCMP");
  tcase_add_test(tc, strcmp_1);
  tcase_add_test(tc, strcmp_2);
  tcase_add_test(tc, strcmp_3);
  tcase_add_test(tc, strcmp_4);
  tcase_add_test(tc, strcmp_5);
  tcase_add_test(tc, strcmp_6);
  tcase_add_test(tc, strcmp_7);
  tcase_add_test(tc, strcmp_8);
  tcase_add_test(tc, strcmp_9);
  tcase_add_test(tc, strcmp_10);
  suite_add_tcase(s, tc);
  return s;
}
