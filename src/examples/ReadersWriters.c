//#include <pthread.h>
#include <stdio.h>
#include <synch.h>
//#include <unistd.h>
//#include <stdlib.h> 

//#include <errno.h>
//#include <string.h>

//sem_t rw_mutex, mutex;
struct semaphore rw_mutex, mutex;

int read_count=0;
char data;

static void *writer()
{
	do 
	{ 
		//sleep(3);
		//printf("Entering writer...\n");		
		sem_wait(&rw_mutex); 	
		printf("Writing...\n");				
		//strcpy(data,"HOLA");
		data='W';
		//printf("I'm writing data %s",data);
		printf("Done Writing...\n");		
		sem_post(&rw_mutex);
		
	} while (1);
}

static void *reader()
{
	do 
	{ 
		//printf("Entering reader...\n");		
		sem_wait(&mutex); 

		read_count++; 
		if (read_count == 1)
			sem_wait(&rw_mutex);
		sem_post(&mutex);

		printf("I'm reading data> %s\n",data);
		//printf("Reading...\n");
		sem_wait(&mutex); 
		
		read_count--; 
		if (read_count == 0)
			sem_post(&rw_mutex);
		sem_post(&mutex);
		//sleep(1);
	} while (1);
}

int main()
{
	printf("Inicializando semaforos...\n");
	
	sem_init(&rw_mutex,1);
	//sem_init(&mutex,0);
	//sem_init(&rw_mutex,0,1);
	//sem_init(&mutex,0,1);

/*	printf("Creando hilos...\n");

	pthread_t tid[2];
	int y, s;

	s=pthread_create(&tid[0], NULL, writer,NULL);
	if (s != 0)
		perror("pthread_create");
		
	s = pthread_create(&tid[1], NULL, reader,NULL);	
	if (s != 0)
		perror("pthread_create");

	for(y=0;y<2;y++)
	{
		s = pthread_join(tid[y], NULL);

		if (s != 0)
			perror("pthread_join");
	}*/

	return 0;
}
