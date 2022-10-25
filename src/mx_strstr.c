#include "../inc/libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) {
        return NULL;
    }

    char *str1 = (char*)haystack;
    char *str2 = (char*)needle;
    int length = mx_strlen(str2);

    if (length == 0) {
        return str1;
    }

    while (*str1) {
        if (!mx_strncmp(str1, str2, mx_strlen(str2))) {
            return str1;   
        }
        str1++;
    }

    return NULL;
}

