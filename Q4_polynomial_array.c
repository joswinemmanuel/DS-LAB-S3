#include <stdio.h>

struct Polynomial {
	int expo;
	int coeff;
};

void create_poly(struct Polynomial P[], int terms);
void display_poly(struct Polynomial P[], int terms);

int main(){
	int terms;
	printf("Enter the number of terms : ");
	scanf("%d", &terms);
	struct Polynomial P[terms];
	create_poly(P, terms);
	display_poly(P, terms);
}

void create_poly(struct Polynomial P[], int terms){
	printf("\nEnter the largest exponent and it's coefficient first\n");
	for(int i=0; i<terms; i++){
		printf("Enter coefficient %d : ", i+1);
		scanf("%d", &P[i].coeff);
		printf("   Enter exponent %d : ", i+1);
		scanf("%d", &P[i].expo);
	}
}

void display_poly(struct Polynomial P[], int terms){
	printf("\nThe corresponding polynomial is\n");
	for(int i=0; i<terms-1; i++){
		printf("%d(x^%d) + ", P[i].coeff, P[i].expo);
	}
	printf("%d(x^%d)\n", P[terms-1].coeff, P[terms-1].expo);
}

/*
Enter the number of terms : 5

Enter the largest exponent and it's coefficient first
Enter coefficient 1 : 9
   Enter exponent 1 : 6
Enter coefficient 2 : 10
   Enter exponent 2 : 5
Enter coefficient 3 : 1
   Enter exponent 3 : 4
Enter coefficient 4 : 2
   Enter exponent 4 : 2
Enter coefficient 5 : 3
   Enter exponent 5 : 0

The corresponding polynomial is
9(x^6) + 10(x^5) + 1(x^4) + 2(x^2) + 3(x^0)
*/