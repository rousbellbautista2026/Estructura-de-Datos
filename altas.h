#include <stdio.h>

void ALTAS(struct Persona**);

void ALTAS(struct Persona**ptr);{
    struct persona *p=NULL;
    struct Alumno *A=NULL;
    int b=1;
    p=nuevaPersona();
    if(P==NULL)
        B=0;
    else{
        A=nuevoAlumno();
        if(A==NULL){
            b=0;
            free(p);
        }
        else{
            p->ptrAlum=A;
            if(*ptr==NULL){
                *ptr=p;
            }
        }
    }
    return b;
}

