#include <stdio.h>
#include <syscall.h>

int main(int argc, char* argv[])
{  
	int num=atoi(argv[1]); 
    int i = 0;
    while(i < 1000)
    {
       sem_wait(0);
       printf("Producer %d produced 1 pizza!!\n", num);
       sem_post(1);
       i++;
    }

    return 0;
}
