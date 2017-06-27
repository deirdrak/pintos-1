#include <stdio.h>
#include <syscall.h>

int main(int argc, char* argv[])
{
    int num=atoi(argv[1]);
    int i = 0;
    while(i < 1000)
    {
       sem_wait(1);
       printf("Consumer %d ate 1 pizza!!\n", num);
       sem_post(0);
       i++;
    }
    return 0;
}
