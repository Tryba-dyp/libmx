#include "../inc/libmx.h"

int mx_count_words(const char *str, char c) {
    if (str == NULL) {
        return -1;
    }

    int i = 0;
    int words = 0;
	bool delimited = true;
    
    while (str[i] != '\0') {
        if (str[i] == c) {
			delimited = true;
        }
        else if (delimited) {
			words++;
			delimited = false;
        }
        
        i++;
    }  
 
    return words;  
}

