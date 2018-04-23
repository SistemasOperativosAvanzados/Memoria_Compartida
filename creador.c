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
    int       shm_id;
    key_t     mem_key;
    int       *shm_ptr;

    mem_key = ftok(".", 'a');
    shm_id = shmget(mem_key, 4*sizeof(int), IPC_CREAT | 0666);
    if (shm_id < 0) {
        printf("*** shmget error (server) ***\n");
        exit(1);
    }
    
    printf("Id de la memoria compartida en el creador: %d\n", shm_id);

    shm_ptr = (int *) shmat(shm_id, NULL, 0);  /* attach */
    //if ((int) shm_ptr == -1) {
    //    printf("*** shmat error (server) ***\n");
    //    exit(1);
    //}
    
}


//http://www.csl.mtu.edu/cs4411.ck/www/NOTES/process/shm/example-2.html

