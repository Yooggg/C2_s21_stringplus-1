#include "s21_string.h"

char *s21_strncat(char *dest, const char *src, size_t n){
    if (n != 0) {
		register char *d = dest;
		register const char *s = src;

		do {
			if ((*d++ = *s++) == 0) {
				while (--n != 0)
					*d++ = 0;
				break;
			}
		} while (--n != 0);
	}
	return (dest);
}
