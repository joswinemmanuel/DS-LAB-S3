#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
	

typedef struct node{
	struct node* prev;
    int value;
	int size;
	struct node* next;
}node;
	

	

	

node* create(){
	node* t = malloc(sizeof(node));
	printf("Enter the value : ");
	scanf("%d",&(t->value));
	printf("Enter the size : ");
	scanf("%d",&(t->size));
	t->next=NULL;
	t->prev=NULL;
	return t;
}
	

node* insert(node* t,node* H){ // inserting at front
	if(H==NULL){
	    H=t;
	}
	else{
	    node* p = H;
	    while(p->next){
	        p=p->next;
	    }
	    p->next=t;
	    t->prev=p;
	}
	return H;
}
node* insertGarbage(int p,node* H){ // inserting garbage
	node* t= malloc(sizeof(node));
	t->next=NULL;
	t->prev=NULL;
	t->size=p;
	t->value=INT_MIN;
	if(H==NULL){
	    H=t;
	}
	else{
	    node* p = H;
	    while(p->next){
	        p=p->next;
	    }
	    p->next=t;
        t->prev=p;
    }
	return H;
}
	

void display(node * H){
	printf("\nThe current list is         : ");
    node* p = H;
	if(p){
	    while(p->next){
	        if(p->value!=INT_MIN){
                printf("%d -> ",p->value);
	        }
	        else{
	            printf("# -> ");
            }
	        p=p->next;
	    }
	    if(p->value!=INT_MIN){
            printf("%d -> ",p->value);
	    }
	    else{
            printf("# -> ");
        }
	}
	

	printf("\nThe corresponding sizes are : ");
    p = H;
	if(p){
	    while(p->next){
	        printf("%d -> ",p->size);
	        p=p->next;
	    }
	    printf("%d -> ",p->size);
    }
	printf("\n");
}
	

void displayGarbage(node * HG){
	printf("\nThe garbage values is : ");
    node* p = HG;
	if(p){
	    while(p->next){
	        printf("%d -> ",p->size);
            p=p->next;
        }
	    printf("%d -> ",p->size);
	}
	

}
	

	

node* delete(node* H,node* HG){
	int pos;
	printf("Enter the pos to delete : ");
	scanf("%d",&pos);  
	node* p = H;      
	for(int i =2;i<=pos;i++){
	    p=p->next;
	}
	if(p->value!=INT_MIN){
	    p->value=INT_MIN;
	    HG= insertGarbage(p->size,HG);
    }
    display(H);
	return HG;
}
void garbageCollection(node* H,node* HG){
	node * p =H;
    int garbage = 0;
	if(p){
	    while(p->next){
	        if(p->value==INT_MIN){
                garbage += p->size;
	        }
	        p=p->next;
	    }
        if(p->value==INT_MIN){
	        garbage += p->size;
	    }
	}
    printf("The amount of garbage collected is : %d",garbage);
	displayGarbage(HG);
	

}
int main(){
	node* HL = NULL;
    node* HG = NULL;
	int n,pos;
	while (1){
	 	printf("\n\n============================");
		printf("\n1.Display\n2.Insert\n3.Delete\n4.Collect Garbage\n5.Exit");
		printf("\n============================");
        printf("\nEnter Choice : ");
		fflush(stdin);
	    scanf("%d", &n);
 		node* t;
		switch (n) {
	        case 1:
                display(HL);	     
                break;
	        case 2:
	            t=create();
	            HL=insert(t,HL);
                display(HL);
	            
	            break;
	        case 3:
	            HG = delete(HL,HG);
	            break;
            case 4:
	            garbageCollection(HL,HG);
	            break;
	        case 5:
	            exit(0);
            default :
	            printf("Wrong option selected");
	    }
	}
}
