#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include<unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SHM_SIZE 1024  /* make it a 1K shared memory segment */

int main(int argc, char *argv[])
{
    int existKey;
    FILE *keyFile;
    key_t key;
    int shmid;
    char *data;
    int mode;

    char *bufferName;
    int seconds;

    //Method that takes the input arguments and create a new Productor object
    //Input arguments are:
    //                   -b --> name of the buffer
    //                   -s --> seconds for the random waiting mean time
    if(argc > 5 || argc < 5){
        printf("El creador necesita de todos sus parametros. \n");
    }else{
            for(int i=1; i<argc; i++)
            {
                if (strcmp("-b",argv[i]) == 0) bufferName = argv[i+1];
                else if (strcmp("-s",argv[i]) == 0) seconds = atoi(argv[i+1]);            
            }

            printf("Buffer Name: %s\n", bufferName );
            printf("Seconds: %d\n", seconds);

            //ABRIR Key
            existKey = open(bufferName,O_RDONLY);
         
            //CONTROLAR SI EXISTE ARCHIVO
            // if(existKey !=-1){
            //     printf("\n Actualmente existe un buffer abierto con este nombre.");
            // }else{
                printf("Creando el buffer: %s\n", bufferName);
                keyFile = fopen(bufferName, "w+");
                /* make the key: */
                if ((key = ftok(bufferName, 'R')) == -1) {
                    perror("ftok");
                    exit(1);
                }

                /* connect to (and possibly create) the segment: */
                if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1) {
                    perror("shmget");
                    exit(1);
                }

                printf("shmid %d \n", shmid);
            // }
            

    }

    return 0;
}

