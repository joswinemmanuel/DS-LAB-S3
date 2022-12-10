#include <stdio.h>

int count=0;

int binary_search(int arr[], int n, int x){
	int low=0, high=n-1, mid=0;
    count+=3;
	while(low <= high){
        count++;
		mid = (low + high) / 2;
		if(arr[mid] < x) {
            count++;
			low = mid + 1;
        } else if(arr[mid] > x) {
            count++;
			high = mid - 1;
        } else {
            count++;
			return mid;
        }
	}
    count++;
	return -1;
}

int main(){
	int arr[20], n, x, found;
    count++;
	
	printf("Enter the size of the sorted array : ");
    count++;
	scanf("%d", &n);
    count++;
	
	for(int i=0; i<n; i++){
        count++;
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter the element to search from the sorted array : ");
	scanf("%d", &x);
	
	printf("\nThe sorted array is \n");
	for(int i=0; i<n; i++){
        count++;
		printf("%d ", arr[i]);
	} 
	
	found = binary_search(arr, n, x);
	
	if(found != -1) {
        count++;
		printf("\n\n%d is found at index %d of the sorted array", x, found);
    } else {
        count++;
		printf("\n\n%d is not found in the sorted array", x);
    }

    printf("\n\nSpace Complexity : %d\n", 20+(4*n));
    printf("Time Complexity : %d\n", count);
    
	printf("\n\n");
	return 0;
	
}