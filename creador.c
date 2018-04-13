#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "creador.h"

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)

// Main method for the productor.c file
int main(int argc, char* argv[])
{
    initializeVars();
    while(1)
    {
    }
}

// Initializes the variables used in the system
void initializeVars()
{
}
