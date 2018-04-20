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
    key_t key;
    int shmid;
    char *data;
    int mode;
    int existKey;
    FILE *keyFile;
    char *bufferName;
    int seconds;

    if(argc > 5 || argc < 5){
        printf("El consumidor necesita de todos sus parametros. \n");
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
        if(existKey !=-1){
            printf("\n Intentando acceder al buffer %s...\n",bufferName);
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

            /* attach to the segment to get a pointer to it: */
            data = shmat(shmid, (void *)0, 0);
            if (data == (char *)(-1)) {
                perror("shmat");
                exit(1);
            }

            printf("segment contains: \"%s\"\n", data);

            /* detach from the segment: */
            if (shmdt(data) == -1) {
                perror("shmdt");
                exit(1);
            }
        }else{
            printf("No existe el buffer %s.\n", bufferName);
        }
    }

    return 0;
}