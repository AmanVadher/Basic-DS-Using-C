#include<stdio.h>
#include<stdlib.h>

void main(){
   int n,i;
   int *a;
   printf("Enter the number of elements in the array: ");
   scanf("%d",&n);
   a = (int *)malloc(n * (sizeof(int)));
   printf("Enter %d numbers:\n",n);
   for( i=0 ; i < n ; i++ ) {
      scanf("%d",&a[i]);
   }
   printf("The numbers entered are: ");
   for( i=0 ; i < n ; i++ ) {
      printf("%d ",a[i]);
   }
}
