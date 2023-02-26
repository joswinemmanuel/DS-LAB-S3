#include <stdio.h>

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = (2*i)+1;
    int right = (2*i)+2;

    if(left<n && arr[left]>arr[largest])
        largest = left;

    if(right<n && arr[right]>arr[largest])
        largest = right;
    
    if(largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for(int i=(n/2)-1; i>=0; i--)
        heapify(arr, n, i);

    for(int i=n-1; i>=0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
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

    printf("Before Sorting : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heapsort(arr, n);

    printf("After Sorting : ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
