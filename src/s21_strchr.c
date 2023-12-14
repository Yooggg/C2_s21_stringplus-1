#include "s21_string.h"
char *s21_strchr(const char *str, int c){
    char * res = NULL;
    while (*str!='\0'){
        if (c==*str){
            
            res = ( char *) str;
            break;
        }
        str++;
    }
    if (*str=='\0' && c=='\0'){
        res = (char*)str;
    }
    return res;
}
