#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "consumidor.h"

// Metodo que crea una instancia nueva del consumidor
int main(int argc, char* argv[]){   
    Consumidor consumidor = setConsumidor(argc,argv);
    printf("Se ha creado un nuevo consumidor, con el ID: %d\t, buffer: %s\t, segundos: %d\t, mensaje: %s\n", consumidor.consumidorID, consumidor.buffer,consumidor.segundos,consumidor.mensaje);
    
    getMessage(consumidor);

    return 0;
}

//
Consumidor setConsumidor(int argc, char* argv[]){
	Consumidor consumidor;
	consumidor.buffer = 1;
	
}

//Metodo que obtendra un mensaje de acuerdo al consumidor
void getMessage(Consumidor c){
	
}