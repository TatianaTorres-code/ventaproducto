#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main() {
    int opcion;
    do {
        printf("Menu:\n");
        printf("1. Visualizar productos\n");
        printf("2. Realizar venta\n");
        printf("3. Listar todas las ventas\n");
        printf("4. Listar ventas por cliente\n");
        printf("5. Buscar venta por cedula\n");
        printf("6. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                visualizarProductos();
                break;
            case 2:
                realizarVenta();
                break;
            case 3:
                listarTodasLasVentas();
                break;
            case 4:
                listarVentasPorCliente();
                break;
            case 5:
                buscarVentaPorCedula();
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente nuevamente.\n");
        }
    } while (opcion != 6);
    
    return 0;
}