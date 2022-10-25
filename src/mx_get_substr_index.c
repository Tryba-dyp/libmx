#include "../inc/libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -2;
    }

    int i = 0;
    while (*str) {
        if (mx_strncmp(str, sub, mx_strlen(sub)) == 0) {
            return i;
        }
        i++;
        str++;
    }

    return -1;
}

