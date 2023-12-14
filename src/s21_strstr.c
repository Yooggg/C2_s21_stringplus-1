#include "s21_string.h"
char *s21_strstr(const char *haystack, const char *needle){
    size_t res = s21_strlen(needle);
    if (res ==1){
        return (s21_strchr(haystack, *needle));
    }
    if (s21_strlen(needle)==0){
        return (char *)haystack;
    }
    while (*haystack!='\0'){
        const char *temp =  haystack;
        const char *temp2 = needle;
        size_t c =0;
        int flag =0;
        while (*haystack==*needle ){
                needle++;
                haystack++;
                c++;
                if (*haystack=='\0'){
                    flag=1;
                }
                
            }
        if (c==res){
            return ((char *)haystack)-c;
        }
        else if ((c-1==res) &&(flag)){
            return ((char *)haystack)-c;
        }
        haystack=temp;
        haystack++;
        needle=temp2;
    }
    return NULL;
}