#include "../inc/libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
	if (s != NULL) {
		for (size_t i = mx_strlen(s); n > 0; i--, n--) {
        	if (((const unsigned char *)s)[i] == (unsigned char)c) {
        	    return (void *)&(((unsigned char *)s)[i]);
        	}
    	}
    }
    
    return NULL;
}

