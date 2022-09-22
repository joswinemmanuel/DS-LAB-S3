#include <stdio.h>

void bubble_sort(int arr[], int n);

int main(){
	int arr[20], n;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("\nBefore Bubble Sort\n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	bubble_sort(arr, n);
	
	printf("\n\nAfter Bubble Sort\n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	printf("\n\n");
	return 0;
}

void bubble_sort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}
