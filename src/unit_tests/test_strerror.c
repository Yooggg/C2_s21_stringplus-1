#include "test_string.h"

START_TEST(strerror_1) { ck_assert_str_eq(s21_strerror(1), strerror(1)); }
END_TEST

START_TEST(strerror_2) { ck_assert_str_eq(s21_strerror(2), strerror(2)); }
END_TEST

START_TEST(strerror_3) { ck_assert_str_eq(s21_strerror(3), strerror(3)); }
END_TEST

START_TEST(strerror_4) { ck_assert_str_eq(s21_strerror(4), strerror(3)); }
END_TEST

START_TEST(strerror_5) { ck_assert_str_eq(s21_strerror(5), strerror(5)); }
END_TEST

Suite *strerror_suite(void) {
  Suite *s = suite_create("SUITE_STRERROR");
  TCase *tc;
  tc = tcase_create("TC_STRERROR");
  tcase_add_test(tc, strerror_1);
  tcase_add_test(tc, strerror_2);
  tcase_add_test(tc, strerror_3);
  tcase_add_test(tc, strerror_4);
  tcase_add_test(tc, strerror_5);
  suite_add_tcase(s, tc);
  return s;
}
