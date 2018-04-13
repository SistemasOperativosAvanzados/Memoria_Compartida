#ifndef PRODUCTOR_H_
#define PRODUCTOR_H_
#include "creador.h"

// Definition of struct for the productor
struct Productor
{
    int seconds;
    int productorId;
    char* message;
    char* bufferName;
    int messagesCreated;
    double totalWaitingTime;
};
typedef struct Productor Productor;

// Productor.c file methods pre-definitions
Productor setProductor(int arg, char* argv[]);
void createMessages(Productor p);

#endif
