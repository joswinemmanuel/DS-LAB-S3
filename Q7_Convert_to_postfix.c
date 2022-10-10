#include <stdio.h>
#include <ctype.h>
#include <string.h> 

int top = -1;
char stack[20];

void push(char);
int pop();
int priority(char);

int main() {
    push('(');
    char infix[20], *p;
    printf("Enter the infix expression :\n");
    scanf("%s", infix);
    p = infix;
    printf("\nIt's postfix expression is :\n");
    while(*p != '\0') {
        if(isalnum(*p))
            printf("%c ", *p);
        else if(*p == '(')
            push(*p);
        else if(*p == ')')
            while(pop() != '(');
        else {
            while(priority(stack[top]) >= priority(*p)) { 
                pop();
            }
            push(*p);
        }
    p++;
    }
    while(top >= 0){
        pop();
    }
}

void push(char pushElement) {
    top++;
    stack[top] = pushElement;
}

int pop() {
    char x;
    x = stack[top];
    if(x != '(')
        printf("%c ",x);
    top--;
    return x;
}

int priority(char element){
    if(element == '^')
        return 3;
    else if(element=='*' || element=='/')
        return 2;
    else if(element=='+' || element=='-')
        return 1;
    else
        return 0;
}

/*
Enter the infix expression :
5*(6+2)-12/4

It's postfix expression is :
5 6 2 + * 1 2 4 / - 
*/


/*
Enter the infix expression :
(6+2)/(4-2*1)

It's postfix expression is :
6 2 + 4 2 1 * - /
*/