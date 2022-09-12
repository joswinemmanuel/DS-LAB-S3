#include <stdio.h>

int binary_search_iterative(int array[], int n, int x){
    int low=0, high=n-1, mid=0;
    while(low <= high){
        mid = (high + low) / 2;
        if(array[mid] < x)
            low = mid + 1;
        else if(array[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    return -1;
}

int binary_search_recursive(int array[], int low, int high, int x){
    int mid = 0;
    if(high >= low){
        mid = (high + low) / 2;
        if(array[mid] == x)
            return mid;
        else if(array[mid] > x)
            return binary_search_recursive(array, low, mid-1, x);
        else
            return binary_search_recursive(array, mid+1, high, x);
    } else{
        return -1;
    }
}

int main(){
    int arr[100], n, value;
    printf("Enter the number of elements in the sorted array : ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Enter the values of element %d : ", i+1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the value to search for : ");
    scanf("%d", &value);

    printf("Output form iterative binary search : %d\n", binary_search_iterative(arr, n, value));
    printf("Output form recursive binary search : %d", binary_search_recursive(arr, 0, n-1, value));

    return 0;
}