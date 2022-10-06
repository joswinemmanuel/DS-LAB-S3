#include <stdio.h>

int circular_queue[100], n, front=-1, rear=-1, option;

void Enqueue();
void Dequeue();
void Display();

int main(){
	printf("Enter the size of the Circular queue : ");
	scanf("%d", &n);

	printf("\n1) Enqueue\n2) Dequeue\n3) Display\n4) Exit\n");
	do {
		printf("\nSelect your option : ");
		scanf("%d", &option);

		switch(option){
			case 1:
				Enqueue();
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				Display();
				break;
			case 4:
				break;
			default:
				printf("Please select valid option\n");
		}
	} while(option != 4);
}

void Enqueue() {
    if((front == rear + 1) || (front == 0 && rear == n-1))
        printf("Circular Queue is full\n");
    else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % n;
        printf("Enter the element to enqueue : ");
        scanf("%d", &circular_queue[rear]);
    }
}

void Dequeue() {
    int element;
    if(front == -1)
        printf("Circular Queue is empty, no elements to remove \n");
    else {
        int element = circular_queue[front];
        if(front == rear)
            front = rear = -1;
        else {
            front = (front + 1) % n;
        }
        printf("%d is removed \n", element);
    }
}

void Display() {
    int i;
    if(front == -1)
        printf("Empty Circular queue, no elements to display\n");
    else {
        printf("\n Front    -> %d ", front);
        printf("\n Elements -> ");
        for (i = front; i != rear; i = (i + 1) % n) {
        printf("%d ", circular_queue[i]);
        }
        printf("%d ", circular_queue[i]);
        printf("\n Rear     -> %d \n", rear);
    }
}