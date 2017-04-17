#include<stdio.h>

int main(void){
    
    int variable_1, *ptr_variable_1;
    
    variable_1     = 3;
    ptr_variable_1 = &variable_1;
    
    printf("Value of variable_1 is %d \n", variable_1);
    printf("Address of variable_1 is %p \n", &variable_1);
    printf("Value of ptr_variable_1 is %p \n", ptr_variable_1);
    
    return 0;
}