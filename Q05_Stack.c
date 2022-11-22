#include <stdio.h>

int stack[100], n, top, option;
void push();
void pop();
void display();

int main(){
    top = -1;
    printf("Enter the size of the stack (max = 100) : ");
    scanf("%d", &n);

    printf("\n1) To push an element\n");
    printf("2) To pop an element\n");
    printf("3) To display all the elements\n");
    printf("4) To exit out\n");

    do{
        printf("\nSelect your option : ");
        scanf("%d", &option);

        switch(option){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid option, Select again\n");
        }
    } while(option != 4);
}

void push(){
    if(top >= n-1){
        printf("Stack is in OVER FLOW condition\n");
    } else {
        top++;
        printf("Enter the value to push : ");
        scanf("%d", &stack[top]);
    }
}

void pop(){
    if(top <= -1){
        printf("Stack is in UNDER FLOW condition\n");
    } else {
        printf("%d is popped\n", stack[top]);
        top--;
    }
}

void display(){
    if(top >= 0){
        printf("The elements in stack\n");
        for(int i=top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    } else {
        printf("The stack is empty\n");
    }
}
