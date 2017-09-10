//Home Assignment
//Day02 Prog01
//Write a Program to multiply two polynomials using array. Minimize usage of //memory.
//Made by :-
//Raunak Kumar Lal
//2nd Year CSE 'C'
//Roll- 1651158

//Header Files
#include <stdio.h>

//Each term of the polynomial
typedef struct
{
	int coeff;
	int xpwr;
	int ypwr;
}node;
//Function used to delete a term from the array
int delete_term(node A[], int size, int index)
{
	int i;
	for(i=index;i<size-1;i++)
		A[i]=A[i+1];
	return (size-1);
}

int main()
{
	int t1,t2,a=0;
	printf("\nHow many terms do you want for polynomial 1?\t");
	scanf("%d",&t1);
	printf("\nHow many terms do you want for polynomial 2?\t");
	scanf("%d",&t2);

	node poly[t1+t2];
	node pdt[t1*t2];
	int i,j;

    //Taking the polynomial as input
	printf("\nPolynomial 1: ");
	for(i=0; i<t1; i++)
	{
		printf("\nTerm %d : ", ++a);
		printf("\n\nCoefficient: ");
		scanf("%d",&poly[i].coeff);

		printf("X-pwr: ");
		scanf("%d",&poly[i].xpwr);

		printf("Y-pwr: ");
		scanf("%d",&poly[i].ypwr);
	}
	printf("\nYour given Polynomial:\n\n");
	for(i=0;i<t1-1;i++)
        printf("( %dx^%d * y^%d ) + ",poly[i].coeff,poly[i].xpwr,poly[i].ypwr);
	printf("( %dx^%d * y^%d ) \n",poly[i].coeff,poly[i].xpwr,poly[i].ypwr);

    //Taking the polynomial as input
    a=0;
	printf("\nPolynomial 2: ");
	for(i=t1;i<t1+t2;i++)
	{
		printf("\nTerm %d : ", ++a);
		printf("\n\nCoefficient: ");
		scanf("%d",&poly[i].coeff);

		printf("X-pwr: ");
		scanf("%d",&poly[i].xpwr);

		printf("Y-pwr: ");
		scanf("%d",&poly[i].ypwr);
	}

	printf("\nYour given Polynomial:\n\n");
	for(i=t1;i<t1+t2-1;i++)
        printf("( %dx^%d * y^%d ) + ",poly[i].coeff,poly[i].xpwr,poly[i].ypwr);
	printf("( %dx^%d * y^%d ) \n",poly[i].coeff,poly[i].xpwr,poly[i].ypwr);

	int c = 0;
	for(i=0; i<t1; i++)
		for(j=t1; j<t1+t2; j++)
		{
			pdt[c].coeff=poly[i].coeff*poly[j].coeff;
			pdt[c].xpwr=poly[i].xpwr+poly[j].xpwr;
			pdt[c].ypwr=poly[i].ypwr+poly[j].ypwr;
			c++;
		}

	for(i=0;i<c-1;i++)
		for(j=i+1;j<c;j++)
		{
			if(pdt[i].xpwr == pdt[j].xpwr && pdt[i].ypwr == pdt[j].ypwr)
			{
				pdt[i].coeff=pdt[i].coeff+pdt[j].coeff;
				c=delete_term(pdt,c,j);
			}
		}

	printf("\nAnswer: \n");
	for(i=0;i<c-1;i++)
	{
		printf("( %dx^%d * y^%d ) + ",pdt[i].coeff,pdt[i].xpwr,pdt[i].ypwr);
	}
	printf("( %dx^%d * y^%d ) ",pdt[i].coeff,pdt[i].xpwr,pdt[i].ypwr);
	return 0;
}
