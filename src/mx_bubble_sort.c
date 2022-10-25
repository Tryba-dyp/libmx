#include "../inc/libmx.h"

int mx_bubble_sort(char **arr, int size) {
    int count = 0;

	if (size <= 0)
		return -1; 
    
    for (int i = 0; i < size; i++)
		if (arr[i] == NULL)
			return -1; 
    
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (mx_strcmp(arr[j], arr[j + 1]) > 0) {
                char *temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                count++;
            }
        }   
    }
    
    return count;
}

