#include <stdio.h>

void root(char []);
int leftInsertion(char [], int);
int rightInsertion(char [], int);
void displayBinaryArray(char[], int);

int main() {    
    char binary[20];
    int option, parent, childOption, size=0, pos;
    for(int i=0;i<20;i++){
        binary[i]='*';
    }
    root(binary);
    do{
        printf("\nChoose your option\n");
        printf("\n1.Insertion\n2.Display Binary Array \n3.Exit\n");
        scanf("%d",&option);
        fflush(stdin);
        switch (option)
        {
        case 1:
            printf("Enter the parent node position\n");
            scanf("%d",&parent);
            printf("Choose your option\n");
            printf("1.Left Child\n2.Right Child\n");
            scanf("%d",&childOption);
            if(childOption==1){
                pos=leftInsertion(binary,parent);
            }
            else if(childOption==2){
                pos=rightInsertion(binary,parent);
            }
            else{
                printf("Enter a valid option");
            }
            if(pos>size){
                size=pos;
            }
            break;

        case 2 :
            displayBinaryArray(binary,size);
            break;
        case 3 :
            printf("\n<<<<<<<<<<<<<<<<<< THANK YOU >>>>>>>>>>>>>>>>>");
            break;
        default:
            printf("\nEnter a valid option\n");
            break;
        }
    }while(option!=3);
    return 0;
}
void root(char binaryTree[50]){
    char value;
    
        printf("Enter the value of root node\n");
        scanf("%c",&value);
        binaryTree[0]=value;
        printf("Data is added at Root position %d",0);
    
}
int leftInsertion(char binaryTree[50],int parent){
    char value;
    if ((binaryTree[parent])=='*'){
        printf("Parent node didn't found ! insertion at this position is not possible");
        return 0;
    }
    else{
        printf("Enter the value of node\n");
        fflush(stdin);
        scanf("%c",&value);
        binaryTree[(parent*2)+1]=value;
        printf("Data is added at position %d",(parent*2)+1);
        return ((parent*2)+1);
    }
}
int rightInsertion(char binaryTree[50],int parent){
    char value;
    if (binaryTree[parent]=='*'){
        printf("Parent node didn't found ! insertion at this position is not possible");
        return 0;
    }
    else{
        printf("Enter the value of node\n");
        fflush(stdin);
        scanf("%c",&value);
        binaryTree[(parent*2)+2]=value;
        printf("Data is added at position %d",(parent*2)+2);
        return ((parent*2)+2);
    }
}
void displayBinaryArray(char binaryTree[50],int size){
    int i;
    printf("Your Binary Tree represntation in array is ;-\n");
    for(i=0;i<size;i++){
        if(binaryTree[i]=='*'){
            printf("_  ");
        }
        else{
            printf("%c  ",binaryTree[i]);
        }
        
    }
}