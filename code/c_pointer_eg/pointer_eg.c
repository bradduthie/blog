#include<stdio.h>
#include<stdlib.h>

int main(void){

    int *array_1;
    int i;

    array_1 = malloc(10 * sizeof(int));

    printf("\n");
    for(i = 0; i < 10; i++){
        printf("%p\t", array_1 + i);
    }
    printf("\n");

    return 0;
}
