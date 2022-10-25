#include "../inc/libmx.h"

static int str_length(const char *str) {
    int length = 0;

    while (str[length] != '\0') {
        length++;
    }

    return length;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    if (hex == NULL){
        return 0;
    }
    
    int length = str_length(hex);
    unsigned long num = 0;
    unsigned long temp = 1;

    for (int i = 0; i <= length; i++) {
        if (hex[length - i] >= '0' && hex[length - i] <= '9') {
            num = num + (hex[length - i] - 48) * temp;
            temp = temp * 16;
        }
        if (hex[length - i] >= 'A' && hex[length - i] <= 'Z') {
            num = num + (hex[length - i] - 55) * temp;
            temp = temp * 16;
        }
        if (hex[length - i] >= 'a' && hex[length - i] <= 'z') {
            num = num + (hex[length - i] - 87) * temp;
            temp = temp * 16;
        }
    }
    return num;
}

