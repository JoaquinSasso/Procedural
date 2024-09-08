/*Ejercicio 2
Se cuenta con información de los socios de un club provincial: DNI, edad, tipo y estado: “Activo “o “Inactivo”. Los tipos de socios están determinados por letras: ‘A’: Socio deportivo, …, ‘J’: Socio Jubilado. La cantidad de socios se ingresa por teclado.
Escribir un programa en C que permita:
a) Cargar los datos en una estructura adecuada. (Validar el ingreso, suponiendo que el tipo de socio varía entre ‘A’ y ‘J ‘)
b) Para un tipo de socio determinado, mostrar los DNI de los socios que tienen edad mayor a 40. Generar una estructura auxiliar.
c) Realizar un listado que muestre, cuantas personas se encuentran activas, para cada tipo de socio. Generar una estructura auxiliar.*/
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct persona
{
    int edad;
    int estado;
    char tipo;
    int dni;
} socio;
void cargar(socio *a, int i, int n)
{
    char tipo, estado[8];
    printf("Ingrese el tipo de socio (A o J)\n");
    scanf("%c", &tipo);
    if(!((tipo <= 'J') && (tipo >= 'A')) || !((tipo <= 'j') && (tipo >= 'a')) || (i == n))
        return;
    else
    {
        a[i].tipo = tipo;
        printf("Ingrese el DNI\n");
        scanf("%d", &a[i].dni);
        printf("Ingrese la edad\n");
        scanf("%d", &a[i].edad);
        printf("Ingrese el estado\n");
        fflush(stdin);
        gets(estado);
        if (strcmp(estado, "Activo") == 0)
            a[i].estado = 1;
        if (strcmp(estado, "Inactivo") == 0)
            a[i].estado = 0;
    }
}
void subTipo(socio *a, socio *b, int i, int n)
{
    char tipo;
    printf("Ingrese el tipo de socio\n");
    scanf("%c", &tipo);
    
}
int main()
{
    int n, i = 0;
    printf("Ingrese la cantidad de socios\n");
    scanf("%d", &n);
    socio *a, *b, *c;
    a = (socio *)malloc(sizeof(socio) * n);
    cargar(a, i, n);
    subTipo(a, b, i, n);
    return 7;
}