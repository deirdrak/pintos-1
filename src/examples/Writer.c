#include <stdio.h>
#include <syscall.h>
#include <random.h>

int
main(int argc, char * argv[])
{
    int i = 0;
	int waitTime = 10000;
    
	while(i < 1300)
    {		
	
		int x=random_ulong()/waitTime;;
		while(x>0)
		{
			x--;		
		}	

		sem_wait(0); 	
		printf("Writing...\n");				
	

		printf("Done Writing...\n");		
		sem_post(0);

		i++;	
    }

    return 0;
}
