#include "../inc/libmx.h"

static char *mx_join(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }
    else if (s1 == NULL) {
        return mx_strdup(s2);
    }
    else if (s2 == NULL) {
        return mx_strdup(s1);
    }
    else {
        char *newstr = mx_strnew(mx_strlen(s1) + mx_strlen(s2));
        char *del = (char*)s1;
        
        newstr = mx_strcat(mx_strcpy(newstr, s1), s2);
		mx_strdel(&del);
		
		return newstr;
    }
}

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
	if (buf_size <= 0 || fd == -1) {
		return -2;
	}
	
	char *buffer = mx_strnew(buf_size);
	int status;
	if (*lineptr != NULL) {
		*lineptr = NULL;
	}
	
	while ((status = read(fd, buffer, 1)) > 0) {
		if (mx_get_char_index(buffer, delim) >= 0) {
			buffer[mx_get_char_index(buffer, delim)] = '\0';
			*lineptr = mx_join(*lineptr, buffer);
			free(buffer);
			return mx_strlen(*lineptr);
		}
		
		*lineptr = mx_join(*lineptr, buffer);
	}
	
	if (mx_strlen(*lineptr) == 0) {
		*lineptr = "";
		free(buffer);
		
		if (status == -1) {
			return -2;
		}
		else {
			return -1;
		}
	}
	
	free(buffer);
	return mx_strlen(*lineptr);
}

