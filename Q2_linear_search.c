#include <stdio.h>

int main(){
    int array[100], n, value, index, found=0;

    printf("Enter the number of elements in the array : ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        printf("Enter the value of element %d : ", i+1);
        scanf("%d", &array[i]);
    }

    printf("Enter the value to search for : ");
    scanf("%d", &value);

    for(int i=0; i<n; i++){
        if(array[i] == value){
            index = i+1;
            found = 1;
            break;
        }
    }

    if(found){
        printf("Value found in the array at index %d", index);
    } else{
        printf("Value not found");
    }

    return 0;
}
