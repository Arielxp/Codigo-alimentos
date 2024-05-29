#include <stdio.h>
#include <string.h>
#include "funciones.h"
#define MAX_PRODUCTOS 10

int main() {
    char productos[MAX_PRODUCTOS][3][30];
    float costos[MAX_PRODUCTOS];
    int cantidades[MAX_PRODUCTOS];
    char nombreBuscado[30];
    int opcionPrincipal, opcionSecundaria;
    int totalProductos = 0;

    do {
        printf("Seleccione una opcion:\n1. Ingresar Productos\n2. Imprimir Inventario\n3. Buscar Producto\n4. Editar Producto\n5. Eliminar Producto\n>> ");
        scanf("%d", &opcionPrincipal);
        
        switch (opcionPrincipal) {
            case 1:
                printf("¿Cuántos productos desea ingresar? ");
                scanf("%d", &totalProductos);
                if (totalProductos > MAX_PRODUCTOS) {
                    printf("El número máximo de productos es %d.\n", MAX_PRODUCTOS);
                    totalProductos = MAX_PRODUCTOS;
                }
                ingresarProductos(productos, costos, cantidades, totalProductos);
                break;
            case 2:
                imprimirInventario(productos, costos, cantidades, totalProductos);
                break;
            case 3:
                printf("Ingrese el nombre del producto que desea buscar: ");
                scanf("%s", nombreBuscado);
                int indice = buscarProductoPorNombre(productos, nombreBuscado, totalProductos);
                imprimirProductoPorIndice(nombreBuscado, productos, costos, cantidades, indice);
                break;
            case 4:
                printf("Ingrese el nombre del producto que desea editar: ");
                scanf("%s", nombreBuscado);
                editarProducto(nombreBuscado, productos, costos, cantidades, totalProductos);
                break;
            case 5:
                printf("Ingrese el nombre del producto que desea eliminar: ");
                scanf("%s", nombreBuscado);
                eliminarProducto(productos, costos, cantidades, totalProductos, nombreBuscado);
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }
        printf("Desea elegir una nueva opcion: 1.Si / 2.No\n>> ");
        scanf("%d", &opcionSecundaria);
    } while (opcionSecundaria == 1);

    return 0;
}

void ingresarProductos(char productos[][3][30], float costos[], int cantidades[], int total) {
    for (int i = 0; i < total; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        scanf("%s", productos[i][0]);
        printf("Ingrese el precio del producto %d: ", i + 1);
        scanf("%f", &costos[i]);
        printf("Ingrese la cantidad del producto %d: ", i + 1);
        scanf("%d", &cantidades[i]);
    }
}

void imprimirInventario(char productos[][3][30], float costos[], int cantidades[], int total) {
    printf("Nombre\t\tPrecio\t\tCantidad\n");
    for (int i = 0; i < total; i++) {
        if (cantidades[i] > 0) {
            printf("%s\t\t%.2f\t\t%d\n", productos[i][0], costos[i], cantidades[i]);
        }
    }
}

int buscarProductoPorNombre(char productos[][3][30], char nombreBuscado[], int total) {
    int indice = -1;
    for (int i = 0; i < total; i++) {
        if (strcmp(productos[i][0], nombreBuscado) == 0) {
            indice = i;
            break;
        }
    }
    return indice;
}

void imprimirProductoPorIndice(char nombreBuscado[], char productos[][3][30], float costos[], int cantidades[], int indice) {
    if (indice != -1) {
        printf("Los datos de %s son: \n", nombreBuscado);
        printf("Precio: %.2f\n", costos[indice]);
        printf("Cantidad: %d\n", cantidades[indice]);
    } else {
        printf("No existe el producto %s en el inventario\n", nombreBuscado);
    }
}

void editarProducto(char nombreBuscado[], char productos[][3][30], float costos[], int cantidades[], int total) {
    int indice = buscarProductoPorNombre(productos, nombreBuscado, total);
    if (indice != -1) {
        printf("Ingrese el nuevo nombre del producto: ");
        scanf("%s", productos[indice][0]);
        printf("Ingrese el nuevo precio del producto %s: ", nombreBuscado);
        scanf("%f", &costos[indice]);
        printf("Ingrese la nueva cantidad del producto %s: ", nombreBuscado);
        scanf("%d", &cantidades[indice]);
    } else {
        printf("No existe el producto %s en el inventario\n", nombreBuscado);
    }
}

void eliminarProducto(char productos[][3][30], float costos[], int cantidades[], int total, char nombreBuscado[]) {
    int indice = buscarProductoPorNombre(productos, nombreBuscado, total);
    if (indice != -1) {
        for (int i = indice; i < total - 1; i++) {
            strcpy(productos[i][0], productos[i + 1][0]);
            costos[i] = costos[i + 1];
            cantidades[i] = cantidades[i + 1];
        }
        productos[total - 1][0][0] = '\0';
        costos[total - 1] = 0;
        cantidades[total - 1] = 0;
        printf("Producto %s eliminado del inventario.\n", nombreBuscado);
    } else {
        printf("No existe el producto %s en el inventario\n", nombreBuscado);
    }
}


