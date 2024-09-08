/*Ejercicio 4
Una Empresa Constructora procesa el archivo ASPIRANTES.DAT. Este archivo almacena la información de los aspirantes a
un nuevo barrio a construirse: número aspirante, apellido y nombre, cantidad de Integrantes del grupo familiar,
cantidad de cuotas e importe de cuota.
El archivo no posee ningún orden en particular.
Se pide realizar un programa óptimo que a través del uso de funciones genere un menú de opciones que responda a las siguientes
solicitudes:
a) Listar los aspirantes que han pagado más de $77.500, indicando apellido y nombre, cantidad de cuotas e importe total abonado
a la empresa.
b) Dado un apellido y nombre que se ingresa por teclado, indicar la cantidad de cuotas y la cantidad de integrantes.
c) La empresa ha generado un método de selección, que consiste en otorgar una casa a los aspirantes que tienen familia numerosa
(cantidad de integrantes del grupo familiar mayor a cinco). Generar una nueva estructura que almacene el apellido y nombre y
cantidad de integrantes de los aspirantes que cumplen con la condición.
d) Utilizando la estructura generada, mostrar en forma ordenada alfabéticamente, nombre y apellido de cada uno de los aspirantes
seleccionados.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char NArchivo[] = "ASPIRANTES.dat";
const char NSubArchivo[] = "SELECCIONADOS.dat";
typedef struct
{
    int num;
    char nombre[80];
    int familiares;
    int cuotas;
    float importe;
} aspirante;
typedef struct
{
    char nombre[80];
    int familiares;
} seleccionado;
typedef struct nodo
{
    aspirante datos;
    struct nodo *sig;
} lista;

void cargar(FILE *archi)
{
    aspirante a;
    fpos_t x;
    printf("Ingrese el numero del aspirante, 0 para detener\n");
    scanf("%d", &a.num);
    if (a.num == 0)
        return;
    fseek(archi, 0, SEEK_END);
    fgetpos(archi, &x);
    printf("Ingrese el nombre\n");
    fflush(stdin);
    gets(a.nombre);
    printf("Ingrese cantidad de integrantes del grupo familiar\n");
    scanf("%d", &a.familiares);
    printf("Ingrese cantidad de cuotas abonadas\n");
    scanf("%d", &a.cuotas);
    printf("Ingrese el importe de las cuotas\n");
    scanf("%f", &a.importe);
    fwrite(&a, sizeof(aspirante), 1, archi);
    cargar(archi);
}
void listar(FILE *archi)
{
    aspirante a;
    if ((archi = fopen(NArchivo, "rb")) == NULL)
        printf("Hubo un error al abrir el archivo\n");
    else
    {
        while (fread(&a, sizeof(aspirante), 1, archi))
        {
            if ((a.importe * a.cuotas) > 77500)
                printf("El aspirante %s, abono en %d cuotas un total de %.2f\n", a.nombre, a.cuotas, (a.cuotas * a.importe));
        }
    }
    return;
}
void buscar(FILE *archi)
{
    aspirante a;
    char nombre[80];
    printf("Ingrese el nombre que desea buscar\n");
    fflush(stdin);
    gets(nombre);
    if ((archi = fopen(NArchivo, "rb")) == NULL)
        printf("Hubo un error al abrir el archivo\n");
    else
    {
        while (fread(&a, sizeof(aspirante), 1, archi) && !(strcmp(a.nombre, nombre) == 0))
            ;
        if (strcmp(a.nombre, nombre) == 0)
            printf("El aspirante %s, abono %d cuotas y su grupo familiar es de %d integrantes\n", a.nombre, a.cuotas, a.familiares);
    }
    return;
}
void seleccionar(FILE *archi, FILE *subArchi)
{
    aspirante a;
    seleccionado s;
    if ((archi = fopen(NArchivo, "rb")) == NULL)
        printf("Hubo un error leyendo original\n");
    else
    {
        while ((fread(&a, sizeof(aspirante), 1, archi)))
        {
            if (a.familiares > 5)
            {
                strcpy(s.nombre, a.nombre);
                s.familiares = a.familiares;
                fwrite(&s, sizeof(seleccionado), 1, subArchi);
            }
        }
    }
}
void mostrar(FILE *archi)
{
    aspirante a;
    while (fread(&a, sizeof(aspirante), 1, archi))
    {
        printf("El nombre del aspirante es %s\n", a.nombre);
    }
    fclose(archi);
}
void mostrarSeleccionados(FILE *archi)
{
    seleccionado a;
    while (fread(&a, sizeof(seleccionado), 1, archi))
    {
        printf("El nombre del aspirante es %s, y su grupo familiar es de %d integrantes\n", a.nombre, a.familiares);
    }
    fclose(archi);
}
void ordenarLista(lista *cab)
{
    aspirante aux;
    lista *k, *cota, *p;
    k = NULL;
    cota = NULL;
    while (k != cab)
    {
        k = cab;
        p = cab;
        while (p->sig != cota)
        {
            if ((strcmp(p->datos.nombre, p->sig->datos.nombre)) > 0)
            {
                aux = p->sig->datos;
                p->sig->datos = p->datos;
                p->datos = aux;
                k = p;
            }
            p = p->sig;
        }
        cota = k->sig;
    }
}
void ordenar(FILE *archi)
{
    fpos_t x;
    lista *cab = NULL, *nuevo, *actual;
    aspirante aux;
    if ((archi = fopen(NArchivo, "rb")) == NULL)
        printf("Hubo un error al abrir el archivo original\n");
    else
    {
        while (fread(&aux, sizeof(aspirante), 1, archi))
        {
            nuevo = (lista *)malloc(sizeof(lista));
            nuevo->datos = aux;
            nuevo->sig = cab;
            cab = nuevo;
        }
        fclose(archi);
        ordenarLista(cab);
        if ((archi = fopen(NArchivo, "wb")) == NULL)
            printf("Hubo un error al sobreescribir el archivo\n");
        else
        {
            actual = cab;
            fseek(archi, 0, SEEK_END);
            fgetpos(archi, &x);
            while (actual != NULL)
            {
                fwrite(&actual->datos, sizeof(aspirante), 1, archi);
                actual = actual->sig;
            }

            fclose(archi);
        }
    }
}
int main()
{
    FILE *archi, *subArchi;
    int opcion;
    printf("Ingrese la opciion del menu:\n0: SALIR\n1:Cargar\n2:Listar aspirantes que abonaron mas de 77500\n3:Buscar por nombre\n4:Generar archivo con los aspirantes seleccionados\n5:Mostrar ordenado alfabeticamente\nOpcion: ");
    scanf("%d", &opcion);
    while (opcion != 0)
    {
        switch (opcion)
        {
        case 1:
            if ((archi = fopen(NArchivo, "wb")) == NULL)
                printf("Hubo un error al crear el archivo\n");
            else
            {
                cargar(archi);
                fclose(archi);
            }
            break;
        case 2:
            listar(archi);
            fclose(archi);
            break;
        case 3:
            buscar(archi);
            fclose(archi);
            break;
        case 4:
            if ((subArchi = fopen(NSubArchivo, "wb")) == NULL)
                printf("Hubo un error al crear el archivo secundario\n");
            else
            {
                seleccionar(archi, subArchi);
                fclose(archi);
                fclose(subArchi);
                if ((subArchi = fopen(NSubArchivo, "rb")) == NULL)
                    printf("Hubo un error al leer el archivo ordenado\n");
                else
                    mostrarSeleccionados(subArchi);
            }
            break;
        case 5:
        {
            ordenar(archi);
            if ((archi = fopen(NArchivo, "rb")) == NULL)
                printf("Hubo un error al leer el archivo ordenado\n");
            else
                mostrar(archi);
        }
        break;
        default:
            printf("El numero ingresado no corresponde a una opcion\n");
            break;
        }
        printf("Ingrese la opciion del menu:\n0: SALIR\n1:Cargar\n2:Listar aspirantes que abonaron mas de 77500\n3:Buscar por nombre\n4:Generar archivo con los aspirantes seleccionados\n5:Mostrar ordenado alfabeticamente\nOpcion: ");
        scanf("%d", &opcion);
    }
    return 7;
}
/*
Numero de Aspirante
Nombre
Grupo familiar
Cuotas
Importe
Lote de prueba
1
348
Sasso Joaquin
4
10
8000.23
384
Reynoso Nicolas
2
3
9000.67
110
Valiente Lucas
5
30
10000.89
280
Reta German
6
19
2000.89
0
*/