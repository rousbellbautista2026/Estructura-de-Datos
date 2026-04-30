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
    printf("2. Mostrar dato\n");
    printf("3. Liberar\n");
    printf("4. Salir\n");
    scanf("%d", &opcion);

    return opcion;
}

struct Dato* crearDato(){
    struct Dato *ptrtem = (struct Dato*)malloc(sizeof(struct Dato));

    if (ptrtem == NULL){
        return NULL;
    }

    printf("Ingrese el valor entero: ");
    scanf("%d", &ptrtem->d);

    ptrtem->ptrsig = NULL;

    return ptrtem;
}

void mostrar(struct Dato *dato){
    if (dato != NULL){
        printf("Dato: %d\n", dato->d);
    } else {
        printf("No hay dato.\n");
    }
}

void liberar(struct Dato *dato){
    free(dato);
}

int main() {
    int opcion;
    struct Dato *dato = NULL;

    do {
        opcion = menu();

        switch (opcion) {
            case 1:
                dato = crearDato();
                break;
            case 2:
                mostrar(dato);
                break;
            case 3:
                liberar(dato);
                dato = NULL;
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