#include <stdio.h>

void bubble_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                arr[j] = arr[j] + arr[j+1];
                arr[j+1] = arr[j] - arr[j+1];
                arr[j] = arr[j] - arr[j+1];
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
}

int main(){
    int arr[100], n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        printf("Enter value of element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("Sorted array: ");
    bubble_sort(arr, n);
}