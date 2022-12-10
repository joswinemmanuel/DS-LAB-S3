#include <stdio.h>

int count=0;

//Bubble sort
void bubble_sort(int arr[], int n){
	for(int i=0; i<n-1; i++){
		for(int j=0; j<n-i-1; j++){
            count++;
			if(arr[j] > arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
                count+=3;
			}
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
	
	printf("\nBefore Bubble Sort\n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
        count++;
	}
	
	bubble_sort(arr, n);
	
	printf("\n\nAfter Bubble Sort\n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
        count++;
	}

    printf("\n\nSpace Complexity : %d\n", 20+(4*n));
    printf("Time Complexity : %d", count);
	
	printf("\n\n");
	return 0;
}

