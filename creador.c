#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "creador.h"
#include <sys/shm.h>
#include <sys/ipc.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

int main(int argc, char* argv[])
{
  int shmid;
  char* addr1;
  key_t key;
  shmid = shmget(1077,sizeof(struct buffer),IPC_CREAT|SHM_R|SHM_W);
  printf("shmid = %d",shmid);
  addr1 = shmat(shmid,0,0);
  printf("\nIPC SHARED MEMORY");
  //copying your structure at the shared location.
  
  struct buffer myObj;
  myObj.testMessage = "message";
  
  memcpy(addr1,&myObj,sizeof(myObj));
  printf("\nMESSAGE STORED");
    
}

