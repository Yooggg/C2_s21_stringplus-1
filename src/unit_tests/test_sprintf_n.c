#include <check.h>
#include <stdio.h>
#include <string.h>

#include "test_string.h"

// Тест-кейс 1: Проверка количества записанных символов
START_TEST(s21_sprintf_n_1) {
    char buffer[50];
    int value = 42;
    int standard_result;
    int standard_chars_written = sprintf(buffer, "The answer is %d", value);
    standard_result = value + standard_chars_written;

    char s21_buffer[50];
    int s21_chars_written;
    int s21_result = value;
    s21_chars_written = s21_sprintf(s21_buffer, "The answer is %d%n", value, &s21_result);

    ck_assert_int_eq(s21_chars_written, standard_chars_written);
    ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

// Тест-кейс 2: Проверка количества записанных символов (пустой формат)
START_TEST(s21_sprintf_n_2) {
    char buffer[50];
    int standard_result;
    int standard_chars_written = sprintf(buffer, "%n", &standard_result);
    standard_result = standard_chars_written;

    char s21_buffer[50];
    int s21_chars_written;
    int s21_result = 0;  // Не должно влиять на результат
    s21_chars_written = s21_sprintf(s21_buffer, "%n", &s21_result);

    ck_assert_int_eq(s21_chars_written, standard_chars_written);
    ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

// Тест-кейс 3: Проверка количества записанных символов (пустой формат в середине строки)
START_TEST(s21_sprintf_n_3) {
    char buffer[50];
    int standard_result;
    int standard_chars_written = sprintf(buffer, "Value: %n", &standard_result);
    standard_result = standard_chars_written - strlen("Value: ");

    char s21_buffer[50];
    int s21_chars_written;
    int s21_result = 0;  // Не должно влиять на результат
    s21_chars_written = s21_sprintf(s21_buffer, "Value: %n", &s21_result);

    ck_assert_int_eq(s21_chars_written, standard_chars_written);
    ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

// Тест-кейс 4: Проверка сразу нескольких %n
START_TEST(s21_sprintf_n_4) {
    char buffer[50];
    int value1 = 123;
    int value2 = 456;
    int value3 = 789;
    int standard_result;
    int standard_chars_written = sprintf(buffer, "Values: %d%n, %d%n, %d%n", value1, &standard_result, value2, &standard_result, value3, &standard_result);
    standard_result = standard_chars_written;

    char s21_buffer[50];
    int s21_chars_written;
    int s21_result1 = 0;
    int s21_result2 = 0;
    int s21_result3 = 0;
    s21_chars_written = s21_sprintf(s21_buffer, "Values: %d%n, %d%n, %d%n", value1, &s21_result1, value2, &s21_result2, value3, &s21_result3);

    ck_assert_int_eq(s21_chars_written, standard_chars_written);
    ck_assert_int_eq(s21_result1, value1);
    ck_assert_int_eq(s21_result2, value2);
    ck_assert_int_eq(s21_result3, value3);
}
END_TEST

// Тест-кейс 5: Проверка совпадения с %d, не использующим %n
START_TEST(s21_sprintf_n_5) {
    char buffer[50];
    int value = 987;
    int standard_result;
    int standard_chars_written = sprintf(buffer, "Value: %d", value);
    standard_result = standard_chars_written;

    char s21_buffer[50];
    int s21_chars_written;
    int s21_result = 0;  // Не должно влиять на результат
    s21_chars_written = s21_sprintf(s21_buffer, "Value: %d%n", value, &s21_result);

    ck_assert_int_eq(s21_chars_written, standard_chars_written);
    ck_assert_int_eq(s21_result, standard_result);
}
END_TEST

Suite *sprintf_n_suite(void) {
    Suite *s = suite_create("SUITE_sprintf_n");
    TCase *tc;
    tc = tcase_create("TC_sprintf_n");
    tcase_add_test(tc, s21_sprintf_n_1);
    tcase_add_test(tc, s21_sprintf_n_2);
    tcase_add_test(tc, s21_sprintf_n_3);
    tcase_add_test(tc, s21_sprintf_n_4);
    tcase_add_test(tc, s21_sprintf_n_5);
    suite_add_tcase(s, tc);
    return s;
}
