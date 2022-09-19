#include <stdio.h>

struct Polynomial {
    float coeff;
    int expo;
};

int main(){
    struct Polynomial X1[3] = {{7, 4}, {5, 2}, {3, 1}};
    struct Polynomial X2[3] = {{5, 3}, {3, 1}, {-8, 0}};
    struct Polynomial X3[5];
    int i=0, j=0, k=0;
    while(i<3 && j<3){
        if(X1[i].expo == X2[j].expo){
            X3[k].expo = X1[i].expo;
            X3[k].coeff = X1[i].coeff + X2[j].coeff;
            i++;
            j++;
            k++;
        } else if(X1[i].expo > X2[j].expo){
            X3[k].expo = X1[i].expo;
            X3[k].coeff = X1[i].coeff;
            i++;
            k++;
        } else if(X1[i].expo < X2[j].expo){
            X3[k].expo = X2[j].expo;
            X3[k].coeff = X2[j].coeff;
            j++;
            k++;
        }
    }

    while(j < 3){
        X3[k].expo = X2[j].expo;
        X3[k].coeff = X2[j].coeff;
        j++;
        k++;
    }

    while(i < 3){
        X3[k].expo = X1[i].expo;
        X3[k].coeff = X1[i].coeff;
        i++;
        k++;
    }

    printf("%f %d\n", X3[0].coeff, X3[0].expo);
    printf("%f %d\n", X3[1].coeff, X3[1].expo);
    printf("%f %d\n", X3[2].coeff, X3[2].expo);
    printf("%f %d\n", X3[3].coeff, X3[3].expo);
    printf("%f %d\n", X3[4].coeff, X3[4].expo);
}