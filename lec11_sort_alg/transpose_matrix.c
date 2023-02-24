#include <stdio.h>
#define ROW 3
#define COL 4

// This function stores transpose of A[][] in B[][]
void transpose(int A[ROW][COL], int B[COL][ROW])
{
	int i, j;
	for (i = 0; i < COL; i++)
		for (j = 0; j < ROW; j++)
			B[i][j] = A[j][i];
}

void transpose_ptr(int *A, int *B)
{
	int i, j;
	for (i = 0; i < COL; i++)
		for (j = 0; j < ROW; j++)
			//B[i][j] = A[j][i];
		B[i*ROW+j]=A[j*COL+i];		
}

int main()
{
	int A[ROW][COL] = { {1, 1, 1, 1},
					    {2, 2, 2, 2},
					    {3, 3, 3, 3}};

	// Note dimensions of B[][]
	int B[COL][ROW], i, j;
	
	int B_p[COL][ROW];
	
	transpose(A, B);

	printf("Result matrix is \n");
	for (i = 0; i < COL; i++)
	{
		for (j = 0; j < ROW; j++)
		printf("%d ", B[i][j]);
		printf("\n");
	}

   transpose_ptr(A, B_p);
   
   printf("Result matrix is \n");
	for (i = 0; i < COL; i++)
	{
		for (j = 0; j < ROW; j++)
		printf("%d ", B_p[i][j]);
		printf("\n");
	}

	return 0;
}
