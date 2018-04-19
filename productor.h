#ifndef PRODUCTOR_H_
#define PRODUCTOR_H_
<<<<<<< HEAD
#include "creador.h"
=======
>>>>>>> b0fe7573e71c60c46ebcb5e9a6ccf711864e5da3

// Definition of struct for the productor
struct Productor
{
    int seconds;
<<<<<<< HEAD
    int productorId;
=======
>>>>>>> b0fe7573e71c60c46ebcb5e9a6ccf711864e5da3
    char* message;
    char* bufferName;
    int messagesCreated;
    double totalWaitingTime;
};
typedef struct Productor Productor;

// Productor.c file methods pre-definitions
Productor setProductor(int arg, char* argv[]);
<<<<<<< HEAD
void createMessages(Productor p);
=======
>>>>>>> b0fe7573e71c60c46ebcb5e9a6ccf711864e5da3

#endif
