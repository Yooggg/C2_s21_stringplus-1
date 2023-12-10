#include "s21_string.h"
char *s21_strchr(const char *str, int c){
    char * res = NULL;
    int flag = 0;
    while ((*str!='\0') &&(!flag)){
        if (c==*str){
            res = (char *) str;
            flag =1;
        }
        str++;
    }
    return res;
}
