#include<stdio.h>
#include<stdlib.h>

int main(void){
  
  int i;
  double *array_1;
  
  array_1 = malloc(6 * sizeof(double));
  
  array_1[0] = 3;
  array_1[1] = 5;
  array_1[2] = 4;
  array_1[3] = 1;
  array_1[4] = 7;
  array_1[5] = 6;
  
  for(i = 0; i < 6; i++){
    printf("%f\n", array_1[i]);
  }
  
  free(array_1);
  
  return 0;
}