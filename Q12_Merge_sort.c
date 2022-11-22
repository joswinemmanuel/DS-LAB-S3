#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int l, int m, int r) {
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for(i=0; i<n1; i++)
		L[i] = arr[l+i];
	for(j=0; j<n2; j++)
		R[j] = arr[m+1+j];

	i = 0; 
	j = 0;
	k = l;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int l, int r) {
	if(l < r) {
		int m = l+(r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

void printArray(int A[], int size) {
	int i;
	for(i=0; i<size; i++)
		printf("%d ", A[i]);
	printf("\n");
}

int main() {
	int arr[20], arr_size;

    printf("Enter the size of the array : ");
    scanf("%d", &arr_size);

    printf("Enter the %d values in the array : ", arr_size);
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }

	printf("\nGiven array before Merge Sort \n");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size-1);

	printf("\nSorted array after Merge Sort \n");
	printArray(arr, arr_size);
	return 0;
}

/*
Enter the size of the array : 5
Enter the 5 values in the array : 50 20 10 5 35
Given array before Merge Sort 
50 20 10 5 35 
Sorted array after Merge Sort 
5 10 20 35 50 
*/