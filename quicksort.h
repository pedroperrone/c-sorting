//
//  quicksort.h
//  c-sorting
//
//  Created by Pedro Perrone on 28/08/2018.
//  Copyright © 2018 Pedro Perrone. All rights reserved.
//

#ifndef quicksort_h
#define quicksort_h

typedef struct quicksort_params {
    int* list;
    int start_index;
    int end_index;
} QUICKSORT_PARAMS;

void swap(int* number_a, int* number_b);
void quicksort(int list[], int list_size);
void recursive_quicksort(int list[], int start_index, int end_index);
int partitionate(int list[], int start_index, int end_index);

void parallel_quicksort(int list[], int list_size);
void* parallel_recursive_quicksort(void* params);
void set_quicksort_params(QUICKSORT_PARAMS* params_struct, int* list, int start_index, int end_index);
#endif /* quicksort_h */
