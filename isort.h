#ifndef _ISORT_H
#define _ISORT_H
#define LEN 50
#include <stdio.h>
#include <stdlib.h>
FILE* f;
int arr[LEN] ;

void shift_element(int* arr, int i);
void insertion_sort(int* arr, int len);
void print(int* arr);




#endif
