#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char* TiposProductos[] = {"Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"};

typedef struct {
    int ProductoID;        // Numerado en ciclo iterativo
    int Cantidad;          // entre 1 y 10
    char* TipoProducto;    // Algún valor del arreglo TiposProductos
    float PrecioUnitario;  // entre 10 - 100
} Producto;

typedef struct {
    int ClienteID;                // Numerado en el ciclo iterativo
    char* NombreCliente;          // Ingresado por usuario
    int CantidadProductosAPedir;  // (aleatorio entre 1 y 10)
    Producto* Productos           // El tamaño de este arreglo depende de la variable
                                  //  “CantidadProductosAPedir”
} Cliente;

int main() {
    srand(time(NULL));
    int cantClientes;
    char* buff;
    buff = (char*)malloc(100 * sizeof(char));
    puts("Ingrese la cantidad de clientes con 5 como maximo: ");
    scanf("%d", &cantClientes);
    while (cantClientes > 5 || cantClientes < 0) {
        puts("Cantidad invalida, ingrese nuevamente");
        scanf(" %d", &cantClientes);
    }
    Cliente* clientes = (Cliente*)malloc(cantClientes * sizeof(Cliente));
    for (int i = 0; i < cantClientes; i++) {
        clientes[i].ClienteID = i + 1;
        puts("Ingrese nombre del cliente: ");
        gets(buff);
        strcpy(clientes->NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = 1 + rand() % 10;
        clientes[i].Productos = (Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = 1 + rand() % 10;
            clientes[i].Productos[j].TipoProducto = rand() % 5;
            clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 100;
        }
    }

    free(buff);
    free(clientes);
    return 0;
}
