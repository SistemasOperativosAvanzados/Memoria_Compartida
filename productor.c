#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "productor.h"

// Main method for the productor.c file
int main(int argc, char* argv[])
{   
    Productor productor = setProductor(argc,argv);
    printf("A new productor hass been created with the following data:\n");
    printf("Productor's buffer: %s\n", productor.bufferName);
    printf("Productor's seconds: %d\n", productor.seconds);
    printf("Productor's message: %s\n", productor.message);
    
    return 0;
}

//Method that takes the input arguments and create a new Productor object
//Input arguments are:
//                   -b --> name of the buffer
//                   -s --> seconds for the random waiting time
Productor setProductor(int argc, char* argv[])
{
    Productor prod;
    
    for(int i=1; i<argc; i++)
    {
        if (strcmp("-b",argv[i]) == 0) prod.bufferName = argv[i+1];
        else if (strcmp("-s",argv[i]) == 0) prod.seconds = atoi(argv[i+1]);            
    }
    
    prod.message = "Test message for the productor";
    
    return prod;
}
