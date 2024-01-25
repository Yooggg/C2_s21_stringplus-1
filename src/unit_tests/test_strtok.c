#include "test_string.h"

START_TEST(strtok_1) {
  char b1[25] = "test1/test2/test3/test4";
  char b2[25] = "test1/test2/test3/test4";

  ck_assert_str_eq(strtok(b1, "/"), s21_strtok(b2, "/"));
}
END_TEST

START_TEST(strtok_2) {
  ck_assert_str_eq(strtok(s21_NULL, "/"), s21_strtok(s21_NULL, "/"));
}
END_TEST

START_TEST(strtok_3) {
  char b1[25] = "test1/test2/test3/test4";
  char b2[25] = "test1/test2/test3/test4";
  ck_assert_str_eq(strtok(b1, "!"), s21_strtok(b2, "!"));
}
END_TEST

START_TEST(strtok_4) {
  char b3[24] = {'\0'};
  char b4[24] = {'\0'};
  ck_assert_ptr_eq(strtok(b3, "!"), s21_strtok(b4, "!"));
}
END_TEST

START_TEST(strtok_5) {
  char b3[24] = {"abvDSfwe"};
  ck_assert_ptr_eq(strtok(b3, "D"), s21_strtok(b3, "D"));
}
END_TEST

Suite *strtok_suite(void) {
  Suite *s = suite_create("SUITE_STRTOK");
  TCase *tc;
  tc = tcase_create("TC_STRTOK");
  tcase_add_test(tc, strtok_1);
  tcase_add_test(tc, strtok_2);
  tcase_add_test(tc, strtok_3);
  tcase_add_test(tc, strtok_4);
  tcase_add_test(tc, strtok_5);
  suite_add_tcase(s, tc);
  return s;
}
