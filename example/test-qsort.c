#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 1000000

int compare(const void *a, const void *b)
{
    const unsigned long *ia = (const unsigned long *)a;
    const unsigned long *ib = (const unsigned long *)b;
    return *ia - *ib; 
}

int main()
{
	unsigned long *arr = (unsigned long*)malloc(ARRAY_SIZE * sizeof(unsigned long));
	unsigned long val = 1;
	for (size_t i = 0; i < ARRAY_SIZE; i++) {
		arr[i] = val;
		val = ((val * 8191) << 7) ^ val;
	}
	qsort(arr, ARRAY_SIZE, sizeof(unsigned long), compare);
	printf("%ld\n", arr[ARRAY_SIZE-1]);
	return 0;
}
