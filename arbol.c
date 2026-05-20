#include<stdio.h>
struct arbol{
    int Dato;
    struct arbol *izq;
    struct arbol *der;
};

int Menu(){
    int op;
    printf("\n---MENU---\n");
    printf("[1]....Insertar nuevo dato\n");
    printf("[2]....Eliminar\n");
    printf("[3]....Salir\n");;
    printf("Elija una opcion: \n");
    scanf("%d",&op);
    return op;
}
int main(void){
    int op;
    struct arbol *ptrtaux;
    struct arbol *ptrtemp;
    struct arbol *raiz;

    do{
        op=Menu();
        switch (op) {
            case 1:
            
            break;
            
            case 2:
                break;

        }
    }
}