#include <stdio.h>

void buildtree(int a[], int i, int item) {
    int ch, val;

    a[i] = item;

    printf("\nDo you want to create left chid for %d (1/0) : ", item);
    scanf("%d", &ch);
    if(ch==1) {
        printf("\nEnter the left child : ");
        scanf("%d", &val);
        buildtree(a, 2*i, val);
    }
    
    printf("\nDo you want to create right chid for %d (1/0) : ", item);
    scanf("%d", &ch);
    if(ch==1) {
        printf("\nEnter the right child : ");
        scanf("%d", &val);
        buildtree(a, 2*i+1, val);
    }
}

int main() {
    int a[100], item;

    for(int i=0; i<100; i++)
        a[i] = -1;

    printf("Enter the root Node : ");
    scanf("%d", &item);
    buildtree(a, 1, item);

    printf("\nTree : ");
    for(int i=1; i<=16; i++) {
        if(a[i] == -1)
            printf("- ");
        else 
            printf("%d ", a[i]);
    }
}
