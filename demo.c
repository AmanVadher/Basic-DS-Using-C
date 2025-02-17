#include<unistd.h>
#include<sys/types.h>
#include <stdio.h>
void main()
{
    int pid=0;
    // pid = fork();
    if (pid == 0)
    {
        printf("Child Process");
    }
    else
    {
        // wait(NULL);
        printf("Perent Process");
    }
    printf("\n Hello %d",getpid());
}