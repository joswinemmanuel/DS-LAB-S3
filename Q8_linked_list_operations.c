#include<stdio.h>
#include <stdlib.h>

void inputFirst(int);
void display();
void inputEnd(int);
void inputParticular(int,int);

void deleteFirst();
void deleteEnd();
void deleteParticular(int);

struct node {
    int data;
    struct node *ptr;
};
struct node *start;


int main() {
    int option, value, position;
    printf("The linked list operations are : \n");
    printf("1) Enter at the first position\n2) Enter at the end position\n3) Enter at a particular position\n4) Delete from the first position\n5) Delete from the end position\n6) Delete from a particular position\n7) Display\n8) Exit\n");
    do {
        printf("\nSelect your option : ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                printf("Enter the data : ");
                scanf("%d", &value);
                inputFirst(value);
                display();
                break;
            case 2:
                printf("Enter the data : ");
                scanf("%d", &value);
                inputEnd(value);
                display();
                break;
            case 3:
                printf("Enter the data : ");
                scanf("%d", &value);
                printf("Enter the position : ");
                scanf("%d", &position);
                inputParticular(value, position);
                display();
                break;
            case 4:
                deleteFirst();
                display();
                break;
            case 5:
                deleteEnd();
                display();
                break;
            case 6:
            	printf("Enter the position : ");
            	scanf("%d", &position);
            	deleteParticular(position);
            	display();
            	break;
            case 7:
                display();
                break;
            case 8:
                printf("Exited\n");
                break;
            default:
                printf("Invalid option");
        }

    } while(option!=8);
}

void inputFirst(int value) { 
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node *));
     
    if(start == NULL) {
        temp->ptr = NULL;
        temp->data = value;
        start = temp;
    } else {
        temp->ptr = start;
        temp->data = value;
        start = temp;
    }
}

void inputEnd(int value) {
    struct node *temp, *p;
    temp = (struct node *)malloc(sizeof(struct node *));
    
    if(start == NULL) {
        temp->ptr = NULL;
        temp->data = value;
        start = temp;
    } else {
        p = start;
        while(p->ptr != NULL){
            p = p->ptr;
        }
        p->ptr = temp;
        temp->ptr = NULL;
        temp->data = value;
    }
}

void inputParticular(int value, int position){
    struct node *temp, *p;
    temp=(struct node *)malloc(sizeof(struct node *));
    int i;

    if(start == NULL) {
        temp->ptr = NULL;
        temp->data = value;
        start = temp;
    } else {
        p = start;
        for(i=1; i<position-1; i++){
            p = p->ptr;
        }
        temp->ptr = p->ptr;
        p->ptr = temp;
        temp->data = value;
    }
}

void deleteFirst() {
    struct node *temp;
    int value;

    if(start == NULL) {
        printf("Linked list is empty\n");
    } else if(start->ptr == NULL) {
        temp = start;
        value = start->data;
        printf("Deleting data = %d\n", value);
        start = NULL;
        free(temp);
    } else {
        temp = start;
        start = start->ptr;
        value = temp->data;
        printf("Deleting data = %d\n", value);
        free(temp);
    }
}

void deleteEnd() {
    struct node *temp;
    int value;

    if(start == NULL) {
        printf("Linked list is empty\n");
    } else if(start->ptr == NULL) {
        temp = start;        
        value = start->data;
        printf("Deleting data = %d\n", value);
        start = NULL;
        free(temp);
    } else {
        struct node *p;
        temp = start;
        p = start->ptr;
        while(p->ptr != NULL){
            p = p->ptr;
            temp = temp->ptr;
        }
        temp->ptr = NULL;
        value = p->data;
        printf("Deleting data = %d\n", value);
        free(p);
    }
}

void deleteParticular(int position) {
	struct node *temp;
	int value, i;

        if(start == NULL){
       	 printf("\nLinked list is empty\n");
        }
     	else if(start->ptr == NULL){
        	temp = start;
        	value = start->data;
        	printf("Deleting data = %d\n", value);
        	start = NULL;
        	free(temp);
    	} else { 
    		struct node *p;
    		temp = start;
    		p = start->ptr;
    		for(int i=1; i<position-1; i++){
    			temp = temp->ptr;
    			p = p->ptr;	
    		}
    		value = p->data;
        	printf("Deleting data = %d\n", value);
    		temp->ptr = p->ptr;
    		free(p);
    	}
}

void display(){
    struct node *temp;

    if(start == NULL){
        printf("List is empty\n");
    } else {
        printf("\nThe linked list : \n");
        for(temp=start; temp!=NULL; temp=temp->ptr)
            printf("%d ", temp->data);
        printf("\n");
    }
}