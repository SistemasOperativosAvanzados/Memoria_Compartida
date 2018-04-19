#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "creador.h"
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char* argv[])
{
  int shmid;
  char* addr1;
  FILE* fp;
  key_t key;

  struct buffer* myObj2;
  
  shmid = shmget(1077,sizeof(struct buffer),SHM_R|SHM_W);
  addr1 = shmat(shmid,0,0);
  myObj2 = (struct buffer*)malloc(sizeof(struct buffer)*1);
  if(shmid == -1)
    printf("\nShared memory error");
  //Retrieve the stored information, form the shared location.
  memcpy(myObj2,addr1,sizeof(struct buffer));
  printf("mensajillo: %s\n", myObj2->testMessage);
}
