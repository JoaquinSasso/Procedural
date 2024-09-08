#include "stdio.h"
#include "stdlib.h"

typedef struct
{
    int edad;
    char nombre[50];
} data;
struct nodo
{
    data datos;
    struct nodo *sig;
};
typedef struct nodo *puntero;
void cargarOrdenado(puntero *cab)
{
    int edad;
    puntero nuevo, actual, anterior;
    printf("Ingrese edad, -1 para terminar\n");
    scanf("%d", &edad);
    if (edad == -1)
        return;
    nuevo = (puntero)malloc(sizeof(struct nodo));
    nuevo->datos.edad = edad;
    printf("Ingrese el nombre de la persona\n");
    fflush(stdin);
    gets(nuevo->datos.nombre);
    actual = *cab;
    anterior = NULL;
    while ((actual != NULL) && (actual->datos.edad < edad))
    {
        anterior = actual;
        actual = actual->sig;
    }

    if (anterior == NULL)
    {
        nuevo->sig = *cab;
        *cab = nuevo;
    }
    else
    {
        nuevo->sig = actual;
        anterior->sig = nuevo;
    }

    cargarOrdenado(cab);
}
void cargarCabeza(puntero *cab)
{
    int edad;
    puntero nuevo;
    printf("Ingrese edad, -1 para terminar\n");
    scanf("%d", &edad);
    if (edad == -1)
        return;
    nuevo = (puntero)malloc(sizeof(struct nodo));
    nuevo->datos.edad = edad;
    printf("Ingrese el nombre de la persona\n");
    fflush(stdin);
    gets(nuevo->datos.nombre);
    nuevo->sig = *cab;
    *cab = nuevo;
    cargarCabeza(&*cab);
}
void cargarFinal(puntero *cab)
{
    int edad;
    puntero nuevo, actual;
    printf("Ingrese edad, -1 para terminar\n");
    scanf("%d", &edad);
    if (edad == -1)
        return;
    nuevo = (puntero)malloc(sizeof(struct nodo));
    nuevo->datos.edad = edad;
    printf("Ingrese el nombre de la persona\n");
    fflush(stdin);
    gets(nuevo->datos.nombre);
    actual = *cab;
    if(actual == NULL)
    {
        nuevo->sig = *cab;
        *cab = nuevo;
    }
    else
    {
        while (actual->sig !=NULL)
        {
            actual = actual->sig;
        }
        nuevo->sig = actual->sig;
        actual->sig = nuevo;
    }
    cargarFinal(&*cab);
}
void mostrar(puntero actual)
{
    if (actual == NULL)
        return;
    printf("%s tiene una edad de %d\n", actual->datos.nombre, actual->datos.edad);
    mostrar(actual->sig);
}
int main()
{
    puntero cab = NULL;
    cargarCabeza(&cab);
    //cargarOrdenado(&cab); //Deberia quedar ordenado
    //cargarFinal(&cab); //Deberia quedar al reves de cargar a la cabeza
    mostrar(cab);
    return 0;
}
/*Lote de prueba
20
Juan
25
Carlos
32
Marta
10
Felipe
31
Matias
27
Lourdes
24
Martina
18
Laura
42
Julian
-1
*/