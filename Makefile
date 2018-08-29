all: sorting

sorting: main.o quicksort.o
	gcc -o sorting main.o quicksort.o

main.o: main.c quicksort.h
	gcc -c -O3 main.c

quicksort.o: quicksort.c quicksort.h
	gcc -c -O3 quicksort.c

clean:
	rm *.o sorting
