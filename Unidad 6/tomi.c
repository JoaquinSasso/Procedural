#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct
{
    char nya[30];
    int dni;
    int edad;

} socio;

struct nodo
{
    socio persona;
    struct nodo *siguiente;
};

typedef struct nodo *puntero;

void carga(int n, socio *array)
{
    if (array == NULL)
    {
        printf("No se pudo dar memoria");
    }

    for (int i = 0; i < n; i++)
    {
        printf("Ingrese el nombre\n");
        fflush(stdin);
        gets(array[i].nya);
        printf("Ingrese el dni\n");
        scanf("%d", &array[i].dni);
        printf("Ingrese la edad\n");
        scanf("%d", &array[i].edad);
        
    }
}

void mostrar50(int n, socio *array, int i)
{
    if (i < n)
    {
        if (array[i].edad >= 50)
        {
            printf("persona mayor a 50 años:  %s el nombre y apellido y su dni: %d \n", array[i].nya, array[i].dni);
        }
        mostrar50(n, array, i + 1);
    }
}

void buscar(int n, socio *array)
{
    int dnibuscado;
    printf("ingrese el dni a buscar: ");
    scanf("%d", &dnibuscado);
    int i = 0;
    while (i < n && array[i].dni != dnibuscado)
    {
        i++;
    }
    if (i < n)
    {
        printf("Se encontro y se llama: %s", array[i].nya);
    }
    else
    {
        printf("No se encontro\n");
    }
}

void llenarLista(int n, socio array[], puntero *cabeza)
{   int i;
    for (i = 0; i < n; i++)
    {
        if (array[i].edad > 21)
        {
            puntero nuevo = (puntero)malloc(sizeof(struct nodo));
            if (nuevo == NULL)
            {
                printf("No se pudo dar memoria\n");
                return;
            }
            nuevo->persona = array[i];
            nuevo->siguiente = *cabeza;
            *cabeza = nuevo;
        }
    }
}
void mostrarLista(puntero cabeza)
{
    puntero actual = cabeza;
    while (actual != NULL)
    {
        printf("Nombre y apellido: %s\n", actual->persona.nya);
        printf("DNI: %d\n", actual->persona.dni);
        printf("Edad: %d\n", actual->persona.edad);
        actual = actual->siguiente;
    }
}

int main()
{
    int n;
    socio *array;
    puntero *cabeza;
    cabeza = NULL;
    printf("ingrese cantidad de socios; ");
    scanf("%d", &n);
    array = (socio *) malloc(sizeof(socio)*n);
    carga(n, array);
    mostrar50(n, array, 0);
    buscar(n, array);
    llenarLista(n, array, &cabeza);
    mostrarLista(cabeza);
}
/*Lote de prueba
4
Ana Paula
20332291
51
Abel Lomas
42651913
19
Celia Ramos
33185501
29
Jose Petri
22998777
52
*/