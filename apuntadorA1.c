#include <stdio.h>

struct Punto{
int x,y;
};
int menu(){
    printf("[1] Leer datos\n [2] Mostrar datos\n[3]Calcular las distancias[4] Salir\n");
}
int leerdatos(struct Punto *ptr){
    ptr[10];
}
int main(){
    struct Punto punto[10],*ptr;
//Primer forma     
    for(int i=0;i<10;i++){
        punto[i].x=i*4;
        punto[i].y=i*5;
    }
//Segunda forma
    for(int i=0;i<10;i++){
        *(punto+1).x=5;
        *(punto+1).y=5;
    }
//Tercera forma
ptr=punto;//Punto es la direccion de memoria del primer elemento de punto
 for(int i=0;i<10;i++){
        *(ptr+1).x=5;
        *(ptr+1).y=5;
    }
    int op;
    scanf("%d",&op);//Leer opcion
    do
    {
        op=menu();
        switch (op)
        {
        case 1:
            leerDatos(punto);
            break;
        
        default:
            break;
        }
    } while (op!=4);
    
}
