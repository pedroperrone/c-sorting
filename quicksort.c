//
//  quicksort.c
//  c-sorting
//
//  Created by Pedro Perrone on 28/08/2018.
//  Copyright © 2018 Pedro Perrone. All rights reserved.
//

#include "quicksort.h"

void swap(int* number_a, int* number_b) {
    int aux = *number_a;
    *number_a = *number_b;
    *number_b = aux;
}

int partitionate(int list[], int start_index, int end_index) {
    int i, smallers_limit = start_index + 1;
    for(i = start_index + 1; i <= end_index; i++) {
        if(list[i] < list[start_index]) {
            swap(&list[smallers_limit], &list[i]);
            smallers_limit++;
        }
    }
    return smallers_limit - 1;
}

void recursive_quicksort(int list[], int start_index, int end_index) {
    int pivot_correct_index;
    
    if(end_index <= start_index) {
        return;
    }
    pivot_correct_index = partitionate(list, start_index, end_index);
    swap(&list[pivot_correct_index], &list[start_index]);
    recursive_quicksort(list, start_index, pivot_correct_index - 1);
    recursive_quicksort(list, pivot_correct_index + 1, end_index);
}

void quicksort(int list[], int list_size) {
    recursive_quicksort(list, 0, list_size - 1);
}
