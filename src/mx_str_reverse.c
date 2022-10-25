#include "../inc/libmx.h"

void mx_str_reverse(char *s) {
    int i = 0;
    int length = mx_strlen(s) - 1;
    
    while (i <= length / 2) {
        mx_swap_char(&s[i], &s[length - i]);
        i++;
    }    
}

