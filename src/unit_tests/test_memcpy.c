#include "test_string.h"

// Тест-кейс 1: Копирование строки в пустой буфер
START_TEST(test_memcpy_1) {
  char dest[20];
  const char src[] = "Hello, World!";

  ck_assert_ptr_eq(s21_memcpy(dest, src, strlen(src) + 1), dest);
  ck_assert_str_eq(dest, src);
}
END_TEST

// Тест-кейс 2: Копирование части строки
START_TEST(test_memcpy_2) {
  char dest[10];
  const char src[] = "Hello, World!";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 5), dest);
  dest[5] = '\0';  // Устанавливаем нуль-символ вручную, так как s21_memcpy не
                   // добавляет его
  ck_assert_str_eq(dest, "Hello");
}
END_TEST

// Тест-кейс 3: Копирование из пустого буфера
START_TEST(test_memcpy_3) {
  char dest[10];
  const char src[] = "";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 1), dest);
  ck_assert_str_eq(dest, "");
}
END_TEST

// Тест-кейс 4: Попытка копирования из NULL
START_TEST(test_memcpy_4) {
  char dest[10];

  ck_assert_ptr_eq(s21_memcpy(dest, NULL, 1), dest);
  ck_assert_str_eq(dest, "");  // Должно остаться неизменным
}
END_TEST

// Тест-кейс 5: Попытка копирования в NULL
START_TEST(test_memcpy_5) {
  char src[] = "Hello, World!";

  ck_assert_ptr_eq(s21_memcpy(NULL, src, strlen(src) + 1), NULL);
  // Ничего проверять не можем, так как указатель NULL
}
END_TEST

// Тест-кейс 6: Копирование в и из NULL
START_TEST(test_memcpy_6) {
  ck_assert_ptr_eq(s21_memcpy(NULL, NULL, 0), NULL);
  // Ничего проверять не можем, так как указатели NULL
}
END_TEST

// Тест-кейс 7: Копирование из пустого источника
START_TEST(test_memcpy_7) {
  char dest[10] = "Existing";
  const char src[] = "";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 1), dest);
  ck_assert_str_eq(dest, "Existing");  // Ничего не должно измениться
}
END_TEST

// Тест-кейс 8: Попытка копирования 0 байт (буферы не изменяются)
START_TEST(test_memcpy_8) {
  char dest[10] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest, src, 0), dest);
  ck_assert_str_eq(dest, "Existing");  // Ничего не должно измениться
}
END_TEST

// Тест-кейс 9: Копирование в перекрывающийся буфер (неопределенное поведение)
START_TEST(test_memcpy_9) {
  char dest[10] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest + 3, src, 5), dest + 3);
  ck_assert_str_eq(
      dest, "ExiHello");  // Результат неопределен, так как буферы перекрываются
}
END_TEST

// Тест-кейс 10: Копирование в буфер с нуль-символом (копирование до
// нуль-символа)
START_TEST(test_memcpy_10) {
  char dest[20] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest, src, strlen(src)), dest);
  ck_assert_str_eq(dest, "Hello");  // Копирование до нуль-символа
}
END_TEST

// Тест-кейс 11: Копирование с использованием смещенных указателей
START_TEST(test_memcpy_11) {
  char dest[20] = "Existing";
  const char src[] = "Hello";

  ck_assert_ptr_eq(s21_memcpy(dest + 3, src, 5), dest + 3);
  ck_assert_str_eq(dest, "ExiHello");  // Копирование в смещенный буфер
}
END_TEST

Suite *memcpy_suite(void) {
  Suite *s;
  TCase *tc_memcpy;

  // Создаем новую сьюту
  s = suite_create("memcpy_suite");

  // Создаем новый тест-кейс
  tc_memcpy = tcase_create("memcpy_tests");

  // Добавляем тесты в тест-кейс
  tcase_add_test(tc_memcpy, test_memcpy_1);
  tcase_add_test(tc_memcpy, test_memcpy_2);
  tcase_add_test(tc_memcpy, test_memcpy_3);
  tcase_add_test(tc_memcpy, test_memcpy_4);
  tcase_add_test(tc_memcpy, test_memcpy_5);
  tcase_add_test(tc_memcpy, test_memcpy_6);
  tcase_add_test(tc_memcpy, test_memcpy_7);
  tcase_add_test(tc_memcpy, test_memcpy_8);
  tcase_add_test(tc_memcpy, test_memcpy_9);
  tcase_add_test(tc_memcpy, test_memcpy_10);
  tcase_add_test(tc_memcpy, test_memcpy_11);

  // Добавляем тест-кейс в сьюту
  suite_add_tcase(s, tc_memcpy);

  return s;
}