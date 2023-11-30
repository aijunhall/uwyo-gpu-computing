#include "MatrixFunctions.h"

/* 
  Get Matrix Dimension Values
  Return [matrix1Rows, matrix1Columns, matrix2Rows, matrix2Columns]
  matrix1Columns == matrix2Rows
*/
int* getMatrixDimensionValues() {
  static int arr[4];

  // Input
  printf("First Matrix's Row Count: ");
  scanf("%d", &arr[0]);
  
  printf("First Matrix's Column Count: ");
  scanf("%d", &arr[1]);

  printf("SET First Matrix's Column Count = Second Matrix's Row Count\n");
  arr[2] = arr[1];
  
  printf("Second Matrix's Column Count: ");
  scanf("%d", &arr[3]);

  return arr;
}

/*
  Fill a Matrix Struct. 
  This will dynamically allocate memory based off the Specified Dimensions,
  then prompt for the Matrix's values
*/
void fillMatrix(struct Matrix* matrix, int rowCount, int columnCount) {
  matrix->rowCount = rowCount;
  matrix->columnCount = columnCount;
  
  int **data = malloc(rowCount*sizeof(int*));
  for (int i=0;i<rowCount;i++) {
    data = malloc(columnCount*sizeof(int*));
  }

  for (int i=0;i<rowCount;i++) {
    for (int j=0;j<columnCount;j++) {
      int input;
      printf("Matrix1 value at {%d, %d}: ", i, j);
      scanf("%d", &input);
      data[i][j] = input;
    }
  }

  matrix->data = data;
}

// Display a Matrix by printing it to the cmd
void displayMatrix(struct Matrix* matrix) {
  int rowCount = matrix->rowCount;
  int columnCount = matrix->columnCount;
  int** data = matrix->data;

  printf("---------------------------------");
  for (int i=0;i<rowCount;i++) {
    for (int j=0;j<columnCount;j++) {
      printf("%d\t", data[i][j]);
    }
    printf("\n");
  }
  printf("---------------------------------");
}

/* 
  Multiple two matricies together
  multiplicandMatrix * multiplierMatrix = resultMatrix
  PREREQUISITE: the multiplicandMatrix's Column Count must equal the multiplierMatrix's Row Count,
  otherwise the returned matrix will be NULL
  Matrix 1 [A, B] * Maatrix 2 [C, D]
  assert B == C
*/
struct Matrix multiplyMatrices(struct Matrix* multiplicand, struct Matrix* multiplier) {
  int multiplicandRowCount = multiplicand->rowCount;        // Matrix 1 Rows
  int multiplicandColumnCount = multiplicand->columnCount;  // Matrix 1 Columns
  int multiplierRowCount = multiplier->rowCount;            // Matrix 2 Rows   
  int multiplierColumnCount = multiplicand->columnCount;    // Matrix 2 Columns       

  struct Matrix* result; 

  // First check prerequisite
  // Matrix 1 Columns = Matrix 2 Rows
  if (multiplicandColumnCount != multiplierRowCount) {
    result->data = NULL;
    return *result;
  }

  // Fill out resulting Matrix attributes & dynamically allocate memory
  result->rowCount = multiplierRowCount;
  result->columnCount = multiplierColumnCount;

  int **data = malloc(multiplierRowCount*sizeof(int*));

  for (int i=0;i<multiplierColumnCount;i++) {
    data[i] = malloc(multiplierColumnCount*sizeof(int*));
  }

  // Do Matrix Multiplication
  for (int i=0;i<multiplicandRowCount;i++) {
    for (int j=0;j<multiplierColumnCount;j++) {
      
      // Initialize unknown value at 0 at first
      data[i][j] = 0;

      for (int k=0;k<multiplierRowCount;k++) {
        // i => 0 -> matrix1 row count
        // j => 0 -> matrix2 column count
        // k => 0 -> matrix2 row count

        int multiplicandNumber = multiplicand->data[i][k]; // i => VERTICAL INDEXING; k => HORIZONTAL INDEXING; Going down, then across;
        int multiplierNumber = multiplier->data[k][j];   // k => VERTICAL INDEXING; j => HORIZONTAL INDEXING; Going across, then down;
        
        data[i][j] += multiplicandNumber * multiplierNumber; 
      }
    }

    result->data = data;
    return *result;
  }
}