/*
Program:  arrayCorrections.c
Made by:  Garrett Stanifer
Date:  5/3/2021
Correct the errors within the program
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

void means(int arr[], int nvals, double* arithPtr, double geomPtr);
int evenNumbers(int arr[], int arr1[], int nvals);

int main()
{
	int num[20];
	int evens[20];
	double arith, geom;
	int r, ct, elements = 20;
	srand(time(NULL));
	printf("Original Array\n");
	for (r = 0; r < elements; r++)
	{
		num[r] = rand() % 75 + 1;
		printf("%4d", num[r]);
	}

	printf("\n\n");
	means(num, elements, &arith, &geom);
	ct = evenNumbers(num, evens, 20);
	printf("The geometric mean is %.2lf\n", geom);
	printf("The arithmetic mean is %.2lf\n", arith);
	printf("Array of Even Numbers\n");
	for (r = 0; r <= ct; r++)
		printf("%4d", evens[r]);

	printf("\n");
	return 0;
}

//Finds the arithmetic and geometric mean in a 1-D array
void means(int arr[], int nvals, double* arithPtr, double* geomPtr)
{
	int k;
	double sum = 0;
	double prod = 1;
	for (k = 0; k <= nvals - 1; k++)
	{
		sum += arr[k];
		prod *= arr[k];
	}
	*arithPtr = sum / nvals;
	*geomPtr = pow(prod, (double)1 / nvals);
}

//Copies values that are evenly divisible by 2 into a new array.
int evenNumbers(int arr[], int evenArr[], int nvals)
{
	int k;
	int m = 0;
	for (k = 0; k <= nvals - 1; k++)
	{
		if (arr[k] % 2 == 0)
		{
			evenArr[m] = arr[k];
			m++;
		}
	}
	return m;
}
