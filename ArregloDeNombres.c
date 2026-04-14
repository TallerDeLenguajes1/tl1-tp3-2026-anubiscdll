#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MostrarPersonas(char** V);
void BuscarNombre(char** V, int ind);
int main (){
    char* buff = (char *)malloc(50*sizeof(char));
    char* vector[5];
    char mensaje[] = "Ingrese el nombre:" ;
    for (int i = 0; i<5;i++ ){
        puts (mensaje);
        gets(buff);
        vector[i]= (char *) malloc((strlen(buff)+1) * sizeof(char));
        strcpy(vector[i],buff);
    }
    MostrarPersonas(vector);

    puts("Ingrese un numero del 0 al 4 para buscar el nombre: ");
    int num;
    scanf("%d",&num);
    BuscarNombre(vector,num);
    free(buff);
    for (int i = 0; i < 5; i++){
        free(vector[i]);
    }
    return 0;
}
void MostrarPersonas(char** V){
    for (int i = 0;i<5; i++){
        puts("El nombre es: ");
        printf(" %s\n",V[i]);
    }
}
void BuscarNombre(char** V, int ind){
    if (ind <0 || ind > 4) {
        puts("no se encontró el valor buscado");
    }else {
    puts("El nombre en la posicion buscada es: ");
    printf(" %s\n",V[ind]);
    }
}