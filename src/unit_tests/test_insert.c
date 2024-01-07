#include "test_string.h"

// Тест-кейс 1: Вставка строки в середину другой строки
START_TEST(insert_1) {
  const char src[] = "abcdef";
  const char str[] = "123";
  size_t start_index = 3;

  char *result = s21_insert(src, str, start_index);
  char *expected = "abc123def";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 2: Вставка строки в начало другой строки
START_TEST(insert_2) {
  const char src[] = "abcdef";
  const char str[] = "123";
  size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char *expected = "123abcdef";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 3: Вставка строки в конец другой строки
START_TEST(insert_3) {
  const char src[] = "abcdef";
  const char str[] = "123";
  size_t start_index = 6;

  char *result = s21_insert(src, str, start_index);
  char *expected = "abcdef123";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 4: Вставка строки в пустую строку
START_TEST(insert_4) {
  const char src[] = "";
  const char str[] = "123";
  size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char *expected = "123";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 5: Вставка пустой строки в другую строку
START_TEST(insert_5) {
  const char src[] = "abcdef";
  const char str[] = "";
  size_t start_index = 3;

  char *result = s21_insert(src, str, start_index);
  char *expected = "abcdef";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 6: Вставка строки в начало пустой строки
START_TEST(insert_6) {
  const char src[] = "";
  const char str[] = "123";
  size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char *expected = "123";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 7: Вставка строки в конец пустой строки
START_TEST(insert_7) {
  const char src[] = "";
  const char str[] = "123";
  size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char *expected = "123";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 8: Вставка строки в середину пустой строки
START_TEST(insert_8) {
  const char src[] = "";
  const char str[] = "123";
  size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char *expected = "123";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 9: Вставка строки в конец строки с символом-нуль-терминатором
START_TEST(insert_9) {
  const char src[] = "abc\0def";
  const char str[] = "123";
  size_t start_index = 6;

  char *result = s21_insert(src, str, start_index);
  char *expected = "abc\0123def";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

// Тест-кейс 10: Вставка строки в начало строки с символом-нуль-терминатором
START_TEST(insert_10) {
  const char src[] = "abc\0def";
  const char str[] = "123";
  size_t start_index = 0;

  char *result = s21_insert(src, str, start_index);
  char *expected = "123abc\0def";

  ck_assert_str_eq(result, expected);

  // Освобождаем выделенную память
  free(result);
}
END_TEST

Suite *insert_suite(void) {
  Suite *s = suite_create("SUITE_INSERT");
  TCase *tc;
  tc = tcase_create("TC_INSERT");
  tcase_add_test(tc, insert_1);
  tcase_add_test(tc, insert_2);
  tcase_add_test(tc, insert_3);
  tcase_add_test(tc, insert_4);
  tcase_add_test(tc, insert_5);
  tcase_add_test(tc, insert_6);
  tcase_add_test(tc, insert_7);
  tcase_add_test(tc, insert_8);
  tcase_add_test(tc, insert_9);
  tcase_add_test(tc, insert_10);
  suite_add_tcase(s, tc);
  return s;
}
