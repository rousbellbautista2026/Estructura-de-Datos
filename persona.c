#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

struct Persona{
    char * Nombre;
    int Edad;
    char Genero;
    char Fn[8];
    struct Alumno *ptralum;
    struct Persona *ptrsig;
};

struct Alumno{
    char matricula[10];
    char carrera[5];
    int semestre;
    char correo[23];
    float calif[5][5];

};


int main(void){
    int op;
    struct Persona *ptr;
    do{
        op=menuPrincipal();
        switch(op){
            case 1:
                Altas(&ptr);
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
        } 

    }while(op!=3);
}
