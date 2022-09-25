#include<stdio.h>
#define n 5
int main()
{
    int queue[n],ch=1,front=0,rear=0,i,j=1,x=n;
    printf("Queue using Array");
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit\n");
    do {
        printf("\nEnter the Choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                if(rear==x)
                    printf("Queue is Full\n");
                else {
                    printf("Enter no %d : ",j++);
                    scanf("%d",&queue[rear++]);
                }
                break;
            case 2:
                if(front==rear){
                    printf("Queue is empty\n");
                } else {
                    printf("Deleted Element is %d\n",queue[front++]);
                    x++;
                }
                break;
            case 3:
                if(front==rear)
                    printf("Queue is Empty\n");
                else {
                    printf("Queue Elements are\n");
                    for(i=front; i<rear; i++){
                        printf("%d ",queue[i]);
                        printf("\n");
                    }
                }
                break;
            case 4:
                break;
            default:
                printf("Wrong Choice: please see the options\n");
        }
    } while(ch != 4);
    return 0;
}

