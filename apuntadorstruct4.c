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
    printf("1. Crear dato\n");
    printf("2. Mostrar datos\n");
    printf("3. Eliminar ultimo nodo\n");
    printf("4. Salir\n");
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
    int opcion;
    struct Dato *ptr = NULL;
    struct Dato *ptrtem = NULL;
    struct Dato *ptraux = NULL;

    do{
        opcion = menu();
        switch (opcion) {

            case 1:
                ptrtem = creardato();  // CORREGIDO

                if (ptrtem == NULL){
                    printf("No se reservo memoria\n");
                } else {
                    if (ptr == NULL){
                        ptr = ptrtem;
                    } else {
                        ptraux = ptr;
                        while (ptraux->ptrsig != NULL){
                            ptraux = ptraux->ptrsig;
                        }
                        ptraux->ptrsig = ptrtem;
                    }
                }
                break;

            case 2:
                if (ptr == NULL){
                    printf("No existe ningun dato\n");
                } else {
                    ptraux = ptr;  // CORREGIDO
                    printf("Contenido:\n");
                    while (ptraux != NULL){
                        printf("%d ", ptraux->d);
                        ptraux = ptraux->ptrsig;
                    }
                    printf("\n");
                }
                break;

            case 3:
                if (ptr == NULL){
                    printf("No hay nada que eliminar\n");  // faltaba ;
                } else {
                    ptraux = ptr;

                    // Caso: solo un nodo
                    if (ptraux->ptrsig == NULL){  // CORREGIDO (==)
                        free(ptraux);
                        ptr = NULL;
                    } else {
                        struct Dato *anterior = NULL;

                        // recorrer hasta el último nodo
                        while (ptraux->ptrsig != NULL){
                            anterior = ptraux;
                            ptraux = ptraux->ptrsig;
                        }

                        // eliminar último nodo
                        anterior->ptrsig = NULL;
                        free(ptraux);
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