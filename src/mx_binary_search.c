#include "../inc/libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int left = 0;
    int right = size - 1; 
    int mid;

	if (size <= 0)
		return -1; 
    
    for (int i = 0; i < size; i++)
		if (arr[i] == NULL)
			return -1; 

    while (left <= right) {
        (*count)++;
        mid = (left + right) / 2;
        
        if (mx_strcmp(s, arr[mid]) == 0) 
            return mid;
        else if (mx_strcmp(s, arr[mid]) < 0)
            right = mid - 1;
        else
            left = mid + 1;
    }
    *count = 0;
    return -1;
}

