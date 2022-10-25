#include "../inc/libmx.h"

static int num_length(unsigned long num) {
    int length = 0;

    while (num) {
        num /= 16;
        length++;
    }

    return length;
}

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex_string = NULL;
    unsigned long nbr2 = nbr;
    int length = num_length(nbr);
    int temp;

	if (nbr == 0) {
    	hex_string = "0";	
    	return hex_string;
    }

    if (length == 0)
        return NULL;
      
    hex_string = mx_strnew(length);
    for (int i = length - 1; i >= 0; i--) {
        temp = nbr2 % 16;

        if (temp < 10)
            hex_string[i] = temp + 48;
        else
            hex_string[i] = temp + 87;

        nbr2 /= 16;
    }
    return hex_string;
}

