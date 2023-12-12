#include "test_string.h"
#include <string.h>

// Тест-кейс 1: Преобразование строки в нижний регистр
START_TEST(to_lower_1) {
    const char str[] = "Hello, World!";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "hello, world!");
}
END_TEST

// Тест-кейс 2: Преобразование пустой строки
START_TEST(to_lower_2) {
    const char str[] = "";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "");
}
END_TEST

// Тест-кейс 3: Преобразование строки с символами разных регистров
START_TEST(to_lower_3) {
    const char str[] = "HeLLo, WoRLd!";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "hello, world!");
}
END_TEST

// Тест-кейс 4: Преобразование строки с цифрами
START_TEST(to_lower_4) {
    const char str[] = "12345";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "12345");
}
END_TEST

// Тест-кейс 5: Преобразование строки с символами пунктуации
START_TEST(to_lower_5) {
    const char str[] = "!@#$%^&*()";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "!@#$%^&*()");
}
END_TEST

// Тест-кейс 6: Преобразование строки с пробелами
START_TEST(to_lower_6) {
    const char str[] = "   ";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "   ");
}
END_TEST

// Тест-кейс 7: Преобразование строки с русскими символами
START_TEST(to_lower_7) {
    const char str[] = "Привет, Мир!";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "привет, мир!");
}
END_TEST

// Тест-кейс 8: Преобразование строки с символами новой строки
START_TEST(to_lower_8) {
    const char str[] = "Hello\nWorld!";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "hello\nworld!");
}
END_TEST

// Тест-кейс 9: Преобразование строки с символами табуляции
START_TEST(to_lower_9) {
    const char str[] = "Hello\tWorld!";
    char result[20];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "hello\tworld!");
}
END_TEST

// Тест-кейс 10: Преобразование строки с разными типами символов
START_TEST(to_lower_10) {
    const char str[] = "Hello, 123, World! @#$";
    char result[30];
    strcpy(result, str);
    s21_to_lower(result);
    ck_assert_str_eq(result, "hello, 123, world! @#$");
}
END_TEST

Suite *to_lower_suite(void) {
    Suite *s = suite_create("SUITE_TO_LOWER");
    TCase *tc;
    tc = tcase_create("TC_TO_LOWER");
    tcase_add_test(tc, to_lower_1);
    tcase_add_test(tc, to_lower_2);
    tcase_add_test(tc, to_lower_3);
    tcase_add_test(tc, to_lower_4);
    tcase_add_test(tc, to_lower_5);
    tcase_add_test(tc, to_lower_6);
    tcase_add_test(tc, to_lower_7);
    tcase_add_test(tc, to_lower_8);
    tcase_add_test(tc, to_lower_9);
    tcase_add_test(tc, to_lower_10);
    suite_add_tcase(s, tc);
    return s;
}
