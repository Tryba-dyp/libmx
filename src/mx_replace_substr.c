#include "../inc/libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (str == NULL || sub == NULL || replace == NULL) {
        return NULL;
    }

    int new_length = mx_strlen(str) + mx_count_substr(str, sub) * (mx_strlen(replace) - mx_strlen(sub));
    char *new_str = mx_strnew(new_length);
	int i = 0;
	
    while (i < new_length) {
        if (mx_strncmp(str, sub, mx_strlen(sub)) == 0) {
            mx_strncpy(&new_str[i], replace, mx_strlen(replace));
            str += mx_strlen(sub);
            i += mx_strlen(replace);
        }
        else {
        	new_str[i] = *str;
        	str++;
        	i++;
        }
    }

    return new_str;
}

