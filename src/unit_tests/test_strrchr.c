#include "test_string.h"

// Тест-кейс 1: Поиск последнего вхождения символа в строке
START_TEST(strrchr_1) {
    char str[] = "abcdef";
    int c = 'c';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 2: Поиск последнего вхождения символа в строке (пустая строка)
START_TEST(strrchr_2) {
    char str[] = "";
    int c = 'a';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 3: Поиск последнего вхождения символа в строке (символ не найден)
START_TEST(strrchr_3) {
    char str[] = "abcdef";
    int c = 'z';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 4: Поиск последнего вхождения символа в строке (пустая строка, символ не найден)
START_TEST(strrchr_4) {
    char str[] = "";
    int c = 'a';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 5: Поиск последнего вхождения символа в строке (пустая строка, символ не найден)
START_TEST(strrchr_5) {
    char str[] = "";
    int c = '\0';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 6: Поиск последнего вхождения символа в строке (символ в середине)
START_TEST(strrchr_6) {
    char str[] = "abcabc";
    int c = 'b';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 7: Поиск последнего вхождения символа в строке (символ в конце)
START_TEST(strrchr_7) {
    char str[] = "abcdef";
    int c = 'f';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 8: Поиск последнего вхождения символа в строке (символ в начале)
START_TEST(strrchr_8) {
    char str[] = "abcdef";
    int c = 'a';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST

// Тест-кейс 9: Поиск последнего вхождения символа в строке (символ - нуль-терминатор)
START_TEST(strrchr_9) {
    char str[] = "abcdef";
    int c = '\0';

    ck_assert_ptr_eq(s21_strrchr(str, c), strrchr(str, c));
}
END_TEST


// Тест-кейс 10: Поиск последнего вхождения символа в строке (русский символ) NOT COMPARISON WITH ORIGINAL FUNCTION
// START_TEST(strrchr_10) {
//     setlocale(LC_ALL, ""); // Устанавливаем локаль для корректной работы с широкими символами
//     const wchar_t str[] = L"Привет, мир!";
//     wint_t c = L'и';

//     ck_assert_ptr_eq(s21_strrchr((const char *)str, c), wcsrchr(str, c));
// }
// END_TEST

Suite *strrchr_suite(void) {
    Suite *s = suite_create("SUITE_STRRCHR");
    TCase *tc;
    tc = tcase_create("TC_STRRCHR");
    tcase_add_test(tc, strrchr_1);
    tcase_add_test(tc, strrchr_2);
    tcase_add_test(tc, strrchr_3);
    tcase_add_test(tc, strrchr_4);
    tcase_add_test(tc, strrchr_5);
    tcase_add_test(tc, strrchr_6);
    tcase_add_test(tc, strrchr_7);
    tcase_add_test(tc, strrchr_8);
    tcase_add_test(tc, strrchr_9);
    // tcase_add_test(tc, strrchr_10);
    suite_add_tcase(s, tc);
    return s;
}
