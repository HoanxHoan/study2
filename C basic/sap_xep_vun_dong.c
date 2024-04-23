#include <stdio.h>
#include<stdlib.h>
int swap(int* a,int* b)
{
	int x = *a;
	*a=*b;
	*b=x;
}
void heapify(int arr[], int n, int i)
{
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	// Neu nut con trai lon hon so voi root
	if (l < n && arr[l] > arr[largest])
		largest = l;

	// Neu nut con phai lon hon so voi root
	if (r < n && arr[r] > arr[largest])
		largest = r;

	// Neu root khong phai la lon nhat
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);

		heapify(arr, n, largest);
	}
}

// Ham vun dong
void heapSort(int arr[], int n)
{
	// Tao mot dong (Sap xep lai mang)
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--)
	{
		// Di chuyen root ve cuoi cung
		swap(&arr[0], &arr[i]);

		// goi ham heapify
		heapify(arr, i, 0);
	}
}
void printArray(int arr[], int n)
{
	for (int i = 0; i<n; ++i)
		printf("%d\n",arr[i]);
}
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int n = sizeof(arr) / sizeof(arr[0]);
	heapSort(arr, n);
	printArray(arr, n);
	return 0;
}
