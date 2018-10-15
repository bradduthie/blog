#include<stdio.h>
#include<stdlib.h>

int main(void){
  
  int row,  col;
  int row_number, col_number;
  double **array2D;
  
  row_number = 2;
  col_number = 3;
  
  array2D = malloc(row_number * sizeof(double *));
  for(row = 0; row < row_number; row++){
      *(array2D + row) = malloc(col_number * sizeof(double));
  }
  
  *(*(array2D + 0) + 0) = 3;
  *(*(array2D + 0) + 1) = 5;
  *(*(array2D + 0) + 2) = 4;
  *(*(array2D + 1) + 0) = 1;
  *(*(array2D + 1) + 1) = 7;
  *(*(array2D + 1) + 2) = 6;

  for(row = 0; row < row_number; row++){
    for(col = 0; col < col_number; col++){
      printf("%f\t", *(*(array2D + row) + col) );
    }
    printf("\n");
  }
  
  for(row = 0; row < row_number; row++){
      free(*(array2D + row));
  }
  free(array2D);
  
  return 0;
}