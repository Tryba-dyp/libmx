#include "../inc/libmx.h"

static int num_length(int num) {
    int length = 0;

    while (num) {
        num /= 10;
        length++;
    }

    return length;
}

char *mx_itoa(int num) {
    char *str = NULL;

    if (num == 0) {
        str = mx_strnew(1);
        str[0] = '0';
        return str;
    }

    int length = num_length(num);
    int temp = num;
	str = mx_strnew(length);

	if (num == 0) {
		str = "0";
		return str;
	}	
	
	if (num == -2147483648) {
		str = "-2147483648";
		return str;
	}
    
    if (temp < 0) {
        temp *= -1;
        length++;
    }
    
    if (num < 0) {
        str[0] = '-';
        num *= -1;
    }
    
    str[length--] = '\0';
    while ((num != 0 && length >= 0) 
    		&& str[length] != '-') {
        str[length--] = (num % 10) + '0';
        num /= 10;
    }
    
    return str;
}

