#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char** V);
int BuscarNombrePorPalabra(char** V, char* nombre);
void BuscarNombrePorId(char** V, int ind);
int main() {
    char* buff = (char*)malloc(50 * sizeof(char));
    char* vector[5];
    char mensaje[] = "Ingrese el nombre:";
    for (int i = 0; i < 5; i++) {
        puts(mensaje);
        gets(buff);
        vector[i] = (char*)malloc((strlen(buff) + 1) * sizeof(char));
        strcpy(vector[i], buff);
    }
    MostrarPersonas(vector);
    puts("Elija la operacion a realizar:");
    puts("1. Busqueda de nombre por ID");
    puts("2. Busqueda de nombre por palabra");
    puts("Ingrese el numero de la operación que desea realizar: ");
    int menu;
    scanf("%d", &menu);
    if (menu < 1 || menu > 2) {
        puts("Operación no encontrada");
    } else if (menu == 1) {
        puts("Ingrese un numero del 0 al 4 para buscar el nombre: ");
        int num;
        scanf("%d", &num);
        BuscarNombrePorId(vector, num);
    } else {
        puts("Ingrese un nombre a buscar: ");
        gets(buff);
        int busc = BuscarNombrePorPalabra(vector, buff);
        if (busc == -1) {
            puts("No se encontro el nombre");
        } else {
            puts("Se encontro:");
            printf(" %s\n", vector[busc]);
        }
    }
    /*
    puts("Ingrese un numero del 0 al 4 para buscar el nombre: ");
    int num;
    scanf("%d", &num);
    BuscarNombrePorId(vector, num);
    puts("Ingrese un nombre a buscar: ");
    gets(buff);
    int busc = BuscarNombrePorPalabra(vector, buff);
    if (busc == -1) {
        puts("No se encontro el nombre");
    } else {
        puts("Se encontro:");
        printf(" %s\n", vector[busc]);
    }
    */
    free(buff);
    for (int i = 0; i < 5; i++) {
        free(vector[i]);
    }

    return 0;
}
void MostrarPersonas(char** V) {
    for (int i = 0; i < 5; i++) {
        puts("El nombre es: ");
        printf(" %s\n", V[i]);
    }
}

int BuscarNombrePorPalabra(char** V, char* nombre) {
    for (int i = 0; i < 5; i++) {
        if (strstr(V[i], nombre)) {
            return i;
        }
    }
    return -1;
}

void BuscarNombrePorId(char** V, int ind) {
    if (ind < 0 || ind > 4) {
        puts("no se encontró el valor buscado");
    } else {
        puts("El nombre en la posicion buscada es: ");
        printf(" %s\n", V[ind]);
    }
}
