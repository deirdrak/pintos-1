#include <stdio.h>
#include <syscall.h>

int
main(void)
{
    semarray(2);
    
    seminit(0,1);//rw_mutex    
    seminit(1,1);//mutex

    int pid[2];
    pid[0] = exec("Writer 1");
    pid[1] = exec("Reader 1");

    wait(pid[0]);
    wait(pid[1]);

    return 0;
}
