#include <stdio.h>
#include <stdlib.h>

struct matrix{
	float** mat;
	int rows;
	int cols;
};

void addElements(struct matrix *m, int matrixNum);
void multiplyMatrices(struct matrix mat1, struct matrix mat2);
void deallocate(struct matrix *m);

int main()
{	
	char input[4];
	struct matrix m1, m2;
	printf("Enter the dimensions of the first matrix: ");
	scanf("%s", input);
	m1.rows = input[0] - '0';
	m1.cols = input[2] - '0';
	printf("Enter the dimensions of the second matrix: ");
	scanf("%s", input);
        m2.rows = input[0] - '0';
        m2.cols = input[2] - '0';

	addElements(&m1, 1);
	addElements(&m2, 2);
	multiplyMatrices(m1,m2);

	return 0;
}

void addElements(struct matrix *m, int matrixNum)
{	
	int i,j,val;

	m->mat = malloc(m->rows * sizeof(float));
	printf("Enter the elements of matrix (%d): ",matrixNum);
	

	for(i = 0; i < m->rows; i++)
		*(m->mat+i) = malloc(m->cols * sizeof(float));

	for(i = 0; i < m->rows; i++)
	{
		for(j=0; j < m->cols; j++)
		{
			scanf("%d", &val);
			*(*(m->mat+i)+j) = val;
		}
	}
	
	for(i = 0; i < m->rows; i++)
	{
		for(j=0; j < m->cols; j++)
		{
			val = (int)m->mat[i][j];
		}
	}

	return;	
}

void multiplyMatrices(struct matrix mat1, struct matrix mat2)
{
	int i,j,val,k=0,z=0,total=0;
	struct matrix pMatrix;
	pMatrix.mat = malloc(mat1.rows * sizeof(float));
	
	for(i = 0; i < mat1.rows; i++)
		*(pMatrix.mat+i) = malloc(mat2.cols * sizeof(float));

	for(i=0; i < mat1.rows; i++)
	{
		z = 0;
		while(z < mat2.cols)
		{
			for(j=0; j < mat1.cols; j++)
			{
				val = (int)*(*(mat1.mat+i)+j) * (int)*(*(mat2.mat+j)+z);
                        	total = total + val;
			}
			
			z++;
			*(*(pMatrix.mat+i)+k) = total;
               		total =0;
               		k++;

	                if(k==mat2.cols)
				k = 0;
        	}

	}

	for(i = 0; i < mat1.rows; i++)
	{
		for(j=0; j < mat2.cols; j++)
		{
			printf("%d\t", (int)*(*(pMatrix.mat+i)+j));
		}
		printf("\n");
	}

	deallocate(&mat1);
	deallocate(&mat2);

	return;
}

void deallocate(struct matrix *m)
{
	int i=0;
	for(i=0; i< m->rows; i++)
		free(m->mat[i]);
	free(m->mat);
}


