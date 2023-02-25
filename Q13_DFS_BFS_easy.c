#include <stdio.h>

int stack[50], top=-1, queue[50], front=-1, rear=-1, visited[50], adj[50][50];

void push(int data) {
    if(top >= 49)
        printf("Overflow\n");
    else {
        stack[++top] = data;
    }
}

int pop() {
    if(top <= -1)
        return 0;
    else
        return stack[top--];
}

void DFS(int source, int n) {
    int printable;

    printf("DFS : ");
    push(source);
    visited[source] = 1;
    printable = pop();
    if(printable != 0)
        printf(" %d ", printable);
    
    while(printable != 0) {
        for(int i=1; i<=n; i++) {
            if(adj[printable][i]!=0 && visited[i]==0) {
                push(i);
                visited[i] = 1;
            }
        }
        printable = pop();
        if(printable != 0)
            printf(" %d ", printable);
        
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == 0) {
            DFS(i, n);
        }
    }
}

void add(int data) {
    if(rear>=49)
        printf("Overflow\n");
    else {
        if(front==-1)
            front = 0;
        queue[++rear] = data;
    }
}

int delete() {
    if(front<=-1 || front>rear)
        return 0;
    else
        return queue[front++];
}

void BFS(int source, int n) {
    int printable;

    printf("BFS : ");
    add(source);
    visited[source] = 1;
    printable = delete();
    if(printable != 0)
        printf(" %d ", printable);
    
    while(printable != 0) {
        for(int i=1; i<=n; i++) {
            if(adj[printable][i]!=0 && visited[i]==0) {
                add(i);
                visited[i] = 1;
            }
        }
        printable = delete();
        if(printable != 0)
            printf(" %d ", printable);
        
    }

    for(int i=1; i<=n; i++) {
        if(visited[i] == 0) {
            BFS(i, n);
        }
    }
}

int main() {
    int n, choice, source;
    char ch;

    printf("Enter the no. of vertices : ");
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("Enter (1/0) if %d hava a relation with %d : ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }

    printf("\nCorresponding Adjustancy Matrix :\n");
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nMENU\n1) BFS\n2) DFS\n");

    do {
        for(int i=1; i<=n; i++)
            visited[i] = 0;

        printf("Enter the source vertex : ");
        scanf("%d", &source);
        printf("Enter the choice : ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                BFS(source, n);
                break;
            case 2:
                DFS(source, n);
                break;
            default:
                printf("Enter a valid choice\n");
        }
        printf("\nDo you want to continue? (Y/N) : ");
        scanf(" %c", &ch);
        printf("\n");
    } while(ch=='y' || ch=='Y');

}

/*
Enter the no. of vertices : 3
Enter (1/0) if 1 hava a relation with 1 : 1
Enter (1/0) if 1 hava a relation with 2 : 1
Enter (1/0) if 1 hava a relation with 3 : 1
Enter (1/0) if 2 hava a relation with 1 : 1
Enter (1/0) if 2 hava a relation with 2 : 1
Enter (1/0) if 2 hava a relation with 3 : 1
Enter (1/0) if 3 hava a relation with 1 : 1
Enter (1/0) if 3 hava a relation with 2 : 1
Enter (1/0) if 3 hava a relation with 3 : 1

Corresponding Adjustancy Matrix :
1 1 1 
1 1 1 
1 1 1 

MENU
1) BFS
2) DFS
Enter the source vertex : 1
Enter the choice : 1
BFS :  1  2  3 
Do you want to continue? (Y/N) : Y

Enter the source vertex : 1
Enter the choice : 2
DFS :  1  3  2 
Do you want to continue? (Y/N) : N
*/
