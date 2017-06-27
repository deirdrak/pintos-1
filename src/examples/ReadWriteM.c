#include <stdio.h>
#include <syscall.h>

int
main(void)
{
	lockarray(1);
	lock_init(0);    

    int pid[2];
    pid[0] = exec("WriterM 1");
    pid[1] = exec("ReaderM 1");

    wait(pid[0]);
    wait(pid[1]);

    return 0;
}
