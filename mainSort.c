#include <stdio.h>
#include "isort.h"


int main() {
	char fileName[100];

		for (int j = 0; j < LEN; j++) {
			scanf("%d", (arr + j));
		}
	
	int arrSave[LEN];
	for (int k = 0; k < LEN; k++) {
		*(arrSave + k) = *(arr + k);
	}
	int number;
	printf("enter a number to first:\n");
	scanf("%d", &number);
	shift_element(arr, number);
	for (int k = 0; k < LEN; k++) {
		*(arr + k) = *(arrSave + k);
	}
	insertion_sort(arr, LEN);

	return -1;
}
