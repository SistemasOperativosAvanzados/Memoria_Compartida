#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "creador.h"
#include <sys/shm.h>
#include <sys/ipc.h>

int main(int argc, char* argv[])
{

    int       shm_id;
    key_t     mem_key;
    int       *shm_ptr;

    mem_key = ftok(".", 'a');
    shm_id = shmget(mem_key, 4*sizeof(int), 0666);
    if (shm_id < 0) {
        printf("*** shmget error (client) ***\n");
        exit(1);
    }
    
    printf("Id de la memoria compartida en el consumidor/productor: %d\n", shm_id);

    shm_ptr = (int *) shmat(shm_id, NULL, 0);
    if ((int) shm_ptr == -1) { /* attach */
        printf("*** shmat error (client) ***\n");
        exit(1);
    }
}
