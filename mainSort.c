#include <stdio.h>
#include "isort.h"


int main() {
	char fileName[100];
	printf("Enter the file name:\n");
	scanf("%s", fileName);
	f = fopen(fileName, "r");
	if (f == NULL) {
		printf("Error cannot open %s", fileName);
		exit(1);
	}
	if (f != NULL) {
		for (int j = 0; j < LEN; j++) {
		fscanf(f, "%1d", (arr + j));
		}
	}
	fclose(f);
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