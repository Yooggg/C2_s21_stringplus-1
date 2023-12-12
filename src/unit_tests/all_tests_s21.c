#include "test_string.h"

int main(){
    int number_failed = 0;
    Suite *s;
    SRunner *sr;
    Suite *s21_function_massive[] = {
    memchr_suite(),
    memcmp_suite(),
    strchr_suite(),
    strncmp_suite(),
    strpbrk_suite() , 
    strcspn_suite(),
    0
    };


for(int i = 0; s21_function_massive[i] != 0 ; i++){
    s = s21_function_massive[i];
    sr = srunner_create(s);
    srunner_run_all(sr,CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
    printf("\n");
}
  printf("========= FAILED: %d =========\n", number_failed);

  return number_failed == 0 ? 0 : 1;
}