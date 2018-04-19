#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "creador.h"
#include <sys/mman.h>
#include <semaphore.h>
#include <fcntl.h>

void *create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared other processes can access it, but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_ANONYMOUS | MAP_SHARED;
  printf("Inside create shared memory\n");
  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  // void *mmap(void *addr, size_t length, int prot, int flags,int fd, off_t offset);
  /*

    Prot : [PROT_EXEC  Pages may be executed.

            PROT_READ  Pages may be read.

            PROT_WRITE Pages may be written.

            PROT_NONE  Pages may not be accessed.]
    Flags : [MAP_SHARED , MAP_PRIVATE]

  */
  int shfd = shm_open("/somesharedmemname", O_RDWR|O_CREAT, 0750);
  if (shfd<0) { perror("shm_open"); exit(EXIT_FAILURE); };
  return mmap(NULL, size, protection, visibility, shfd, 0);
}
int main(int argc, char* argv[]) {
    Creador creador;
    for(int i=1; i<argc; i++)
    {
        if (strcmp("-b",argv[i]) == 0) creador.bufferName = argv[i+1];
        else if (strcmp("-s",argv[i]) == 0) creador.seconds = atoi(argv[i+1]);            
    }
    //while(1){
        char* parent_message = "hello";  // parent process will write this message
        char* child_message = "goodbye"; // child process will then write this one

        void* shmem = create_shared_memory(128);

        memcpy(shmem, parent_message, sizeof(parent_message));
        printf("Shared MEMORY %p \n", shmem);

        int pid = fork();

        if (pid == 0) {
            printf("Child read: %s\n", shmem);
            memcpy(shmem, child_message, sizeof(child_message));
            printf("Shared MEMORY %p \n", shmem);
            printf("Child wrote: %s\n", shmem);
        } else {
            printf("Parent read: %s\n", shmem);
            sleep(1);
            printf("After 1s, parent read: %s\n", shmem);
        }
    //}
}

// Initializes the variables used in the system
void initializeVars()
{
}

