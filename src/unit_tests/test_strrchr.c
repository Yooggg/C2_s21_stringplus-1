#include "test_string.h"

START_TEST(strrchr_1) {
  char str[] = "abcdef";
  int c = 'c';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_2) {
  char str[] = "";
  int c = 'a';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_3) {
  char str[] = "abcdef";
  int c = 'z';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_4) {
  char str[] = "";
  int c = 'a';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_5) {
  char str[] = "";
  int c = '\0';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_6) {
  char str[] = "abcabc";
  int c = 'b';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_7) {
  char str[] = "abcdef";
  int c = 'f';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_8) {
  char str[] = "abcdef";
  int c = 'a';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

START_TEST(strrchr_9) {
  char str[] = "abcdef";
  int c = '\0';

  ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

Suite *strrchr_suite(void) {
  Suite *s = suite_create("SUITE_STRRCHR");
  TCase *tc;
  tc = tcase_create("TC_STRRCHR");
  tcase_add_test(tc, strrchr_1);
  tcase_add_test(tc, strrchr_2);
  tcase_add_test(tc, strrchr_3);
  tcase_add_test(tc, strrchr_4);
  tcase_add_test(tc, strrchr_5);
  tcase_add_test(tc, strrchr_6);
  tcase_add_test(tc, strrchr_7);
  tcase_add_test(tc, strrchr_8);
  tcase_add_test(tc, strrchr_9);
  suite_add_tcase(s, tc);
  return s;
}
