#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) 
        return -1;
    
    int count = 0;

    if (left < right) {
        int first = left;
        int last = right;
        char *mid = arr[(first + last) / 2];

        while (first <= last) {
            while (mx_strlen(arr[first]) < mx_strlen(mid)) 
                first++;
            while (mx_strlen(arr[last]) > mx_strlen(mid)) 
                last--;

            if (first <= last) {
                if (mx_strlen(arr[last]) != mx_strlen(arr[first])) {
                    char *temp = arr[first];
                    arr[first] = arr[last];
                    arr[last] = temp;
                    count++;
                }
                first++;
                last--;
            }
        }

        count += mx_quicksort(arr, left, last);
        count += mx_quicksort(arr, first, right);
    }    
    return count;
}

