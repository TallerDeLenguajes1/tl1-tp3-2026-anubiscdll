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
    Producto* Productos;          // El tamaño de este arreglo depende de la variable
                                  //  “CantidadProductosAPedir”
} Cliente;

float TotalProducto(Producto prod);

int main() {
    srand(time(NULL));
    int cantClientes;
    char* buff = (char*)malloc(100 * sizeof(char));
    float suma[] = {0, 0, 0, 0, 0};

    puts("Ingrese la cantidad de clientes con 5 como maximo: ");
    scanf("%d", &cantClientes);
    getchar();
    while (cantClientes > 5 || cantClientes < 0) {
        puts("Cantidad invalida, ingrese nuevamente");
        scanf(" %d", &cantClientes);
        getchar();
    }
    Cliente* clientes = (Cliente*)malloc(cantClientes * sizeof(Cliente));
    for (int i = 0; i < cantClientes; i++) {
        clientes[i].ClienteID = i + 1;
        puts("Ingrese nombre del cliente: ");
        gets(buff);
        clientes[i].NombreCliente = (char*)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(clientes[i].NombreCliente, buff);
        clientes[i].CantidadProductosAPedir = 1 + rand() % 10;
        clientes[i].Productos = (Producto*)malloc(clientes[i].CantidadProductosAPedir * sizeof(Producto));
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            clientes[i].Productos[j].ProductoID = j + 1;
            clientes[i].Productos[j].Cantidad = 1 + rand() % 10;
            clientes[i].Productos[j].TipoProducto = TiposProductos[rand() % 5];
            clientes[i].Productos[j].PrecioUnitario = 10 + rand() % 100;
            suma[i] += TotalProducto(clientes[i].Productos[j]);
        }
    }

    for (int i = 0; i < cantClientes; i++) {
        printf("El Cliente: %s ,de ID: %d pidio %d productos: \n", clientes[i].NombreCliente, clientes[i].ClienteID, clientes[i].CantidadProductosAPedir);
        for (int j = 0; j < clientes[i].CantidadProductosAPedir; j++) {
            printf("Producto %d: %s - ID: %d - Cantidad: %d - Precio unitario: %.2f \n", j + 1, clientes[i].Productos[j].TipoProducto, clientes[i].Productos[j].ProductoID, clientes[i].Productos[j].Cantidad, clientes[i].Productos[j].PrecioUnitario);
        }
        printf("El costo total del cliente es: %.2f \n", suma[i]);
    }

    free(buff);
    for (int i = 0; i < cantClientes; i++) {
        if (clientes[i].NombreCliente != NULL) {
            free(clientes[i].NombreCliente);
        }
        if (clientes[i].Productos != NULL) {
            free(clientes[i].Productos);
        }
    }
    free(clientes);
    return 0;
}

float TotalProducto(Producto prod) {
    return (prod.Cantidad * prod.PrecioUnitario);
}