#include <stdio.h>

int count = 0;

int linear_search(int arr[], int n, int x){
	for(int i=0; i<n; i++){
        count++;
		if(arr[i] == x) {
            count++;
			return i;
        }
	}
    count++;
	return -1;
}

int main(){
	int arr[20], n, x, found;
    count++;
	

	printf("Enter the size of the array : ");
	scanf("%d", &n);
    count++;
	
	for(int i=0; i<n; i++){
        count++;
		printf("Enter the value of arr[%d] : ", i);
		scanf("%d", &arr[i]);
	}
	
	printf("\nEnter the element to search for : ");
	scanf("%d", &x);
    count++;
	
	printf("\nThe array is \n");
	for(int i=0; i<n; i++){
        count++;
		printf("%d ", arr[i]);
	}
	
	found = linear_search(arr, n, x);
	
	if(found != -1){
        count++;
		printf("\n\n%d is found at index %d of the array", x, found);
    }
	else {
        count++;
		printf("\n\n%d is not found in the array", x);
    }

    printf("\n\nSpace Complexity : %d\n", 20+(4*n));
    printf("Time Complexity : %d\n", count);
    
	printf("\n\n");
	return 0;
	
}