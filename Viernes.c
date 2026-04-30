#include <stdio.h>

int main() {
    int numeros[5];
    int suma = 0;
    float promedio;

    // Pedir datos al usuario
    for(int i = 0; i < 5; i++) {
        printf("Ingresa el numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Calcular suma
    for(int i = 0; i < 5; i++) {
        suma += numeros[i];
    }

    // Calcular promedio
    promedio = suma / 5.0;

    // Mostrar resultados
    printf("La suma es: %d\n", suma);
    printf("El promedio es: %.2f\n", promedio);

    return 0;
}