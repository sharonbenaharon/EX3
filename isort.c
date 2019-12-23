#include "isort.h"
void print(int* arr) {
	for (int x = 0; x < LEN; x++)
	{
		if (x != LEN - 1) {
			printf("%d,", *(arr + x));
		}
		if (x == LEN - 1) {
			printf("%d", *(arr + x));
		}
	}

	printf("\n");
}


void insertion_sort(int* arr, int len) {
int index,j;
	for (int i = 1; i< LEN; i++) {
	index=*(arr+i);
	j=i-1;
	for ( j >= 0 && index<*(arr + j); j--) {
			*(arr+j+1)=*(arr+j);
		}
	}
}
void shift_element(int* arr, int i) {
	int*j;
	for(j=(arr+i);j<arr ;j--){
		*j=*(j-1);
	}
}
