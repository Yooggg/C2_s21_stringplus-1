#include "test_string.h"

// Тест-кейс 1: Начальный сегмент, полностью соответствующий accept
START_TEST(strspn_1) {
    char str[] = "abcdef";
    char accept[] = "abcdef";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 2: Начальный сегмент, частично соответствующий accept
START_TEST(strspn_2) {
    char str[] = "abcdef";
    char accept[] = "abc";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 3: Начальный сегмент, полностью не соответствующий accept
START_TEST(strspn_3) {
    char str[] = "abcdef";
    char accept[] = "xyz";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 4: Начальный сегмент, полностью соответствующий accept (пустой accept)
START_TEST(strspn_4) {
    char str[] = "abcdef";
    char accept[] = "";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 5: Начальный сегмент, полностью соответствующий accept (str и accept пустые)
START_TEST(strspn_5) {
    char str[] = "";
    char accept[] = "";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 6: Начальный сегмент, частично соответствующий accept (пустой str)
START_TEST(strspn_6) {
    char str[] = "";
    char accept[] = "abc";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 7: Начальный сегмент, полностью соответствующий accept (пробелы в accept)
START_TEST(strspn_7) {
    char str[] = "   Hello, World!";
    char accept[] = " ";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 8: Начальный сегмент, частично соответствующий accept (цифры и символы)
START_TEST(strspn_8) {
    char str[] = "123abc";
    char accept[] = "0123456789";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 9: Начальный сегмент, частично соответствующий accept (русские буквы)
START_TEST(strspn_9) {
    char str[] = "Привет, мир!";
    char accept[] = "ртмиве";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

// Тест-кейс 10: Начальный сегмент, частично соответствующий accept (специальные символы)
START_TEST(strspn_10) {
    char str[] = "@#$%Hello!";
    char accept[] = "!@#$%";

    ck_assert_int_eq(s21_strspn(str, accept), strspn(str, accept));
}
END_TEST

Suite *strspn_suite(void) {
    Suite *s = suite_create("SUITE_STRSPN");
    TCase *tc;
    tc = tcase_create("TC_STRSPN");
    tcase_add_test(tc, strspn_1);
    tcase_add_test(tc, strspn_2);
    tcase_add_test(tc, strspn_3);
    tcase_add_test(tc, strspn_4);
    tcase_add_test(tc, strspn_5);
    tcase_add_test(tc, strspn_6);
    tcase_add_test(tc, strspn_7);
    tcase_add_test(tc, strspn_8);
    tcase_add_test(tc, strspn_9);
    tcase_add_test(tc, strspn_10);
    suite_add_tcase(s, tc);
    return s;
}
