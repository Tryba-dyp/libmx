#include "../inc/libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    while (mx_isspace(*str)) {
        str++;
    }

    int new_length = mx_strlen(str);

    while (mx_isspace(str[new_length - 1])) {
        new_length--;
    }

    return mx_strndup(str, new_length);
}

