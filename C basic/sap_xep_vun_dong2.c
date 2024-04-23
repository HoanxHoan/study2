#include <stdio.h>
#include<stdlib.h>
void swap(double* a,double* b)
{
	double x = *a;
	*a=*b;
	*b=x;
}
void heapify(double arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 
	if (l < n && arr[l] > arr[largest])
		largest = l;
		
	if (r < n && arr[r] > arr[largest])
		largest = r;
		
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(double arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}
void printArray(double arr[], int n)
{
	for (int i = 0; i<n; ++i)
		printf("%.2lf\n",arr[i]);
}
int main()
{
	int x,k;
	scanf("%d %d",&k,&x);
	double *arr = (double *)malloc(x * sizeof(double));
	for(int i=0;i<x;i++)
	{scanf("%lf",&arr[i]);}
	heapSort(arr, x);
	printArray(arr, k);
	free(arr);
	return 0;
}
