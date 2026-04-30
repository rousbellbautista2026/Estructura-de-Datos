#include <stdio.h>
#include <string.h>
#include <time.h>

struct Estudiante {
    char Nombre[50];
    int Calificacion[5][5]

};


int main(void){

    struct Estudiante estudiante[5];

    for (int i=0; i<5; i++){
        printf("Ingrese el nombre del estudiante: ");
        fgets(estudiante[].Nombre, sizeof(estudiante.Nombre), stdin);

         for (int i = 0; i < 5; i++) {
             printf("\n")
              for (int j = 0; j < 5; j++) {
                estudiante.Calificacion[i][j] = rand() % 10+1;
                printf("Calificacion %d: %d\n", j + 1, estudiante.Calificacion[i][j]);
                }
            }
    }   +


   srand(time(NULL));
 
  
return 0;
}
