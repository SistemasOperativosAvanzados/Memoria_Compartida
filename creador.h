#ifndef CREADOR_H_
#define CREADOR_H_
#include <sys/shm.h>
#include <sys/ipc.h>

// Definition of global variables to be used in the system
struct buffer{
  char* testMessage;
};

// creador.c file methods pre-definitions
void initializeVars();

#endif
