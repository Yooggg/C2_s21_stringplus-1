#include "test_string.h"

START_TEST(strstr_1) {
  char haystack[] = "abcdef";
  char needle[] = "cd";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_2) {
  char haystack[] = "";
  char needle[] = "abc";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_3) {
  char haystack[] = "abcdef";
  char needle[] = "";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_4) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_5) {
  char haystack[] = "abcdef";
  char needle[] = "xyz";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_6) {
  char haystack[] = "abcdef";
  char needle[] = "abc";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_7) {
  char haystack[] = "abcdef";
  char needle[] = "def";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_8) {
  char haystack[] = "abcdef";
  char needle[] = "bcde";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_9) {
  char haystack[] = "abcdef";
  char needle[] = "\0";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

START_TEST(strstr_10) {
  char haystack[] = "Привет, мир!";
  char needle[] = "мир";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("SUITE_STRSTR");
  TCase *tc;
  tc = tcase_create("TC_STRSTR");
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  suite_add_tcase(s, tc);
  return s;
}
