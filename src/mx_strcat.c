#include "../inc/libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    int i = 0;
    int size_s1 = mx_strlen(s1);
    
    while (s2[i] != '\0') {
        s1[size_s1 + i] = s2[i];
        i++;
    }
    
    s1[size_s1 + i] = '\0';
    return s1;    
}

