#include "test_string.h"

START_TEST(test_memcpy_1) {
  char dest[20];
  const char src[] = "Hello, World!";

  ck_assert_ptr_eq(s21_memcpy(dest, src, strlen(src) + 1), dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

START_TEST(test_memcpy_2) {
  char dest[10];
  const char src[] = "Hello, World!";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 5), dest);
  dest[5] = '\0';
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_memcpy_3) {
  char dest[10];
  const char src[] = "";
  s21_memcpy(dest, src, 1);
  ck_assert_ptr_eq(dest, "");
}
END_TEST

START_TEST(test_memcpy_4) {
  char dest[10];
  s21_memcpy(dest, s21_NULL, 1);
  ck_assert_ptr_eq(dest, "");
}
END_TEST

START_TEST(test_memcpy_5) {
  char src[] = "Hello, World!";

  ck_assert_ptr_eq(s21_memcpy(s21_NULL, src, strlen(src) + 1), s21_NULL);
}
END_TEST

START_TEST(test_memcpy_6) {
  ck_assert_ptr_eq(s21_memcpy(s21_NULL, s21_NULL, 0), s21_NULL);
}
END_TEST

START_TEST(test_memcpy_7) {
  char dest[10] = "Existing";
  const char src[] = "";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 1), dest);
  ck_assert_str_eq(dest, "Existing");
}
END_TEST

START_TEST(test_memcpy_8) {
  char dest[10] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 0), dest);
  ck_assert_str_eq(dest, "Existing");
}
END_TEST

START_TEST(test_memcpy_9) {
  char dest[10] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest + 3, src, 5), dest + 3);
  ck_assert_str_eq(dest, "ExiHello");
}
END_TEST

START_TEST(test_memcpy_10) {
  char dest[20] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest, src, strlen(src)), dest);
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

START_TEST(test_memcpy_11) {
  char dest[20] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest + 3, src, 5), dest + 3);
  ck_assert_str_eq(dest, "ExiHello");
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_memcpy;

  s = suite_create("memcpy_suite");

  tc_memcpy = tcase_create("memcpy_tests");

  tcase_add_test(tc_memcpy, test_memcpy_1);
  tcase_add_test(tc_memcpy, test_memcpy_2);
  tcase_add_test(tc_memcpy, test_memcpy_3);
  tcase_add_test(tc_memcpy, test_memcpy_4);
  tcase_add_test(tc_memcpy, test_memcpy_5);
  tcase_add_test(tc_memcpy, test_memcpy_6);
  tcase_add_test(tc_memcpy, test_memcpy_7);
  tcase_add_test(tc_memcpy, test_memcpy_8);
  tcase_add_test(tc_memcpy, test_memcpy_9);
  tcase_add_test(tc_memcpy, test_memcpy_10);
  tcase_add_test(tc_memcpy, test_memcpy_11);

  suite_add_tcase(s, tc_memcpy);

  return s;
}