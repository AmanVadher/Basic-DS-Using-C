#include<stdio.h>

void swap(int *,int *);
int main(){
    int a=10, b=20;
    printf("Before Swapping:\nA = %d & B = %d\n",a,b);
    swap(&a,&b);
    printf("After Swapping:\nA = %d & B = %d\n",a,b);
    return 0;
}

void swap(int *x, int *y){
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}