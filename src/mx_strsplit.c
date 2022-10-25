#include "../inc/libmx.h"

static int mx_word_length(const char *s, char c) {
	int length = 0;
	
	while (s[length] != c && s[length] != '\0') {
		length++;
	}
	
	return length;
}

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) {
        return NULL;
    }

    int count_words = mx_count_words(s, c);
    
    if (count_words == -1) {
        return NULL;
    }

    char **arr = (char**)malloc(sizeof(char *) * (count_words + 1));
    
    int n = 0;
    while (*s != '\0') {
    	if (*s == c) {
    		s++;
    	}
        else {
            int word_length = mx_word_length(s, c);
            arr[n] = mx_strndup(s, word_length);
            s += word_length;
            n++;
        }
    }

    arr[count_words] = NULL;
    return arr;
}

