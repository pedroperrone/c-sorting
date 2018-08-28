//
//  main.c
//  c-sorting
//
//  Created by Pedro Perrone on 28/08/2018.
//  Copyright © 2018 Pedro Perrone. All rights reserved.
//

#include <stdio.h>
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

int main(int argc, const char * argv[]) {
    int array[] = {4, 1, 6, 9, 2, 7, 3, 8, 5, 10};
    print_array(array, 10);
    quicksort(array, 10);
    print_array(array, 10);
    return 0;
}
