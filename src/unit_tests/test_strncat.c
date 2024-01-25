#include "test_string.h"

START_TEST(strncat_1) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  const char src[] = "World!";
  s21_strncat(dest1, src, 20);
  strncat(dest2, src, 19);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_2) {
  char dest1[20] = "Hello, ";
  char dest2[20] = "Hello, ";
  const char src[] = "World!";
  s21_strncat(dest1, src, 3);
  strncat(dest2, src, 3);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_3) {
  char dest1[20] = "abc";
  char dest2[20] = "abc";
  const char src[] = "\0def";
  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);
  ck_assert_mem_eq(dest1, dest2, 6);
}
END_TEST

START_TEST(strncat_4) {
  char dest1[20] = "Testing";
  char dest2[20] = "Testing";
  const char src[] = "123";
  s21_strncat(dest1, src, 5);
  strncat(dest2, src, 5);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_5) {
  char dest1[20] = "";
  char dest2[20] = "";
  const char src[] = "Hello, World!";
  s21_strncat(dest1, src, 20);
  strncat(dest2, src, 19);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_6) {
  char dest1[20] = "123";
  char dest2[20] = "123";
  const char src[] = "456";
  s21_strncat(dest1, src, 2);
  strncat(dest2, src, 2);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_7) {
  char dest1[20] = "AaBbCc";
  char dest2[20] = "AaBbCc";
  const char src[] = "DdEeFf";
  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_8) {
  char dest1[20] = "Special@";
  char dest2[20] = "Special@";
  const char src[] = "Characters!";
  s21_strncat(dest1, src, 20);
  strncat(dest2, src, 19);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_9) {
  char dest1[20] = "Line";
  char dest2[20] = "Line";
  const char src[] = "\nBreak";
  s21_strncat(dest1, src, 6);
  strncat(dest2, src, 6);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

START_TEST(strncat_10) {
  char dest1[20] = "Hello\t";
  char dest2[20] = "Hello\t";
  const char src[] = "Tab!";
  s21_strncat(dest1, src, 20);
  strncat(dest2, src, 19);
  ck_assert_str_eq(dest1, dest2);
}
END_TEST

Suite *strncat_suite(void) {
  Suite *s = suite_create("SUITE_STRNCAT");
  TCase *tc;
  tc = tcase_create("TC_STRNCAT");
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);
  suite_add_tcase(s, tc);
  return s;
}
