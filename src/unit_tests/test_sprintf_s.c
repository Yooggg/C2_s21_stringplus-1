#include <check.h>
#include <stdio.h>
#include <string.h>

#include "test_string.h"

// Тест-кейс 1: Обычная строка
START_TEST(s21_sprintf_s_1) {
    char result[50];
    const char *value = "Hello, World!";
    int standard_result = sprintf(result, "%s", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%s", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 2: Пустая строка
START_TEST(s21_sprintf_s_2) {
    char result[50];
    const char *value = "";
    int standard_result = sprintf(result, "%s", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%s", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 3: Строка с пробелами
START_TEST(s21_sprintf_s_3) {
    char result[50];
    const char *value = "   Spaces   ";
    int standard_result = sprintf(result, "%s", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%s", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 4: Строка с числами
START_TEST(s21_sprintf_s_4) {
    char result[50];
    const char *value = "12345";
    int standard_result = sprintf(result, "%s", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%s", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 5: Строка с спецсимволами
START_TEST(s21_sprintf_s_5) {
    char result[50];
    const char *value = "!@#$%^&*()_+";
    int standard_result = sprintf(result, "%s", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%s", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_s_suite(void) {
    Suite *s = suite_create("SUITE_sprintf_s");
    TCase *tc;
    tc = tcase_create("TC_sprintf_s");
    tcase_add_test(tc, s21_sprintf_s_1);
    tcase_add_test(tc, s21_sprintf_s_2);
    tcase_add_test(tc, s21_sprintf_s_3);
    tcase_add_test(tc, s21_sprintf_s_4);
    tcase_add_test(tc, s21_sprintf_s_5);
    suite_add_tcase(s, tc);
    return s;
}
