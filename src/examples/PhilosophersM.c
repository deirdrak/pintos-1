#include <stdio.h>
#include <syscall.h>

int
main(void)
{
	lockarray(1);
	lock_init(0);

	int pid[5];
	pid[0] = exec("DiningPhilM 1");
	pid[1] = exec("DiningPhilM 2");
	pid[2] = exec("DiningPhilM 3");
	pid[3] = exec("DiningPhilM 4");
	pid[4] = exec("DiningPhilM 5");

	wait(pid[0]);
	wait(pid[1]);
	wait(pid[2]);
	wait(pid[3]);
	wait(pid[4]);

	return 0;
}


