#include <stdio.h>

int count;

void selection_sort(int arr[], int n){
	int min_index;
    count++;
	for(int i=0; i<n; i++){
		min_index = i;
        count++;
		for(int j=i+1; j<n; j++){
            count++;
			if(arr[j] < arr[min_index])
				min_index = j;
                count++;
		}
		if(min_index != i){
			int temp = arr[i];
			arr[i] = arr[min_index];
			arr[min_index] = temp;
            count+=3;
		}
	}
}

int main(){
	int arr[20], n;
    count++;
	printf("Enter the size of the array : ");
    count++;
	scanf("%d", &n);
    count++;
	for(int i=0; i<n; i++){
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
        count++;
	}
	
	printf("\nBefore Selection Sort\n");
	for(int i=0; i<n; i++){
        count++;
		printf("%d ", arr[i]);
	}
	
	selection_sort(arr, n);
	
	printf("\n\nAfter Selection Sort\n");
	for(int i=0; i<n; i++){
        count++;
		printf("%d ", arr[i]);
	}
	
    printf("\n\nSpace Complexity : %d\n", 20+(4*n));
    printf("Time Complexity : %d\n", count);

	return 0;
	
}
