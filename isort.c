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

	for (int i = 0; i < LEN; i++) {
	for (int j = i; j >= 0 && *(arr + (j - 1)) > * (arr + j); j--) {
			int	temp = *(arr + j);
			*(arr + j) = *(arr + (j - 1));
			*(arr + (j - 1)) = temp;

		}
	}

	print(arr);
}
void shift_element(int* arr, int i) {
	int cheak = 1;
	int num = i;
	int count = 0;
	for (int z = 0; z < LEN; z++) {
		if (*(arr + z) == num) {
			if ((z - 0) < (num + 1)) {
				printf("error, there is not enough room to perforn the action. \n");
				cheak = 0;
				break;
			}
			int temp = *(arr + z);
			for (int j = z; j >= 0; j--) {
				count++;
				int temp2 = *(arr + (j - 1));
				*(arr + (j - 1)) = temp;
				temp = temp2;
				if (count == num) {
					break;
				}
			}
		}
	}
	if (cheak == 1) {
		print(arr);
	}
}
