#include <stdio.h>

void read_matrix(int a[10][10], int row, int column);
void add_matrix(int a[10][10], int b[10][10], int c[10][10], int row, int column);
void create_sparse(int a[10][10], int b[50][3], int row, int column);
void display_sparse(int b[50][3]);

int main(){
	int a[10][10], b[10][10], c[10][10], s[50][3], row, column;

	printf("Enter the number of rows of the matrix : ");
	scanf("%d", &row);
	printf("Enter the number of columns of the matrix : ");
	scanf("%d", &column);

    printf("\nEnter the elements of matrix A \n");
	read_matrix(a, row, column);
    printf("\nEnter the elements of matrix B \n");
    read_matrix(b, row, column);

    add_matrix(a, b, c, row, column);

	create_sparse(c, s, row, column);
	display_sparse(s);

}

void read_matrix(int a[10][10], int row, int column){
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			printf("Enter value of index [%d][%d] : ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
}

void add_matrix(int a[10][10], int b[10][10], int c[10][10], int row, int column) {
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void create_sparse(int a[10][10], int b[50][3], int row, int column){
	int k=1;
	b[0][0] = row;
	b[0][1] = column;
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			if(a[i][j] != 0){
				b[k][0] = i;
				b[k][1] = j;
				b[k][2] = a[i][j];
				k++;
			}
		}
	}
	b[0][2] = k-1;
}

void display_sparse(int b[50][3]){
	printf("\nROW   COLUMN   VALUE\n");
	for(int i=0; i<=b[0][2]; i++){
		printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
	}
}

/*
Enter the number of rows of the matrix : 2
Enter the number of columns of the matrix : 2

Enter the elements of matrix A 
Enter value of index [0][0] : 1
Enter value of index [0][1] : 0
Enter value of index [1][0] : 0
Enter value of index [1][1] : 3

Enter the elements of matrix B 
Enter value of index [0][0] : 2
Enter value of index [0][1] : 4
Enter value of index [1][0] : 0
Enter value of index [1][1] : 1

ROW   COLUMN   VALUE
2       2       3
0       0       3
0       1       4
1       1       4
*/