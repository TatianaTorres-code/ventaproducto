#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct {
    int id;
    char nombre[50];
    float precio;
} producto;

typedef struct {
    char nombreCliente[100];
    char cedulaCliente[13];
    int numeroProducto;
    char nombreProducto[50];
    float totalProducto;
} venta;

extern producto productos[];
extern int numProductos;
extern venta ventas[100];
extern int numeroVentas;

void visualizarProductos();
void realizarVenta();
void listarTodasLasVentas();
void listarVentasPorCliente();
void buscarVentaPorCedula();

#endif