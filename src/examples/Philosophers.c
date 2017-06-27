#include <stdio.h>
#include <syscall.h>

int
main(void)
{
	semarray(1);
	seminit(0,3);

	int pid[5];
	pid[0] = exec("DiningPhil 1");
	pid[1] = exec("DiningPhil 2");
	pid[2] = exec("DiningPhil 3");
	pid[3] = exec("DiningPhil 4");
	pid[4] = exec("DiningPhil 5");

	wait(pid[0]);
	wait(pid[1]);
	wait(pid[2]);
	wait(pid[3]);
	wait(pid[4]);

	return 0;
}


