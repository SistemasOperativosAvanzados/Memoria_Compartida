#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "productor.h"


// Main method for the productor.c file
int main(int argc, char* argv[])
{   
    Productor productor = setProductor(argc,argv);
    printf("A new productor hass been created with the following data:\n");
    printf("Productor's ID: %d\n", productor.productorId);
    printf("Productor's buffer: %s\n", productor.bufferName);
    printf("Productor's seconds: %d\n", productor.seconds);
    printf("Productor's message: %s\n", productor.message);
    
    createMessages(productor);

    return 0;
}

//Method that takes the input arguments and create a new Productor object
//Input arguments are:
//                   -b --> name of the buffer
//                   -s --> seconds for the random waiting mean time
Productor setProductor(int argc, char* argv[])
{
    Productor prod;
    
    for(int i=1; i<argc; i++)
    {
        if (strcmp("-b",argv[i]) == 0) prod.bufferName = argv[i+1];
        else if (strcmp("-s",argv[i]) == 0) prod.seconds = atoi(argv[i+1]);            
    }
    
    prod.message = "Test message for the productor";
    prod.productorId = 1;
    
    return prod;
}

// Method that creates the messages for the buffer 
void createMessages(Productor p)
{
    time_t currentTime = time(NULL);
    char* formatedTime;
    while(1)
    {
        while(time(NULL) - currentTime < p.seconds);
        formatedTime = ctime(&currentTime);
        printf("A message has been sent to the buffer: %s, at the time: %s\n", p.bufferName, formatedTime);
        currentTime = time(NULL);
        
    }
    return;
}
