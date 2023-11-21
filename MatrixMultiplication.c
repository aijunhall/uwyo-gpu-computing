#include<stdio.h>

int main()
{
  printf("Matrix Multiplication Program\n");
  printf("\n");


  // Hard Coded Matrix Creation
  int matrix1[3][2] = { 
    {3, 4},
    {7, 2},
    {5, 9}
  };
  int matrix2[2][3] = { 
    {3, 1, 5},
    {6, 9, 7}
  };
  int matrix3[3][3];

  // Display Matrixes
  printf("Matrix 1:\n");
  for (int i=0;i<3;i++) {
    for (int j=0;j<2;j++) {
      printf("%d\t", matrix1[i][j]);
    }
    printf("\n");
  }

  printf("Matrix 2:\n");
  for (int i=0;i<2;i++) {
    for (int j=0;j<3;j++) {
      printf("%d\t", matrix2[i][j]);
    }
    printf("\n");
  }

  // Multiplication Functionality
  printf("\nDo Matrix Multiplication\n\n");

  // Going through matrix3 which is known to be 3x3
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      
      // Initialize unknown value at 0 at first
      matrix3[i][j] = 0;

      for (int k=0;k<2;k++) {
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
  for (int i=0;i<3;i++) {
    for (int j=0;j<3;j++) {
      printf("%d\t", matrix3[i][j]);
    }
    printf("\n");
  }

  return 0;
}