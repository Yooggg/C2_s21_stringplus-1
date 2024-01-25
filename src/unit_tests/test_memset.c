#include "test_string.h"

START_TEST(memset_1) {
  char b1[50] = "abCdef";
  ck_assert_str_eq(memset(b1, '*', 8), s21_memset(b1, '*', 8));
}
END_TEST

START_TEST(memset_2) {
  char b1[50] = "abCdef";
  ck_assert_str_eq(memset(b1, '#', 3), s21_memset(b1, '#', 3));
}
END_TEST

START_TEST(memset_3) {
  char b1[50] = "abCdef";
  ck_assert_str_eq(memset(b1, '|', 1), s21_memset(b1, '|', 1));
}
END_TEST

START_TEST(memset_4) {
  char b1[50] = "abCdef";
  ck_assert_str_eq(memset(b1, '\t', 10), s21_memset(b1, '\t', 10));
}
END_TEST

START_TEST(memset_5) {
  char b1[50] = "abCdef";
  ck_assert_str_eq(memset(b1, '&', 3), s21_memset(b1, '&', 3));
}
END_TEST

Suite *memset_suite(void) {
  Suite *s = suite_create("SUITE_MEMSET");
  TCase *tc;
  tc = tcase_create("TC_MEMSET");
  tcase_add_test(tc, memset_1);
  tcase_add_test(tc, memset_2);
  tcase_add_test(tc, memset_3);
  tcase_add_test(tc, memset_4);
  tcase_add_test(tc, memset_5);
  suite_add_tcase(s, tc);
  return s;
}
