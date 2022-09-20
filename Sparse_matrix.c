#include <stdio.h>

void read_matrix(int a[10][10], int row, int column);
void create_sparse(int a[10][10], int row, int column, int b[10][3]);
void print_sparse(int b[10][3]);

int main(){
    int a[10][10], b[10][3], row, column;
    printf("Enter the size of matrix (rows, columns) : ");
    scanf("%d %d", &row, &column);
    read_matrix(a, row, column);
    create_sparse(a, row, column, b);
    print_sparse(b);
}

void read_matrix(int a[10][10], int row, int column){
    printf("\nEnter the elements of the matrix : \n");
    for(int i=0; i<row; i++){
        for(int j=0; j<row; j++){
            printf("[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void create_sparse(int a[10][10], int row, int column, int b[10][3]){
    int k = 1;
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

void print_sparse(int b[10][3]){
    int row = b[0][2];
    printf("\nSparse form - list of 3 triples\n\n");
    printf("ROW   COLUMN   VALUE\n");
    for(int i=0; i<=row; i++){
        printf("%d\t %d\t %d\n", b[i][0], b[i][1], b[i][2]);
    }
}