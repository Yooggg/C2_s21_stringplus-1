#include "test_string.h"

START_TEST(strpbrk_1) {
  char str[] = "abcdef";
  char accept[] = "xyz";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_2) {
  char str[] = "abcdef";
  char accept[] = "";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_3) {
  char str[] = "";
  char accept[] = "xyz";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_4) {
  char str[] = "";
  char accept[] = "";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_5) {
  char str[] = "Hello123!";
  char accept[] = "0123456789";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_6) {
  char str[] = "Привет, мир!";
  char accept[] = "ртмиве";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_7) {
  char str[] = "@#$%Hello!";
  char accept[] = "!@#$%";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_8) {
  char str[] = "abcdef";
  char accept[] = "abcxyz";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_9) {
  char str[] = "abcdef";
  char accept[] = "xyzabc";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

START_TEST(strpbrk_10) {
  char str[] = "abcdef";
  char accept[] = "xyzcde";

  ck_assert_ptr_eq(s21_strpbrk(str, accept), strpbrk(str, accept));
}
END_TEST

Suite *strpbrk_suite(void) {
  Suite *s = suite_create("SUITE_STRPBRK");
  TCase *tc;
  tc = tcase_create("TC_STRPBRK");
  tcase_add_test(tc, strpbrk_1);
  tcase_add_test(tc, strpbrk_2);
  tcase_add_test(tc, strpbrk_3);
  tcase_add_test(tc, strpbrk_4);
  tcase_add_test(tc, strpbrk_5);
  tcase_add_test(tc, strpbrk_6);
  tcase_add_test(tc, strpbrk_7);
  tcase_add_test(tc, strpbrk_8);
  tcase_add_test(tc, strpbrk_9);
  tcase_add_test(tc, strpbrk_10);
  suite_add_tcase(s, tc);
  return s;
}