#include <stdio.h>
#include <syscall.h>
#include <random.h>

int main(int argc, char* argv[])
{
    int num=atoi(argv[1]);
    int i = 0;
    int waitTime=10000;

    while(i < 300)
    {
       lock_acquire(0);
       printf("Consumer %d ate 1 pizza!!\n", num);
       lock_release(0);

	int value = (random_ulong()/waitTime)*6;
       while(value > 0)
       {   
            value--;
       }

       i++;
    }
    return 0;
}
