#include <stdio.h>
#include <syscall.h>


int main(void)
{

  int pid[4];

  semarray(2);
  seminit(0,8);//empty
  seminit(1,0);//full

  pid[0] = exec("Producer 1");
  pid[1] = exec("Producer 2");
  pid[2] = exec("Consumer 1");
  pid[3] = exec("Consumer 2");

  wait(pid[0]);
  wait(pid[1]);
  wait(pid[2]);
  wait(pid[3]);

  return 0;
}

