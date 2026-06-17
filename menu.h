#include<stdio.h>
int menuPrincipal(void);

int menuPrincipal(){
    int op;
    printf("\n--- MENU ---\n");
    printf("1. Dar de alta un alumno\n");
    printf("2. Dar de baja a un alumno\n");
    printf("3. Salir\n");
    printf("Opcion: ");
    scanf("%d",&op);
    return op;

}