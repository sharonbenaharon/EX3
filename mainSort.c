#include <stdio.h>
#include "isort.h"


int main() {
	
		for (int j = 0; j < LEN; j++) {
			scanf("%d", (arr + j));
		}
	insertion_sort(arr, LEN);
	print(arr);
	return 0;
}
