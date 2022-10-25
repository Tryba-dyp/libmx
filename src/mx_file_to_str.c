#include "../inc/libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) {
        return NULL;
    }
    
    char buf;
    int size = 0;

    int open_file = open(file, O_RDONLY);
    if (open_file == -1) {
        return NULL;
    }
    
    while (read(open_file, &buf, 1) > 0) {
		size++;
	}
	
    if (close(open_file) == -1) {
        return NULL;
	}  
    close(open_file);

    char *str = mx_strnew(size);
    open_file = open(file, O_RDONLY);
    
    if (open_file == -1) {
        return NULL;
	}
	
    for (int i = 0; read(open_file, &buf, 1) > 0; i++) {
        str[i] = buf;
	}
    
    if (close(open_file) == -1) {
        return NULL;
    }
    close(open_file);

    return str;
}

