#ifndef PRODUCTOR_H_
#define PRODUCTOR_H_

// Definition of struct for the productor
struct Productor
{
    int seconds;
    char* message;
    char* bufferName;
    int messagesCreated;
    double totalWaitingTime;
};
typedef struct Productor Productor;

// Productor.c file methods pre-definitions
Productor setProductor(int arg, char* argv[]);

#endif
