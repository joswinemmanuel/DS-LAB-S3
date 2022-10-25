#include <stdio.h>  
   
int main() {  
    int arr[] = {1, 2, 8, 3, 2, 2, 2, 5, 1};   
    int length = sizeof(arr)/sizeof(arr[0]);  
    int fr[length];  
    
    int visited = -1;       
    for(int i=0; i<length; i++) {  
        int count = 1;  
        for(int j=i+1; j<length; j++){  
            if(arr[i] == arr[j]) {  
                count++;  
                fr[j] = visited;  
            }  
        }  
        if(fr[i] != visited)  
            fr[i] = count;  
    }  
        
    printf(" Element | Occurrence\n");  
    printf("---------------------\n");  
    for(int i=0; i<length; i++) {  
        if(fr[i] != visited) {  
            printf("%5d", arr[i]);  
            printf("    |  ");  
            printf("%4d\n", fr[i]);  
        }  
    }  
    return 0;  
}  

/*
 Element | Occurrence
---------------------
    1    |     2
    2    |     4
    8    |     1
    3    |     1
    5    |     1
*/