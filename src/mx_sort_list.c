#include "../inc/libmx.h"

static void swap_nodes(void **data1, void **data2) {
    void *temp = *data1;
    *data1 = *data2;
    *data2 = temp;
}

t_list *mx_sort_list(t_list *lst, bool (*cmp)(void *, void *)) {
	if (lst == NULL || cmp == NULL) {
		return NULL;
	}
	
	for (t_list *temp1 = lst; temp1 != NULL; temp1 = temp1->next) {
		for (t_list *temp2 = lst; temp2->next != NULL; temp2 = temp2->next) {
			if (cmp(temp2->data, temp2->next->data)) {
				swap_nodes(&temp2->data, &temp2->next->data);  
    		}
		}
	}
	
    return lst;
}

