#include <stdio.h>
#include <stdlib.h>

struct Dato{
    int d;
    struct Dato *ptrsig;
};

int menu(void) {
    int opcion;
    printf("\n--- MENU ---\n");
    printf("Seleccione una opcion\n");
    printf("[1].- Crear dato\n");
    printf("[2].- Funciones\n");
    printf("[3].- Mostrar datos\n");
    printf("[4].- Eliminar ultimo nodo\n");
    printf("[5].- Salir\n");
    scanf("%d", &opcion);
    return opcion;
}

int submenu(void) {
    int opcion;
    printf("\n--- MENU FUNCIONES ---\n");
    printf("[1].- Buscar\n");
    printf("[2].- Contar\n");
    printf("[3].- Regresar\n");
    scanf("%d", &opcion);
    return opcion;
}


struct Dato* creardato(){
    struct Dato *ptrtem = (struct Dato*)malloc(sizeof(struct Dato));

    if (ptrtem == NULL){
        return NULL;
    } else {
        printf("Ingrese el valor entero: ");
        scanf("%d", &ptrtem->d);
        ptrtem->ptrsig = NULL;
        return ptrtem;
    }
}

int main() {
    int opcion,op2;
    struct Dato *ptr = NULL;
    struct Dato *ptrtem = NULL;
    struct Dato *ptraux = NULL;
    struct Dato *anterior = NULL;                   

    do{
        opcion = menu();
        switch (opcion) {

            case 1:
                ptrtem = creardato();  

                if (ptrtem == NULL){
                    printf("No se reservo memoria\n");
                    } 
                else {
                    if (ptr == NULL){
                        ptr = ptrtem;
                        }
                    else {
                        ptraux = ptr;
                        while (ptraux->ptrsig != NULL){
                            ptraux = ptraux->ptrsig;
                            }
                        ptraux->ptrsig = ptrtem;
                        }
                    }
                break;
            case 2:
                do{
                    op2=submenu();
                    switch(op2){
                        case 1:
                            
                            break;
                        case 2:
                            break;
                        case 3:
                            break;
                        default:
                            break;
                        }
                    }while(op2!=3);
                break;
            case 3:
                if (ptr == NULL){
                    printf("No existe ningun dato\n");
                } else {
                    ptraux = ptr; 
                    printf("Contenido:\n");
                    while (ptraux != NULL){
                        printf("%d -> ", ptraux->d);
                        ptraux = ptraux->ptrsig;
                    }
                    printf("\n");
                }
                break;

            case 4:
                if (ptr == NULL){
                    printf("No hay nada que eliminar\n");  
                    } 
                else {
                    ptraux = ptr;                
                    if (ptraux->ptrsig == NULL){  
                        free(ptraux);
                        ptr = NULL;
                        } 
                    else{                     
                        while (ptraux->ptrsig != NULL){
                            anterior = ptraux;
                            ptraux = ptraux->ptrsig;
                            }                       
                        anterior->ptrsig = NULL;
                        free(ptraux);
                        }
                    }
                break;

            case 5:
                if (ptr != NULL){
                    
                    if (ptr->ptrsig == NULL){  
                        free(ptraux);
                        ptr = NULL;
                        } 
                    else{               
                        ptraux=ptr;      
                        ptr=NULL;
                        while (ptraux->ptrsig != NULL){                            
                            anterior = ptraux;                            
                            ptraux = ptraux->ptrsig;
                            free(ptraux);
                            }   
                        free(ptraux);       

                        printf("Todos los nodos fueron eliminados \n");
                        }
                    }
                printf("Saliendo...\n");
                break;

            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 5);

    return 0;
}