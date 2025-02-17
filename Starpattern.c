#include <stdio.h>  
void main()  
{  
    int n=5;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(i%2==0){
                printf("@ ");
            }
            else{
                printf("* ");
            }
            
        }
        printf("\n");
    }
}