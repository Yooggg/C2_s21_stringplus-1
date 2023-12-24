#include "test_string.h"
#include <math.h>

// Тест-кейс 1: Тест для спецификатора %e с положительным значением
START_TEST(s21_sprintf_e_1) {
    char result[50];
    double value = 1234.5678;
    int standard_result = sprintf(result, "%e", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%e", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 2: Тест для спецификатора %e с отрицательным значением
START_TEST(s21_sprintf_e_2) {
    char result[50];
    double value = -9876.54321;
    int standard_result = sprintf(result, "%e", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%e", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 3: Тест для спецификатора %e с нулевым значением
START_TEST(s21_sprintf_e_3) {
    char result[50];
    double value = 0.0;
    int standard_result = sprintf(result, "%e", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%e", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 4: Тест для спецификатора %e с максимальным положительным значением
START_TEST(s21_sprintf_e_4) {
    char result[50];
    double value = INT32_MAX;
    int standard_result = sprintf(result, "%e", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%e", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

// Тест-кейс 5: Тест для спецификатора %e с минимальным положительным значением
START_TEST(s21_sprintf_e_5) {
    char result[50];
    double value = DBL_MIN;
    int standard_result = sprintf(result, "%e", value);

    char s21_result[50];
    int s21_result_length = s21_sprintf(s21_result, "%e", value);

    ck_assert_int_eq(s21_result_length, standard_result);
    ck_assert_str_eq(s21_result, result);
}
END_TEST

Suite *sprintf_e_suite(void) {
    Suite *s = suite_create("SUITE_sprintf_e");
    TCase *tc;
    tc = tcase_create("TC_sprintf_e");
    tcase_add_test(tc, s21_sprintf_e_1);
    tcase_add_test(tc, s21_sprintf_e_2);
    tcase_add_test(tc, s21_sprintf_e_3);
    tcase_add_test(tc, s21_sprintf_e_4);
    tcase_add_test(tc, s21_sprintf_e_5);
    suite_add_tcase(s, tc);
    return s;
}
