#include<stdio.h>

int swap(int,int);
int main(){
    int a=10, b=20;
    printf("Before Swapping:\nA = %d & B = %d\n",a,b);
    swap(a,b);
    printf("After Swapping:\nA = %d & B = %d\n",b,a);
    return 0;
}

int swap(int x, int y){
    int temp;
    temp = x;
    x = y;
    y = temp;
    return x,y;
}