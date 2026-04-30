#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void menu(int res){

    printf("Seleccione una opcion \n");
    printf("1: rellenar \n");
    printf("2: mostrar datos \n");
    printf("3: salir");
    
    /*
    srand(time(NULL));
    do{
    for(int i=0; i<5; i++)
        ptr[i]=rand()%10 + 1;

    for(int j=0; j<5; j++)
        printf("%d \n", ptr[j]);
    
    printf("desas repetir el proceso para asignar los valores? \n");
    printf("presione 1 para salir");
    scanf("%d", &op);
    }while(op!=1);
    */
}

int main(){
    int *ptr;
    int res;

    ptr=(int*)malloc(sizeof(int)*5);

    menu(ptr);

    free(ptr);
}