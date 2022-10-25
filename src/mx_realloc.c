#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) {
    if (ptr == NULL && size > 0) {
       return malloc(size);
    }
    
    if (ptr != NULL && size <= 0) {
        free(ptr);
        return NULL;
    }

    size_t old_size = malloc_size(ptr);//malloc_usable_size - for Linux
    void *new_ptr = NULL;

    if (size <= old_size) {
	    new_ptr = malloc(old_size);
        mx_memcpy(new_ptr, ptr, old_size);
    }
    else {
        new_ptr = malloc(size);
        mx_memcpy(new_ptr, ptr, size);
    }

    free(ptr);
    return new_ptr;
}

