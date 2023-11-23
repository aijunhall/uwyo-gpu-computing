#include <stdio.h>
#include <stdlib.h>

int main()
{
  printf("Matrix Multiplication Program\n\n");

  int matrix1Rows, matrix1Columns;
  int matrix2Rows, matrix2Columns;

  // Get Matrix Dimension Input
  printf("Matrix1 Rows: ");
  scanf("%d", &matrix1Rows);
  
  printf("Matrix1 Columns: ");
  scanf("%d", &matrix1Columns);

  printf("Set Matrix1 Columns = Matrix2 Rows\n");
  matrix2Rows = matrix1Columns;
  
  printf("Matrix2 Columns: ");
  scanf("%d", &matrix2Columns);

  // Dynamically allocate matrix array memory
  int **matrix1 = malloc(matrix1Rows*sizeof(int*));
  int **matrix2 = malloc(matrix2Rows*sizeof(int*));
  int **matrix3 = malloc(matrix2Rows*sizeof(int*));

  for (int i=0;i<matrix1Rows;i++) {
    matrix1[i] = malloc(matrix1Columns*sizeof(int*));
  }

  for (int i=0;i<matrix2Rows;i++) {
    matrix2[i] = malloc(matrix2Columns*sizeof(int*));
  }

  for (int i=0;i<matrix2Columns;i++) {
    matrix3[i] = malloc(matrix2Columns*sizeof(int*));
  }

  // Get Matrix Array Inputs
  for (int i=0;i<matrix1Rows;i++) {
    for (int j=0;j<matrix1Columns;j++) {
      int input;
      printf("Matrix1 value at {%d, %d}: ", i, j);
      scanf("%d", &input);
      matrix1[i][j] = input;
    }
  }

  for (int i=0;i<matrix2Rows;i++) {
    for (int j=0;j<matrix2Columns;j++) {
      int input;
      printf("Matrix2 value at {%d, %d}: ", i, j);
      scanf("%d", &input);
      matrix2[i][j] = input;
    }
  }

  // Display Matrixes
  printf("Matrix 1:\n");
  for (int i=0;i<matrix1Rows;i++) {
    for (int j=0;j<matrix1Columns;j++) {
      printf("%d\t", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("Matrix 2:\n");
  for (int i=0;i<matrix2Rows;i++) {
    for (int j=0;j<matrix2Columns;j++) {
      printf("%d\t", matrix2[i][j]);
    }
    printf("\n");
  }

  // Multiplication Functionality
  printf("\nDo Matrix Multiplication\n\n");

  for (int i=0;i<matrix1Rows;i++) {
    for (int j=0;j<matrix2Columns;j++) {
      
      // Initialize unknown value at 0 at first
      matrix3[i][j] = 0;

      for (int k=0;k<matrix2Rows;k++) {
        // i => 0 -> matrix1_row_count
        // j => 0 -> matrix2_column_count
        // k => 0 -> matrix2_row_count

        int multiplicand = matrix1[i][k]; // i => VERTICAL INDEXING; k => HORIZONTAL INDEXING; Going down, then across;
        int multiplier = matrix2[k][j];   // k => VERTICAL INDEXING; j => HORIZONTAL INDEXING; Going across, then down;
        
        matrix3[i][j] += multiplicand * multiplier; 
      }
    }
  }

  printf("Matrix 3 (Result):\n");
  for (int i=0;i<matrix1Rows;i++) {
    for (int j=0;j<matrix2Columns;j++) {
      printf("%d\t", matrix3[i][j]);
    }
    printf("\n");
  }

  return 0;
}