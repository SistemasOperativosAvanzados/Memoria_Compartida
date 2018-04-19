#ifndef CREADOR_H_
#define CREADOR_H_

// Definition of global variables to be used in the system
struct Creador
{
    int seconds;
    char* message;
    char* bufferName;
    int messagesCreated;
    double totalWaitingTime;
};
typedef struct Creador Creador;

// creador.c file methods pre-definitions
void initializeVars();

#endif