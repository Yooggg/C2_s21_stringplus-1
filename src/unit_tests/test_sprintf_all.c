
#include "test_string.h"

START_TEST(s21_sprintf_combinations_1) {
  char buffer[100];
  int standard_result =
      sprintf(buffer, "Integer: %5d, Octal: %5o, Float: %.2f, String: %10s", 42,
              42, 3.14, "Hello");

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer, "Integer: %5d, Octal: %5o, Float: %.2f, String: %10s", 42, 42,
      3.14, "Hello");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_2) {
  char buffer[100];
  int standard_result = sprintf(
      buffer, "Character: %*c, Pointer: %p, Unsigned: %lu, Scientific: %e", 8,
      'A', (void *)0x12345678, 12345L, 1.23e-4);

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer, "Character: %*c, Pointer: %p, Unsigned: %lu, Scientific: %e",
      8, 'A', (void *)0x12345678, 12345L, 1.23e-4);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_3) {
  char buffer[100];
  int standard_result = sprintf(
      buffer, "Integer: %+d, Octal: %o, Hex: %x, Float: %10.3f, String: %.5s",
      -42, 42, 42, -3.14159, "Testing");

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer,
      "Integer: %+d, Octal: %o, Hex: %x, Float: %10.3f, String: %.5s", -42, 42,
      42, -3.14159, "Testing");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_4) {
  char buffer[100];
  int standard_result = sprintf(
      buffer,
      "Unsigned: %u, Hex (uppercase): %X, Float: %-8.2f, String: %20.10s",
      123456, 255, 987.654, "Concatenation");

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer,
      "Unsigned: %u, Hex (uppercase): %X, Float: %-8.2f, String: %20.10s",
      123456, 255, 987.654, "Concatenation");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_5) {
  char buffer[100];
  int standard_result = sprintf(buffer, "Character: %c, Pointer: %p, Float: %e",
                                'X', (void *)0xabcdef, 123.456);

  char s21_buffer[100];
  int s21_result =
      s21_sprintf(s21_buffer, "Character: %c, Pointer: %p, Float: %e", 'X',
                  (void *)0xabcdef, 123.456);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_6) {
  char buffer[100];
  int standard_result = sprintf(buffer, "Character: %c, Pointer: %p, Float: %e",
                                'Y', (void *)0xabcdef, 789.012);

  char s21_buffer[100];
  int s21_result =
      s21_sprintf(s21_buffer, "Character: %c, Pointer: %p, Float: %e", 'Y',
                  (void *)0xabcdef, 789.012);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_7) {
  char buffer[100];
  int standard_result = sprintf(
      buffer,
      "Character: %c, Pointer: %p, Octal: %o, Hex (uppercase): %lX, Float: %e",
      'A', (void *)0xabcdef, 255, (unsigned long)0xabcdef12345678, 987.654e-3);

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer,
      "Character: %c, Pointer: %p, Octal: %o, Hex (uppercase): %lX, Float: %e",
      'A', (void *)0xabcdef, 255, (unsigned long)0xabcdef12345678, 987.654e-3);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_8) {
  char buffer[100];
  int standard_result = sprintf(
      buffer,
      "Unsigned: %u, Hex (uppercase): %X, Float: %-8.2f, String: %20.10s",
      123456, 255, 987.654, "Concatenation");

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer,
      "Unsigned: %u, Hex (uppercase): %X, Float: %-8.2f, String: %20.10s",
      123456, 255, 987.654, "Concatenation");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_9) {
  char buffer[100];
  int standard_result = sprintf(buffer, "Hex: %x, Octal: %o, Pointer: %p", 255,
                                123, (void *)0xabcdef);

  char s21_buffer[100];
  int s21_result = s21_sprintf(s21_buffer, "Hex: %x, Octal: %o, Pointer: %p",
                               255, 123, (void *)0xabcdef);

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_10) {
  char buffer[100];
  int standard_result =
      sprintf(buffer, "String: %s, Unsigned: %u, Character: %c",
              "Hello, World!", 123456, 'Z');

  char s21_buffer[100];
  int s21_result =
      s21_sprintf(s21_buffer, "String: %s, Unsigned: %u, Character: %c",
                  "Hello, World!", 123456, 'Z');

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

START_TEST(s21_sprintf_combinations_11) {
  char buffer[100];
  int standard_result = sprintf(
      buffer,
      "Unsigned: %u, Hex (uppercase): %X, Float: %-8.2f, String: %20.10s",
      98765, 4095, 1234.567, "Concatenation");

  char s21_buffer[100];
  int s21_result = s21_sprintf(
      s21_buffer,
      "Unsigned: %u, Hex (uppercase): %X, Float: %-8.2f, String: %20.10s",
      98765, 4095, 1234.567, "Concatenation");

  ck_assert_int_eq(s21_result, standard_result);
  ck_assert_str_eq(s21_buffer, buffer);
}
END_TEST

Suite *sprintf_all_suite(void) {
  Suite *s = suite_create("SUITE_sprintf_all");
  TCase *tc;
  tc = tcase_create("TC_sprintf_all");
  tcase_add_test(tc, s21_sprintf_combinations_1);
  tcase_add_test(tc, s21_sprintf_combinations_2);
  tcase_add_test(tc, s21_sprintf_combinations_3);
  tcase_add_test(tc, s21_sprintf_combinations_4);
  tcase_add_test(tc, s21_sprintf_combinations_5);
  tcase_add_test(tc, s21_sprintf_combinations_6);
  tcase_add_test(tc, s21_sprintf_combinations_7);
  tcase_add_test(tc, s21_sprintf_combinations_8);
  tcase_add_test(tc, s21_sprintf_combinations_9);
  tcase_add_test(tc, s21_sprintf_combinations_10);
  tcase_add_test(tc, s21_sprintf_combinations_11);

  suite_add_tcase(s, tc);
  return s;
}
