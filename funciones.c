#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

producto productos[] = {
    {1, "Laptop", 1000.0},
    {2, "Auriculares", 80.0},
    {3, "Monitor", 90.0},
    {4, "Mouse", 30.0}
};
int numProductos = sizeof(productos) / sizeof(productos[0]);
venta ventas[100];
int numeroVentas = 0;

void visualizarProductos() {
    printf("Productos disponibles:\n");
    printf("%-5s %-30s %-10s\n", "ID", "Nombre", "Precio");
    printf("---------------------------------------------\n");
    for (int i = 0; i < numProductos; i++) {
        printf("%-5d %-30s %-10.2f\n", productos[i].id, productos[i].nombre, productos[i].precio);
    }
    printf("---------------------------------------------\n");
}

void realizarVenta() {
    venta nuevaVenta;

    printf("Ingrese el nombre del cliente: ");
    scanf("%99s", nuevaVenta.nombreCliente);

    printf("Ingrese la cedula del cliente:\n");
    scanf("%12s", nuevaVenta.cedulaCliente);

    printf("Ingrese el numero de producto:\n");
    scanf("%d", &nuevaVenta.numeroProducto);

    // Validar si el producto existe
    int encontrado = 0;
    for (int i = 0; i < numProductos; i++) {
        if (productos[i].id == nuevaVenta.numeroProducto) {
            strcpy(nuevaVenta.nombreProducto, productos[i].nombre);
            nuevaVenta.totalProducto = productos[i].precio;
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Producto no encontrado.\n");
        return;
    }

    ventas[numeroVentas++] = nuevaVenta;
    printf("Venta realizada con exito.\n");
}

void listarTodasLasVentas() {
    printf("Listado de todas las ventas:\n");
    printf("%-20s %-15s %-5s %-30s %-10s\n", "Nombre Cliente", "Cedula Cliente", "ID Producto", "Nombre Producto", "Total");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < numeroVentas; i++) {
        printf("%-20s %-15s %-5d %-30s $%-10.2f\n",
               ventas[i].nombreCliente,
               ventas[i].cedulaCliente,
               ventas[i].numeroProducto,
               ventas[i].nombreProducto,
               ventas[i].totalProducto);
    }
    printf("---------------------------------------------------------------\n");
}

void listarVentasPorCliente() {
    char nombreCliente[100];
    printf("Ingrese el nombre del cliente: ");
    scanf("%99s", nombreCliente);

    printf("Ventas para el cliente %s:\n", nombreCliente);
    printf("%-20s %-15s %-5s %-30s %-10s\n", "Nombre Cliente", "Cedula Cliente", "ID Producto", "Nombre Producto", "Total");
    printf("---------------------------------------------------------------\n");

    int encontrado = 0;
    for (int i = 0; i < numeroVentas; i++) {
        if (strcmp(ventas[i].nombreCliente, nombreCliente) == 0) {
            printf("%-20s %-15s %-5d %-30s $%-10.2f\n",
                   ventas[i].nombreCliente,
                   ventas[i].cedulaCliente,
                   ventas[i].numeroProducto,
                   ventas[i].nombreProducto,
                   ventas[i].totalProducto);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron ventas para el cliente %s.\n", nombreCliente);
    }
}

void buscarVentaPorCedula() {
    char cedula[13];
    printf("Ingrese la cedula del cliente: ");
    scanf("%12s", cedula);

    printf("Ventas para el cliente con cedula %s:\n", cedula);
    printf("%-20s %-15s %-5s %-30s %-10s\n", "Nombre Cliente", "Cedula Cliente", "ID Producto", "Nombre Producto", "Total");
    printf("---------------------------------------------------------------\n");

    int encontrado = 0;
    for (int i = 0; i < numeroVentas; i++) {
        if (strcmp(ventas[i].cedulaCliente, cedula) == 0) {
            printf("%-20s %-15s %-5d %-30s $%-10.2f\n",
                   ventas[i].nombreCliente,
                   ventas[i].cedulaCliente,
                   ventas[i].numeroProducto,
                   ventas[i].nombreProducto,
                   ventas[i].totalProducto);
            encontrado = 1;
        }
    }

    if (!encontrado) {
        printf("No se encontraron ventas para el cliente con cedula %s.\n", cedula);
    }
}