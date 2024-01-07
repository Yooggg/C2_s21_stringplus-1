#include "test_string.h"

// Тест-кейс 1: Начальный сегмент, полностью соответствующий accept
START_TEST(strcspn_1) {
  char str[] = "abcdef";
  char accept[] = "abcdef";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 2: Начальный сегмент, частично соответствующий accept
START_TEST(strcspn_2) {
  char str[] = "abcdef";
  char accept[] = "abc";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 3: Начальный сегмент, полностью не соответствующий accept
START_TEST(strcspn_3) {
  char str[] = "abcdef";
  char accept[] = "xyz";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 4: Начальный сегмент, полностью соответствующий accept (пустой
// accept)
START_TEST(strcspn_4) {
  char str[] = "abcdef";
  char accept[] = "";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 5: Начальный сегмент, полностью соответствующий accept (str и
// accept пустые)
START_TEST(strcspn_5) {
  char str[] = "";
  char accept[] = "";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 6: Начальный сегмент, частично соответствующий accept (пустой str)
START_TEST(strcspn_6) {
  char str[] = "";
  char accept[] = "abc";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 7: Начальный сегмент, полностью соответствующий accept (пробелы в
// accept)
START_TEST(strcspn_7) {
  char str[] = "   Hello, World!";
  char accept[] = " ";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 8: Начальный сегмент, частично соответствующий accept (цифры и
// символы)
START_TEST(strcspn_8) {
  char str[] = "123abc";
  char accept[] = "0123456789";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 9: Начальный сегмент, частично соответствующий accept (русские
// буквы)
START_TEST(strcspn_9) {
  char str[] = "Привет, мир!";
  char accept[] = "ртмиве";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

// Тест-кейс 10: Начальный сегмент, частично соответствующий accept (специальные
// символы)
START_TEST(strcspn_10) {
  char str[] = "@#$%Hello!";
  char accept[] = "!@#$%";

  ck_assert_int_eq(s21_strcspn(str, accept), strcspn(str, accept));
}
END_TEST

Suite *strcspn_suite(void) {
  Suite *s = suite_create("SUITE_strcspn");
  TCase *tc;
  tc = tcase_create("TC_strcspn");
  tcase_add_test(tc, strcspn_1);
  tcase_add_test(tc, strcspn_2);
  tcase_add_test(tc, strcspn_3);
  tcase_add_test(tc, strcspn_4);
  tcase_add_test(tc, strcspn_5);
  tcase_add_test(tc, strcspn_6);
  tcase_add_test(tc, strcspn_7);
  tcase_add_test(tc, strcspn_8);
  tcase_add_test(tc, strcspn_9);
  tcase_add_test(tc, strcspn_10);
  suite_add_tcase(s, tc);
  return s;
}
