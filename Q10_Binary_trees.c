#include<stdio.h>
#include<math.h>

int main()
{
    int i,size,n,nodes;
    char myarray[50];
    printf("Enter the total height of the binary tree:");
    scanf("%d",&n);
    size=n+1;
    printf("Enter the Root Element:");
    scanf(" %c",&myarray[0]);
   
    nodes=(n*n)-2;
    printf("\nEnter ""_"" to represent Free space\n");
    for(i=0;i<nodes+1;i++){
        if(myarray[i]!='_'){
            printf("Enter the Left child of  %c :",myarray[i]);
            scanf(" %c",&myarray[(2*i)+1]);
            printf("Enter the Right child of  %c :",myarray[i]);
            scanf(" %c",&myarray[(2*i)+2]);
        }
        else{
            myarray[(2*i)+1]='_';
            myarray[(2*i)+2]='_';

        }
    }
    printf("The binary tree using array representation=\n");

    nodes=(size*size)-1;
    for(i=0;i<nodes;i++){
        printf(" %c\t",myarray[i]);
    }
    printf("\n");
    return 0;
}

/*
Enter the total height of the binary tree:2
Enter the Root Element:A

Enter _ to represent Free space
Enter the Left child of  A :B
Enter the Right child of  A :C
Enter the Left child of  B :_
Enter the Right child of  B :D
Enter the Left child of  C :E
Enter the Right child of  C :_
The binary tree using array representation=
 A	 B	 C	 _	 D	 E	 _
*/
