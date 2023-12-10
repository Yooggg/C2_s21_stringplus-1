#include "s21_string.h"
int s21_strncmp(const char *str1, const char *str2, size_t n){
    int res = 0;
    for (size_t i=0; i<n; i++){
        res = *((unsigned char *) (str1 )+i) - *((unsigned char *) (str2 )+i);
        if ((res!=0)|| (*((char *) (str1 )+i)== '\0') ){

            i=n;
        }
    }
    if (n>1){
        if (res>0){
            res =1;
        }
        if (res< 0){
            res =-1;
        }
    }
    return res;
}
