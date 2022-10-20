#include <stdio.h>

void print_arr(int arr[], int n, int loop);
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

void print_arr(int arr[], int n, int loop) {
    printf("Loop %d : ", loop);
    for(int i=0; i<n; i++) {
            printf("%d ", arr[i]);
        }
    printf("\n");
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
        print_arr(arr, n, i);
    }    
}


/*
Enter the size of the array : 5
Enter the 5 values in the array : 8 3 1 2 5
Loop 1 : 3 8 1 2 5 
Loop 2 : 1 3 8 2 5 
Loop 3 : 1 2 3 8 5 
Loop 4 : 1 2 3 5 8 
Array after Insertion sort : 1 2 3 5 8
*/
