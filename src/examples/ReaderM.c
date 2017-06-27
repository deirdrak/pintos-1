#include <stdio.h>
#include <syscall.h>
#include <random.h>

int
main(int argc, char * argv[])
{   
    int j = atoi(argv[1]);
    int i = 0;
		int waitTime = 10000;

		while(i<1000)
		{
		  lock_acquire(0); 

			printf("Reader %d is reading data...\n",j);
			
			lock_release(0);
		
			int x=random_ulong()/waitTime;
			while(x>0)
			{
					x--;		
			}	
		
			i++;
		}
    return 0;
}
