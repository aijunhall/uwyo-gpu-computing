#ifndef MATRIXFUNCTIONS
#define MATRIXFUNCTIONS

#include <stdio.h>
#include <stdlib.h>

// 2D Matrix Struct
extern struct Matrix {
  int rowCount;
  int columnCount;
  int **data;
};

/* 
  Get Matrix Dimension Values
  Return [matrix1Rows, matrix1Columns, matrix2Rows, matrix2Columns]
  matrix1Columns == matrix2Rows
*/
extern int* getMatrixDimensionValues();

/*
  Fill a Matrix Struct. 
  This will dynamically allocate memory based off the Specified Dimensions,
  then prompt for the Matrix's values
*/
extern void fillMatrix(struct Matrix* matrix, int rowCount, int columnCount);

// Display a Matrix by printing it to the cmd
extern void displayMatrix(struct Matrix* matrix);

/* 
  Multiple two matricies together
  multiplicandMatrix * multiplierMatrix = resultMatrix
  PREREQUISITE: the multiplicandMatrix's Column Count must equal the multiplierMatrix's Row Count,
  otherwise the returned matrix will be NULL
  Matrix 1 [A, B] * Maatrix 2 [C, D]
  assert B == C
*/
extern struct Matrix multiplyMatrices(struct Matrix* multiplicandMatrix, struct Matrix* multiplierMatrix);

#endif