#include <stdio.h>
#include <syscall.h>


int main(void)
{

  int pid[4];

  lockarray(1);
  lock_init(0);//empty  

  pid[0] = exec("ProducerM 1");
  pid[1] = exec("ProducerM 2");
  pid[2] = exec("ConsumerM 1");
  pid[3] = exec("ConsumerM 2");

  wait(pid[0]);
  wait(pid[1]);
  wait(pid[2]);
  wait(pid[3]);

  return 0;
}

