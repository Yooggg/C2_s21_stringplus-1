#include "test_string.h"

START_TEST(trim_1) {
  char *s1 = s21_trim("8d7h", "");
  ck_assert_str_eq(s1, "8d7h");
  free(s1);
}
END_TEST

START_TEST(trim_2) {
  char *s1 = s21_trim("8d7h", "8");
  ck_assert_str_eq(s1, "d7h");
  free(s1);
}
END_TEST

START_TEST(trim_3) {
  char *s1 = s21_trim("8d7,.Fhghghvyry.8.", "8.");
  ck_assert_str_eq(s1, "d7,.Fhghghvyry");
  free(s1);
}
END_TEST

START_TEST(trim_4) {
  char *s1 = s21_trim("007.jU;pegiyy  ", " 0.");
  ck_assert_str_eq(s1, "7.jU;pegiyy");
  free(s1);
}
END_TEST

Suite *trim_suite(void) {
  Suite *s = suite_create("SUITE_TRIM");
  TCase *tc;
  tc = tcase_create("TC_INSERT");
  tcase_add_test(tc, trim_1);
  tcase_add_test(tc, trim_2);
  tcase_add_test(tc, trim_3);
  tcase_add_test(tc, trim_4);
  suite_add_tcase(s, tc);
  return s;
}
