#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "creador.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)
               
void* create_shared_memory(size_t size) {
  // Our memory buffer will be readable and writable:
  int protection = PROT_READ | PROT_WRITE;

  // The buffer will be shared (meaning other processes can access it), but
  // anonymous (meaning third-party processes cannot obtain an address for it),
  // so only this process and its children will be able to use it:
  int visibility = MAP_ANONYMOUS | MAP_SHARED;

  // The remaining parameters to `mmap()` are not important for this use case,
  // but the manpage for `mmap` explains their purpose.
  return mmap(NULL, size, protection, visibility, 0, 0);
}

// Main method for the productor.c file
int main(int argc, char* argv[])
{
    char* parent_message = "hello";  // parent process will write this message
    char* child_message = "goodbye"; // child process will then write this one

    void* shmem = create_shared_memory(128);

    memcpy(shmem, parent_message, sizeof(parent_message));
    while(1);

}

// Initializes the variables used in the system
void initializeVars()
{
}
