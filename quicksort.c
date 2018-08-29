//
//  quicksort.c
//  c-sorting
//
//  Created by Pedro Perrone on 28/08/2018.
//  Copyright © 2018 Pedro Perrone. All rights reserved.
//

#include "quicksort.h"
#include <pthread.h>
#include <stdio.h>

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

void* parallel_recursive_quicksort(void* params_pttr) {
    QUICKSORT_PARAMS params = *((QUICKSORT_PARAMS*) params_pttr);
    int pivot_correct_index, end_index = params.end_index, start_index = params.start_index;
    int* list = params.list;
    
    if(end_index <= start_index) {
        return NULL;
    }
    pivot_correct_index = partitionate(list, start_index, end_index);
    swap(&list[pivot_correct_index], &list[start_index]);
    recursive_quicksort(list, start_index, pivot_correct_index - 1);
    recursive_quicksort(list, pivot_correct_index + 1, end_index);
    return NULL;
}

void parallel_quicksort(int list[], int list_size) {
    QUICKSORT_PARAMS params_for_smallers, params_for_greaters;
    pthread_t smallers, greaters;
    int pivot_correct_index;
    if(list_size == 0) {
        return;
    }
    pivot_correct_index = partitionate(list, 0, list_size - 1);
    swap(&list[pivot_correct_index], &list[0]);

    set_quicksort_params(&params_for_smallers, list, 0, pivot_correct_index - 1);
    set_quicksort_params(&params_for_greaters, list, pivot_correct_index + 1, list_size - 1);
    
    if(pthread_create(&smallers, NULL, parallel_recursive_quicksort, &params_for_smallers)) {
        return;
    }
    if(pthread_create(&greaters, NULL, parallel_recursive_quicksort, &params_for_greaters)) {
        return;
    }

    pthread_join(smallers, NULL);
    pthread_join(greaters, NULL);
}

void set_quicksort_params(QUICKSORT_PARAMS* params_struct, int* list, int start_index, int end_index) {
    params_struct->list = list;
    params_struct->start_index = start_index;
    params_struct->end_index = end_index;
}
