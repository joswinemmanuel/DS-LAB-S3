#include <stdio.h>

void selection_sort(int arr[], int n);

int main(){
	int arr[20], n;
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("\nBefore Selection Sort\n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	selection_sort(arr, n);
	
	printf("\n\nAfter Selection Sort\n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n\n");
	
	return 0;
	
}

void selection_sort(int arr[], int n){
	int min_index;
	for(int i=0; i<n; i++){
		min_index = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min_index])
				min_index = j;
		}
		if(min_index != i){
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
		}
	}
}
