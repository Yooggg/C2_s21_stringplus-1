#include "test_string.h"

void make_the_test(Suite *test_to_run, int *tests_counter) {
  if (*tests_counter > 1) printf("\n");
  printf("%s%d%s", "Идет тест: ", *tests_counter, "\n");
  (*tests_counter)++;

  SRunner *sr = srunner_create(test_to_run);

  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);

  srunner_free(sr);
}

int main() {
  Suite *s21_function_massive[] = {memchr_suite(),
                                   memcmp_suite(),
                                   strchr_suite(),
                                   strncmp_suite(),
                                   strpbrk_suite(),
                                   strcspn_suite(),
                                   strrchr_suite(),
                                   strstr_suite(),
                                   //insert_suite(),
                                   strlen_suite(),
                                   strncat_suite(),
                                   strncpy_suite(),
                                   memcpy_suite(),
                                   to_upper_suite(),
                                   to_lower_suite(),
                                   sprintf_f_suite(),
                                   sprintf_c_suite(),
                                   sprintf_i_suite(),
                                   sprintf_g_suite(),
                                   sprintf_e_suite(),
                                   sprintf_E_suite(),
                                   sprintf_d_suite(),
                                   sprintf_G_suite(),
                                   sprintf_o_suite(),
                                   sprintf_s_suite(),
                                   sprintf_u_suite(),
                                   sprintf_x_suite(),
                                   sprintf_X_suite(),
                                   sprintf_p_suite(),
                                   sprintf_n_suite(),
                                   sprintf_percent_suite(),
                                   sprintf_all_suite(),
                                   sprintf_width_suite(),
                                   sprintf_length_suite(),
                                   sscanf_suite_d(),

                                   0};

  int tests_counter = 1;
  // В цикле прогоняем тест-кейсы для всех функций
  for (Suite **i = s21_function_massive; *i != NULL; i++) {
    make_the_test(*i, &tests_counter);
  }

  return 0;
}
