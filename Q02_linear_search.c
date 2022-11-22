#include <stdio.h>

int linear_search(int arr[], int n, int x){
	for(int i=0; i<n; i++){
		if(arr[i] == x)
			return i;
	}
	return -1;
}

int main(){
	int arr[20], n, x, found;
	
	printf("Enter the size of the array : ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter the element to search for : ");
	scanf("%d", &x);
	
	printf("\nThe array is \n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	found = linear_search(arr, n, x);
	
	if(found != -1)
		printf("\n\n%d is found at index %d of the array", x, found);
	else
		printf("\n\n%d is not found in the array", x);
	printf("\n\n");
	return 0;
	
}


