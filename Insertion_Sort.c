#include <stdio.h>

void Insertion_sort(int arr[], int n);

int main() {
    int arr[20], n;

    printf("Enter the size of the array : ");
    scanf("%d", &n);

    printf("Enter the %d values in the array : ", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
    
    Insertion_sort(arr, n);

    printf("Array after Insertion sort : ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
}

void Insertion_sort(int arr[], int n) {
    int key, j;
    for(int i=1; i<n; i++) {
        key = arr[i];
        j = i-1;
        while(j>=0 && key<arr[j]) {
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = key;
    }    
}

/*
Enter the size of the array : 5
Enter the 5 values in the array : 2 5 3 9 7
Array after Insertion sort : 2 3 5 7 9
*/