#include <stdio.h>
#include <syscall.h>
#include <random.h>

int
main(int argc, char * argv[])
{
    int currentPhilosopher = atoi(argv[1]);

    int value = 0;
    int waitTime = 10000;
    int thinking = 0;
    
    int i = 0;
    while(i < 1000)
    {
        if(!thinking)
        {
            sem_wait(0);
            printf("Philosopher %d is eating...\n", currentPhilosopher);           

            value = random_ulong()/waitTime;
            while(value > 0)
            {   
                value--;
            }

            sem_post(0);
            printf("Philosopher %d is done eating...\n", currentPhilosopher);
            value = 0;
            thinking = 1;
        }
        else
        {
            
            printf("Philosopher %d is thinking...\n",currentPhilosopher);  
            value =(random_ulong()/waitTime)*5;
            while(value > 0)
            {   
                value--;
            }
          
            thinking = 0;
            value = 0;
        }
        i++;
    }
    
    return 0;
}
