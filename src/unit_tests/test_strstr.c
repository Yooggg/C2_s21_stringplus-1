#include "test_string.h"

// Тест-кейс 1: Поиск подстроки в строке
START_TEST(strstr_1) {
  char haystack[] = "abcdef";
  char needle[] = "cd";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 2: Поиск подстроки в строке (пустая строка)
START_TEST(strstr_2) {
  char haystack[] = "";
  char needle[] = "abc";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 3: Поиск подстроки в строке (пустая строка для needle)
START_TEST(strstr_3) {
  char haystack[] = "abcdef";
  char needle[] = "";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 4: Поиск подстроки в строке (пустые строки)
START_TEST(strstr_4) {
  char haystack[] = "";
  char needle[] = "";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 5: Поиск подстроки в строке (подстрока не найдена)
START_TEST(strstr_5) {
  char haystack[] = "abcdef";
  char needle[] = "xyz";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 6: Поиск подстроки в строке (подстрока в начале)
START_TEST(strstr_6) {
  char haystack[] = "abcdef";
  char needle[] = "abc";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 7: Поиск подстроки в строке (подстрока в конце)
START_TEST(strstr_7) {
  char haystack[] = "abcdef";
  char needle[] = "def";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 8: Поиск подстроки в строке (подстрока в середине)
START_TEST(strstr_8) {
  char haystack[] = "abcdef";
  char needle[] = "bcde";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 9: Поиск подстроки в строке (символ - нуль-терминатор)
START_TEST(strstr_9) {
  char haystack[] = "abcdef";
  char needle[] = "\0";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

// Тест-кейс 10: Поиск подстроки в строке (русские символы)
START_TEST(strstr_10) {
  char haystack[] = "Привет, мир!";
  char needle[] = "мир";

  ck_assert_ptr_eq(s21_strstr(haystack, needle), strstr(haystack, needle));
}
END_TEST

Suite *strstr_suite(void) {
  Suite *s = suite_create("SUITE_STRSTR");
  TCase *tc;
  tc = tcase_create("TC_STRSTR");
  tcase_add_test(tc, strstr_1);
  tcase_add_test(tc, strstr_2);
  tcase_add_test(tc, strstr_3);
  tcase_add_test(tc, strstr_4);
  tcase_add_test(tc, strstr_5);
  tcase_add_test(tc, strstr_6);
  tcase_add_test(tc, strstr_7);
  tcase_add_test(tc, strstr_8);
  tcase_add_test(tc, strstr_9);
  tcase_add_test(tc, strstr_10);
  suite_add_tcase(s, tc);
  return s;
}
