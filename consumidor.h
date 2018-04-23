#ifndef CONSUMIDOR_H_
#define CONSUMIDOR_H_
#include "productor.h"
#include "creador.h"

//Se crea el struct para el consumidor
struct Consumidor
{
    int consumidorID;
    char* nombre;
    char* mensaje;
    int segundos;
    char* buffer;
    double tiempoEspera;
    int totalConsumidores;
};

typedef struct Consumidor Consumidor;

//Se definen los metodos de la clase consumidor.c
Consumidor setConsumidor(int arg, char* argv[]);
void getMessage(Consumidor c);

#endif
