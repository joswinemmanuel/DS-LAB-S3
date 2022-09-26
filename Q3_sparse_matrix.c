#include <stdio.h>

void read_matrix(int a[10][10], int row, int column);
void create_sparse(int a[10][10], int b[50][3], int row, int column);
void display_sparse(int b[50][3]);

int main(){
	int a[10][10], b[50][3], row, column;

	printf("Enter the number of rows of the matrix : ");
	scanf("%d", &row);
	printf("Enter the number of columns of the matrix : ");
	scanf("%d", &column);

	read_matrix(a, row, column);
	create_sparse(a, b, row, column);
	display_sparse(b);

}

void read_matrix(int a[10][10], int row, int column){
	for(int i=0; i<row; i++){
		for(int j=0; j<column; j++){
			printf("Enter value of a[%d][%d] : ", i, j);
			scanf("%d", &a[i][j]);
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
	printf("ROW   COLUMN   VALUE\n");
	for(int i=0; i<=b[0][2]; i++){
		printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
	}
}

/*
Enter the number of rows of the matrix : 4
Enter the number of columns of the matrix : 4
Enter value of a[0][0] : 0
Enter value of a[0][1] : 0
Enter value of a[0][2] : 9
Enter value of a[0][3] : 0
Enter value of a[1][0] : 0
Enter value of a[1][1] : 1
Enter value of a[1][2] : 0
Enter value of a[1][3] : 0
Enter value of a[2][0] : 5
Enter value of a[2][1] : 0
Enter value of a[2][2] : 9
Enter value of a[2][3] : 0
Enter value of a[3][0] : 8
Enter value of a[3][1] : 0
Enter value of a[3][2] : 0
Enter value of a[3][3] : 6
ROW   COLUMN   VALUE
4       4       6
0       2       9
1       1       1
2       0       5
2       2       9
3       0       8
3       3       6
*/
