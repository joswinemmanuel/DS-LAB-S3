#include <stdio.h>

int binary_search(int arr[], int n, int x){
	int low=0, high=n-1, mid=0;
	while(low <= high){
		mid = (low + high) / 2;
		if(arr[mid] < x)
			low = mid + 1;
		else if(arr[mid] > x)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}

int main(){
	int arr[20], n, x, found;
	
	printf("Enter the size of the sorted array : ");
	scanf("%d", &n);
	
	for(int i=0; i<n; i++){
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter the element to search from the sorted array : ");
	scanf("%d", &x);
	
	printf("\nThe sorted array is \n");
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	
	found = binary_search(arr, n, x);
	
	if(found != -1)
		printf("\n\n%d is found at index %d of the sorted array", x, found);
	else
		printf("\n\n%d is not found in the sorted array", x);
	printf("\n\n");
	return 0;
	
}
