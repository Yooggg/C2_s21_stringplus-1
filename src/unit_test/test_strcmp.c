#include "test_string.h"

// Тест-кейс 1: Сравнение двух одинаковых строк
START_TEST(strcmp_1) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    size_t n = 13;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 2: Сравнение строк разной длины
START_TEST(strcmp_2) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello!";
    size_t n = 13;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 3: Сравнение строк с использованием части блока памяти
START_TEST(strcmp_3) {
    char str1[] = "Hello, World!";
    char str2[] = "Hello,!";
    size_t n = 6;  // Сравниваем только первые 6 символов
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 4: Сравнение пустых строк
START_TEST(strcmp_4) {
    char str1[] = "";
    char str2[] = "";
    size_t n = 1;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 5: Сравнение двух строк с общим префиксом
START_TEST(strcmp_5) {
    char str1[] = "CommonPrefix123";
    char str2[] = "CommonPrefix456";
    size_t n = 13;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 6: Сравнение двух строк, где первая длиннее
START_TEST(strcmp_6) {
    char str1[] = "LongerString123";
    char str2[] = "Short123";
    size_t n = 16;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 7: Сравнение двух строк, где вторая длиннее
START_TEST(strcmp_7) {
    char str1[] = "Short123";
    char str2[] = "LongerString123";
    size_t n = 16;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 8: Сравнение строк, где первый символ различен
START_TEST(strcmp_8) {
    char str1[] = "Apple";
    char str2[] = "Banana";
    size_t n = 6;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 9: Сравнение строк, где различие в средней части
START_TEST(strcmp_9) {
    char str1[] = "Programming";
    char str2[] = "Programmers";
    size_t n = 11;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

// Тест-кейс 10: Сравнение строк, где различие в конце
START_TEST(strcmp_10) {
    char str1[] = "End123";
    char str2[] = "End456";
    size_t n = 7;  // Длина строк
    
    ck_assert_int_eq(s21_strncmp(str1, str2, n), strncmp(str1, str2, n));
}
END_TEST

Suite *strcmp_suite(void) {
    Suite *s = suite_create("SUITE_STRCMP");
    TCase *tc;
    tc = tcase_create("TC_STRCMP");
    tcase_add_test(tc, strcmp_1);
    tcase_add_test(tc, strcmp_2);
    tcase_add_test(tc, strcmp_3);
    tcase_add_test(tc, strcmp_4);
    tcase_add_test(tc, strcmp_5);
    tcase_add_test(tc, strcmp_6);
    tcase_add_test(tc, strcmp_7);
    tcase_add_test(tc, strcmp_8);
    tcase_add_test(tc, strcmp_9);
    tcase_add_test(tc, strcmp_10);
    suite_add_tcase(s, tc);
    return s;
}
