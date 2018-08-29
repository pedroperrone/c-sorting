//
//  main.c
//  c-sorting
//
//  Created by Pedro Perrone on 28/08/2018.
//  Copyright © 2018 Pedro Perrone. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quicksort.h"

// Debuguing
void print_array(int array[], int array_size) {
    int i;
    printf("[");
    for(i = 0; i < array_size - 1; i++) {
        printf("%d - ", array[i]);
    }
    printf("%d]\n", array[i]);
}

int* create_array(size) {
    int* array = (int*) malloc(sizeof(int) * size);
    int i;
    for(i = 0; i < size; i++) {
        array[i] = rand() % (size + 1);
    }
    return array;
}

void copy_array(int* source, int** destiny, int size) {
    int i;
    *destiny = (int*) malloc(sizeof(int) * size);
    for(i = 0; i < size; i++) {
        (*destiny)[i] = source[i];
    }
}

int main(int argc, const char * argv[]) {
    int* array, *array_cp;
    clock_t start, end;
    double total_time;
    srand((unsigned) time(NULL));

    printf("Teste com 100 milhoes de elementos.\n\nCriando array...\n");
    array = create_array(100000000);
    
    printf("Copiando array...\n");
    copy_array(array, &array_cp, 100000000);
    
    printf("Ordenando sem paralelismo...\n");
    start = clock();
    quicksort(array, 100000000);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("A ordenacao sem paralelismo durou %f segundos.\n\n", total_time);
    
    printf("Ordenando com paralelismo...\n");
    start = clock();
    parallel_quicksort(array_cp, 100000000);
    end = clock();
    total_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("A ordenacao com paralelismo durou %f segundos.\n", total_time);

    free(array);
    free(array_cp);
    return 0;
}
