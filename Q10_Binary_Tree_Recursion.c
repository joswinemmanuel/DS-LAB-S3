#include <stdio.h>

void buildtree(int a[], int i, char item) {
    int ch;
    char val;

    a[i] = item;

    printf("\nDo you want to create left chid for %c (1/0) : ", item);
    scanf("%d", &ch);
    if(ch==1) {
        printf("\nEnter the left child : ");
        scanf(" %c", &val);
        buildtree(a, 2*i, val);
    }
    
    printf("\nDo you want to create right chid for %c (1/0) : ", item);
    scanf("%d", &ch);
    if(ch==1) {
        printf("\nEnter the right child : ");
        scanf(" %c", &val);
        buildtree(a, 2*i+1, val);
    }
}

int main() {
    int a[100], n, height=1;
    char item;

    for(int i=0; i<100; i++)
        a[i] = -1;

    printf("Enter the height of the tree : ");
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        height *= 2;
    }
    height = height-1;

    printf("Enter the root Node : ");
    scanf(" %c", &item);
    buildtree(a, 1, item);

    printf("\nTree : ");
    for(int i=1; i<=height; i++) {
        if(a[i] == -1)
            printf("- ");
        else 
            printf("%c ", a[i]);
    }
    printf("\n");
}

/*
Enter the height of the tree : 3
Enter the root Node : A

Do you want to create left chid for A (1/0) : 1

Enter the left child : B

Do you want to create left chid for B (1/0) : 1

Enter the left child : D

Do you want to create left chid for D (1/0) : 0

Do you want to create right chid for D (1/0) : 0

Do you want to create right chid for B (1/0) : 0

Do you want to create right chid for A (1/0) : 1

Enter the right child : C

Do you want to create left chid for C (1/0) : 0

Do you want to create right chid for C (1/0) : 1

Enter the right child : F

Do you want to create left chid for F (1/0) : 0

Do you want to create right chid for F (1/0) : 0

Tree : A B C D - - F 
*/
