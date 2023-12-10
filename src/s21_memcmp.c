#include "s21_string.h"

int s21_memcmp(const void *str1, const void *str2, size_t n){
    unsigned int res = 0;
    for (size_t i=0; i<n; i++){
        res = *((unsigned char *) (str1 )+i) - *((unsigned char *) (str2 )+i);
        if (res!=0){
            i=n;
        }
    }
    return res;
}
