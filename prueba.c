#include <stdio.h>
#include <string.h>

#define MAX 100

// Estructura de producto
struct Producto {
    char nombre[50];
    int cantidad;
    float precio;
};

struct Producto inventario[MAX];
int totalProductos = 0;

// Función para agregar producto
void agregarProducto() {
    if (totalProductos < MAX) {
        printf("Nombre del producto: ");
        scanf(" %[^\n]", inventario[totalProductos].nombre);

        printf("Cantidad: ");
        scanf("%d", &inventario[totalProductos].cantidad);

        printf("Precio: ");
        scanf("%f", &inventario[totalProductos].precio);

        totalProductos++;
        printf("Producto agregado correctamente.\n");
    } else {
        printf("Inventario lleno.\n");
    }
}

// Mostrar productos
void mostrarProductos() {
    printf("\n--- Inventario ---\n");
    for (int i = 0; i < totalProductos; i++) {
        printf("%d. %s | Cantidad: %d | Precio: %.2f\n",
               i, inventario[i].nombre,
               inventario[i].cantidad,
               inventario[i].precio);
    }
}

// Modificar producto
void modificarProducto() {
    int id;
    mostrarProductos();
    printf("Seleccione el producto a modificar: ");
    scanf("%d", &id);

    if (id >= 0 && id < totalProductos) {
        printf("Nuevo nombre: ");
        scanf(" %[^\n]", inventario[id].nombre);

        printf("Nueva cantidad: ");
        scanf("%d", &inventario[id].cantidad);

        printf("Nuevo precio: ");
        scanf("%f", &inventario[id].precio);

        printf("Producto actualizado.\n");
    } else {
        printf("ID inválido.\n");
    }
}

// Comprar producto
void comprarProducto() {
    int id, cantidad;
    float total = 0;
    FILE *archivo = fopen("registro.txt", "a");

    if (archivo == NULL) {
        printf("Error al abrir archivo.\n");
        return;
    }

    char continuar = 's';

    while (continuar == 's') {
        mostrarProductos();
        printf("Seleccione producto: ");
        scanf("%d", &id);

        if (id < 0 || id >= totalProductos) {
            printf("ID inválido.\n");
            continue;
        }

        printf("Cantidad a comprar: ");
        scanf("%d", &cantidad);

        if (cantidad <= inventario[id].cantidad) {
            float subtotal = cantidad * inventario[id].precio;
            total += subtotal;

            inventario[id].cantidad -= cantidad;

            fprintf(archivo, "Producto: %s | Cantidad: %d | Subtotal: %.2f\n",
                    inventario[id].nombre, cantidad, subtotal);

            printf("Agregado al carrito.\n");
        } else {
            printf("No hay suficiente stock.\n");
        }

        printf("¿Desea comprar otro producto? (s/n): ");
        scanf(" %c", &continuar);
    }

    fprintf(archivo, "TOTAL COMPRA: %.2f\n----------------------\n", total);
    fclose(archivo);

    printf("Total a pagar: %.2f\n", total);
}

// Menú principal
int main() {
    int opcion;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Agregar producto\n");
        printf("2. Mostrar productos\n");
        printf("3. Modificar producto\n");
        printf("4. Comprar producto\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto();
                break;
            case 2:
                mostrarProductos();
                break;
            case 3:
                modificarProducto();
                break;
            case 4:
                comprarProducto();
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }
    } while (opcion != 5);

    return 0;
}