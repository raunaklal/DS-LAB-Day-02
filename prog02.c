//Home Assignment
//Day02 Prog02
//Write a Program to add two matrices using Sparse representation. 
//Manipulation of data should be done in sparse format.
//Made by: -
//Raunak Kumar Lal
//2nd Year CSE 'C'
//Roll-1651158

//Header File
#include <stdio.h>
#include <stdlib.h>

int main()
{
	int **matrix1,**matrix2,**sparse1,**sparse2;
	int i,j,m1,n1,m2,n2;
	int count1=0,count2=0;
	//Asking the user for the size of the matrices
	do
	{
		printf("\nEnter number of rows and columns: ");
		scanf("%d%d",&m1,&n1);
		if(m1<0 || n1<0)
		printf("\nSorry...Enter Again ");
	}while(m1<0 || n1<0);

	do
	{
		printf("\nEnter number of rows and columns: ");
		scanf("%d%d",&m2,&n2);
		if(m2<0 || n2<0)
		printf("\nSorry...Enter Again ");
	}while(m2<0 || n2<0);

	//Checking whether addition is possible
	if(m1!=m2 || n1!=n2)
		printf("\nAddition Not Possible.");
	else
	{
		//Allocating space for the matrix
		matrix1=(int**)malloc(m1*sizeof(int*));
		matrix2=(int**)malloc(m2*sizeof(int*));
		for(i=0;i<m1;i++)
		{
			matrix1[i]=(int*)malloc(n1*sizeof(int));
			matrix2[i]=(int*)malloc(n1*sizeof(int));
		}

		//Input Data in Matrix 1
		printf("\nEnter elements of matrix1: \n");
		for(i=0;i<m1;i++)
			for(j=0;j<n1;j++)
			{
				scanf("%d",&matrix1[i][j]);
				if(matrix1[i][j]!=0)
					count1++;
			}

		//Input Data in Matrix 2
		printf("\nEnter elements of matrix2: \n");
		for(i=0;i<m2;i++)
			for(j=0;j<n2;j++)
			{
				scanf("%d",&matrix2[i][j]);
				if(matrix2[i][j]!=0)
					count2++;
			}
		if(((count1+1)*3 <= (m1*n1)) && ((count2+1)*3 <= (m2*n2)))
		{
			//Allocating space for the sparse matrices
			sparse1=(int**)malloc((count1+1)*sizeof(int*));
			sparse2=(int**)malloc((count2+1)*sizeof(int*));
			for(i=0;i<count1+1;i++)
				sparse1[i]=(int*)malloc(3*sizeof(int));
			for(i=0;i<count2+1;i++)
				sparse2[i]=(int*)malloc(3*sizeof(int));

			//Assign values of the first row in sparse matrix
			//sparse[0][0]=No. of rows
			//sparse[0][1]=No. of columns
			//sparse[0][2]=No. of non-zero elements

			sparse1[0][0]=m1; sparse1[0][1]=n1; sparse1[0][2]=count1;
			sparse2[0][0]=m2; sparse2[0][1]=n2; sparse2[0][2]=count2;
			//Assign values to the sparse matrix
			//sparse[c1][0]=index 'i'
			//sparse[c1][1]=index 'j'
			//sparse[c1][2]=value at index i,j
			int c1=1,c2=1;
			for(i=0;i<m1;i++)
				for(j=0;j<n1;j++)
				{
					if(matrix1[i][j]!=0)
					{
						sparse1[c1][0]=i;
						sparse1[c1][1]=j;
						sparse1[c1][2]=matrix1[i][j];
						c1++;
					}
					if(matrix2[i][j]!=0)
					{
						sparse2[c2][0]=i;
						sparse2[c2][1]=j;
						sparse2[c2][2]=matrix2[i][j];
						c2++;
					}
				}//for

			//Printing the two matrices
	    	printf("\nSparse Matrix 1 :\n");
			for(i=0;(i<count1+1);i++)
			{
				printf("\n");
				for(j=0;j<3;j++)
					printf("%4d",sparse1[i][j] );
			}
			printf("\n\nSparse Matrix 2 :\n\n");
			for(i=0;i<(count2+1);i++)
			{
				printf("\n");
		    	for(j=0;j<3;j++)
					printf("%4d",sparse2[i][j]);
			}

			//Adding the two matrices
			int sparse3[count1+count2+1][3];
			int tot1=sparse1[0][2];
			int tot2=sparse2[0][2];
			int k1 =1, k2 =1, k3 = 1;
			while ( k1 <= tot1 && k2 <= tot2)
			{
				if ( sparse1[k1][0] < sparse2[k2][0] )
				{
					sparse3[k3][0] = sparse1[k1][0];
					sparse3[k3][1] = sparse1[k1][1];
					sparse3[k3][2] = sparse1[k1][2];
					k3++;k1++;
				}
				else if ( sparse1[k1][0] > sparse2[k2][0] )
					{
						sparse3[k3][0] = sparse2[k2][0];
						sparse3[k3][1] = sparse2[k2][1];
						sparse3[k3][2] = sparse2[k2][2];
						k3++;k2++;
					}
					else if ( sparse1[k1][0] == sparse2[k2][0] )
					{
						if ( sparse1[k1][1] < sparse2[k2][1] )
						{
							sparse3[k3][0] = sparse1[k1][0];
							sparse3[k3][1] = sparse1[k1][1];
							sparse3[k3][2] = sparse1[k1][2];
							k3++;k1++;
						}
						else if ( sparse1[k1][1] > sparse2[k2][1] )
						{
							sparse3[k3][0] = sparse2[k2][0];
							sparse3[k3][1] = sparse2[k2][1];
							sparse3[k3][2] = sparse2[k2][2];
							k3++;k2++;
						}
						else
						{
							sparse3[k3][0] = sparse2[k2][0];
							sparse3[k3][1] = sparse2[k2][1];
							sparse3[k3][2] = sparse1[k1][2] + sparse2[k2][2];
							k3++;k2++;k1++;
						}
					} // else
			} // while

			while ( k1 <=tot1 )
			{
				sparse3[k3][0] = sparse1[k1][0];
				sparse3[k3][1] = sparse1[k1][1];
				sparse3[k3][2] = sparse1[k1][2];
				k3++;k1++;
			} //while

			while ( k2 <= tot2 )
			{
				sparse3[k3][0] = sparse2[k2][0];
				sparse3[k3][1] = sparse2[k2][1];
				sparse3[k3][2] = sparse2[k2][2];
				k3++;k2++;
			} // while

			sparse3[0][0] = sparse1[0][0];
			sparse3[0][1] = sparse1[0][1];
			sparse3[0][2] = k3-1;

			printf("\nAddition Sparse Matrix: \n");
			for(i=0;i<k3;i++)
			{
				printf("\n");
				for(j=0;j<3;j++)
					printf("%4d ",sparse3[i][j]);
			}

			int sum[m1][n1];
			int c=1;
			printf("\nAddition Matrix :\n");
			
			for(i=0;i<m1;i++)
				for(j=0;j<n1;j++)
					sum[i][j]=0;
			while(c<k3)
			{
				sum[sparse3[c][0]][sparse3[c][1]]=sparse3[c][2];
				c++;
			}
			for(i=0;i<m1;i++)
			{
				printf("\n");
				for(j=0;j<n1;j++)
					printf("%4d",sum[i][j]);
			}
			//Freeing sparse matrices
			for(i=0;i<count1+1;i++)
				free(sparse1[i]);
			for(i=0;i<count2+1;i++)
				free(sparse2[i]);
			free(sparse1);
			free(sparse2);
		}//if
		else
			printf("\nNot Advantageous.\n");

		//Free space occupied by matrices
    	for(i=0;i<m1;i++)
    	{
        	free(matrix1[i]);
        	free(matrix2[i]);
    	}
    	free(matrix1);
    	free(matrix2);
	}//else
	return 0;
}