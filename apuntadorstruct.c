#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrsig;
};
int menu(void) {
    int opcion;

        printf("\n--- MENU ---\n");
        printf(". seleccione una opcion\n");
        printf("1. crear dato\n");
        printf("2. Mostrar dato\n");
        printf("3. Eliminar ultimo nodo\n");
        printf("4. Salir\n");
        scanf("%d", &opcion);
        return opcion;
}

struct Dato* creardato(){
  struct Dato *ptrtem = (struct Dato*)malloc(sizeof(struct Dato)); {
    if (ptrtem==NULL){
        return NULL;
    }else{
        printf("ingrese el valor entero: ");
        scanf("%d",&ptrtem->d);
        ptrtem->ptrsig=NULL;
        return ptrtem;
   }
};

int main() {
    int opcion;
    struct Dato *ptr=NULL;
    struct Dato *ptrtem=NULL;
    struct Dato *Ptraux=NULL;
    
    do{
        opcion=menu();
        switch (opcion) {
            case 1:
                 ptrtem=nuevoDato();
                 if (ptrtem==NULL){
                    printf("No se reservo memoria\n");
                 }else{
                    if (ptr==NULL){
                        ptr=ptrtem;
                    }else{
                        Ptraux=ptr;
                    while (ptraux->ptrsig !=NULL){
                       ptraux=ptraux->ptrsig;
                    }
                        ptraux->ptrsig=ptrtem;
                    }
                 }

                break;
            case 2:
                if (ptr==NULL){
                    printf("no existe ningun dato\n");
                }else{
                    ptraux->ptr;
                    printf("contenido:\n ");
                    while (ptraux !=NULL){
                        printf("%d",ptraux->d); 
                        ptraux=(ptraux->ptrsig);
                    }
                    
                }
                break;
            case 3:
                if (ptr==NULL){
                    printf("no hay nada que eliminar")
                }else{
                    ptraux=ptr;
                    if(ptraux->ptrsig=NULL){
                        free(ptraux);
                        ptr=NULL;
                    }
                }else{
                    ptraux=NULL;
                    while (condition)
                    {
                        
                    }
                    
                }

                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 4);

    return 0;
}

