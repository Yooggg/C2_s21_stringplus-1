#include "test_string.h"


// Тест-кейс 1: Преобразование строки в верхний регистр
START_TEST(to_upper_1) {
    const char str[] = "Hello, World!";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "HELLO, WORLD!");
}
END_TEST

// Тест-кейс 2: Преобразование пустой строки
START_TEST(to_upper_2) {
    const char str[] = "";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "");
}
END_TEST

// Тест-кейс 3: Преобразование строки с символами разных регистров
START_TEST(to_upper_3) {
    const char str[] = "HeLLo, WoRLd!";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "HELLO, WORLD!");
}
END_TEST

// Тест-кейс 4: Преобразование строки с цифрами
START_TEST(to_upper_4) {
    const char str[] = "12345";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "12345");
}
END_TEST

// Тест-кейс 5: Преобразование строки с символами пунктуации
START_TEST(to_upper_5) {
    const char str[] = "!@#$%^&*()";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "!@#$%^&*()");
}
END_TEST

// Тест-кейс 6: Преобразование строки с пробелами
START_TEST(to_upper_6) {
    const char str[] = "   ";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "   ");
}
END_TEST

// Тест-кейс 7: Преобразование строки с русскими символами
START_TEST(to_upper_7) {
    const char str[] = "Привет, Мир!";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "ПРИВЕТ, МИР!");
}
END_TEST

// Тест-кейс 8: Преобразование строки с символами новой строки
START_TEST(to_upper_8) {
    const char str[] = "Hello\nWorld!";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "HELLO\nWORLD!");
}
END_TEST

// Тест-кейс 9: Преобразование строки с символами табуляции
START_TEST(to_upper_9) {
    const char str[] = "Hello\tWorld!";
    char result[20];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "HELLO\tWORLD!");
}
END_TEST

// Тест-кейс 10: Преобразование строки с разными типами символов
START_TEST(to_upper_10) {
    const char str[] = "Hello, 123, World! @#$";
    char result[30];
    strcpy(result, str);
    s21_to_upper(result);
    ck_assert_str_eq(result, "HELLO, 123, WORLD! @#$");
}
END_TEST

Suite *to_upper_suite(void) {
    Suite *s = suite_create("SUITE_TO_UPPER");
    TCase *tc;
    tc = tcase_create("TC_TO_UPPER");
    tcase_add_test(tc, to_upper_1);
    tcase_add_test(tc, to_upper_2);
    tcase_add_test(tc, to_upper_3);
    tcase_add_test(tc, to_upper_4);
    tcase_add_test(tc, to_upper_5);
    tcase_add_test(tc, to_upper_6);
    tcase_add_test(tc, to_upper_7);
    tcase_add_test(tc, to_upper_8);
    tcase_add_test(tc, to_upper_9);
    tcase_add_test(tc, to_upper_10);
    suite_add_tcase(s, tc);
    return s;
}
