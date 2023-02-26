#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for(int j=low; j<high; j++) {
        if(arr[j] < pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quicksort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

int main() {
    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements in the array : ");
    for(int i=0; i<n; i++)
        scanf("%d", &arr[i]);

    printf("Before sorting : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    quicksort(arr, 0, n-1);

    printf("After sorting : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
