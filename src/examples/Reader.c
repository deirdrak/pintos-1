#include <stdio.h>
#include <syscall.h>
#include <random.h>

int
main(int argc, char * argv[])
{   
    int j = atoi(argv[1]);
    int i = 0;
    int read_count = 0;
		int waitTime = 10000;

		while(i<1000)
		{
		  sem_wait(1); 

			read_count++; 
			if (read_count == 1)
				sem_wait(0);
			sem_post(1);

			printf("Reader %d is reading data...\n",j);
			
			sem_wait(1); 
		
			read_count--; 
			if (read_count == 0)
				sem_post(1);
			sem_post(0);
		
			int x=random_ulong()/waitTime;;
			while(x>0)
			{
					x--;		
			}	
		
			i++;
		}
    return 0;
}
