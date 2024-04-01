#include <stdio.h>
#include <stdlib.h>
#define MAX_DEGREE 100

struct polynomial {
	unsigned int high_power;
	int coeff_array[MAX_DEGREE+1];
};

typedef struct polynomial *POLYNOMIAL;

void zero_polynomial(POLYNOMIAL poly){
	poly->high_power = 0;
	for (int i = 0;i<=MAX_DEGREE;i++)
		poly->coeff_array[i] = 0;
}

unsigned int max(unsigned int a, unsigned int b){
	return a>b?a:b;
}

void sum_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_sum){
	zero_polynomial(poly_sum);
	poly_sum->high_power = max(poly1->high_power,poly2->high_power);
	for (int i=0;i<=poly_sum->high_power;i++)
		poly_sum->coeff_array[i] = poly1->coeff_array[i]+poly2->coeff_array[i];
}

void display_polynomial(POLYNOMIAL poly){
	for (int i=poly->high_power;i>=0;i--){		
		if (poly->coeff_array[i]==0)
			continue;
		if (poly->coeff_array[i]<0){
			if (i!=poly->high_power)
				printf(" - ");
			else
				printf("-");
		} else {
			if (i!=poly->high_power)
				printf(" + ");
		}
		
		if (abs(poly->coeff_array[i])!=1)
			printf("%d",abs(poly->coeff_array[i]));
		if (i!=0)
			printf("x");
		if (i>1)
			printf("^%d",i);
	}
	printf("\n");
}

void mult_polynomial(POLYNOMIAL poly1, POLYNOMIAL poly2, POLYNOMIAL poly_prod){
	zero_polynomial(poly_prod);
	poly_prod->high_power = poly1->high_power+poly2->high_power;
	for (int i=0;i<=poly1->high_power;i++)
		for (int j=0;j<=poly2->high_power;j++)
			poly_prod->coeff_array[i+j] += poly1->coeff_array[i]*poly2->coeff_array[j];
}

int main(){
	POLYNOMIAL poly1 = (polynomial*)malloc(sizeof(struct polynomial));
	POLYNOMIAL poly2 = (polynomial*)malloc(sizeof(struct polynomial));	
	POLYNOMIAL poly_sum = (polynomial*)malloc(sizeof(struct polynomial));
	POLYNOMIAL poly_prod = (polynomial*)malloc(sizeof(struct polynomial));
	
	zero_polynomial(poly1);
	zero_polynomial(poly2);
	
	poly1->high_power = 3;
	poly1->coeff_array[0] = 7; poly1->coeff_array[1] = 0;
	poly1->coeff_array[2] = 4; poly1->coeff_array[3] = 10;
	
	poly2->high_power = 2;
	poly2->coeff_array[0] = 5; poly2->coeff_array[1] = -6;
	poly2->coeff_array[2] = -1;
	
	display_polynomial(poly1);
	display_polynomial(poly2);
	
	sum_polynomial(poly1,poly2,poly_sum);
	mult_polynomial(poly1,poly2,poly_prod);
	
	printf("SUM:");
	display_polynomial(poly_sum);
	printf("MULTIPLY:");
	display_polynomial(poly_prod);
	
	return 0;
}