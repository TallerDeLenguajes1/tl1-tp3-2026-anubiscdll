#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void MostrarPersonas(char** V);
int BuscarNombre(char** V, char* nombre);
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
    puts("Ingrese un nombre a buscar: ");
    gets(buff);
    int busc = BuscarNombre(vector, buff);
    if (busc == -1) {
        puts("No se encontro el nombre");
    } else {
        puts("Se encontro:");
        printf(" %s\n", vector[busc]);
    }
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

int BuscarNombre(char** V, char* nombre) {
    for (int i = 0; i < 5; i++) {
        if (strstr(V[i], nombre)) {
            return i;
        }
    }
    return -1;
}