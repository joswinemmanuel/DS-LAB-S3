#include <stdio.h>

void selection_sort(int arr[], int n){
    int min_index;
    for(int i=0; i<n; i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        if(min_index != i){
            arr[i] = arr[i] + arr[min_index];
            arr[min_index] = arr[i] - arr[min_index];
            arr[i] = arr[i] - arr[min_index];
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
    selection_sort(arr, n);
}