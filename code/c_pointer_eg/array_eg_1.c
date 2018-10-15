#include<stdio.h>
#include<stdlib.h>

int main(void){
  
  int i;
  double *pointer_1;
  
  pointer_1 = malloc(6 * sizeof(double));
  
  *pointer_1       = 3;
  *(pointer_1 + 1) = 5;
  *(pointer_1 + 2) = 4;
  *(pointer_1 + 3) = 1;
  *(pointer_1 + 4) = 7;
  *(pointer_1 + 5) = 6;
  
  for(i = 0; i < 6; i++){
    printf("%f\n", *(pointer_1 + i));
  }
  
  free(pointer_1);
  
  return 0;
}