#include "test_string.h"

START_TEST(memcmp_1) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello, World!";
  size_t n = strlen(str1) + 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_2) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello!";
  size_t n = strlen(str1) + 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_3) {
  char str1[] = "Hello, World!";
  char str2[] = "Hello!";
  size_t n = 6;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_4) {
  char str1[] = "";
  char str2[] = "";
  size_t n = 1;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_5) {
  char str1[] = "CommonPrefix123";
  char str2[] = "CommonPrefix456";
  size_t n = 13;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_6) {
  char str1[] = "LongerString123";
  char str2[] = "Short123";
  size_t n = 9;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_7) {
  char str1[] = "Short123";
  char str2[] = "LongerString123";
  size_t n = 9;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_8) {
  char str1[] = "Apple";
  char str2[] = "Banana";
  size_t n = 6;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_9) {
  char str1[] = "Programming";
  char str2[] = "Programmers";
  size_t n = 11;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

START_TEST(memcmp_10) {
  char str1[] = "End123";
  char str2[] = "End456";
  size_t n = 7;

  ck_assert_int_eq(s21_memcmp(str1, str2, n), memcmp(str1, str2, n));
}
END_TEST

Suite *memcmp_suite(void) {
  Suite *s = suite_create("SUITE_MEMCMP");
  TCase *tc;
  tc = tcase_create("TC_MEMCMP");
  tcase_add_test(tc, memcmp_1);
  tcase_add_test(tc, memcmp_2);
  tcase_add_test(tc, memcmp_3);
  tcase_add_test(tc, memcmp_4);
  tcase_add_test(tc, memcmp_5);
  tcase_add_test(tc, memcmp_6);
  tcase_add_test(tc, memcmp_7);
  tcase_add_test(tc, memcmp_8);
  tcase_add_test(tc, memcmp_9);
  tcase_add_test(tc, memcmp_10);
  suite_add_tcase(s, tc);
  return s;
}
