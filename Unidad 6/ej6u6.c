/*Ejercicio 6
La UNSJ tiene almacenada en el archivo “CarreUni.Dat” información de todas las carreras y de los alumnos que se
inscribieron en los últimos 10 ciclos lectivos.
Por cada carrera se ingresa: código de carrera , nombre de la carrera, cantidad de años de cursado (3 ... 6)
y un arreglo con los 4 totales de inscriptos correspondientes a los ciclos lectivos 2018 a 2021.
El archivo está ordenado en forma secuencial por código de carrera a partir de 1.
Construir un programa que a través del uso adecuado de funciones y un manejo eficiente de archivos permita:
a) Ingresar un código de carrera e indicar: nombre de la carrera y ciclo lectivo con mayor cantidad de inscriptos.
b) Modificar la cantidad de algún/os de los 4 totales de inscriptos correspondientes a los ciclos lectivos
2018 a 2021 para un código de carrera ingresado por teclado.
c) Para el ciclo lectivo 2020 indicar en qué carrera/s se registró la mayor cantidad de inscriptos.
d) Por cada facultad, mostrar un listado con el nombre de cada carrera, cantidad de años de cursado y
total de inscriptos (suma de todos los ciclos lectivos). El listado debe estar ordenado ascendentemente
por el total de inscriptos.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char NArchivo[] = "CarreUni.dat";
const int N = 3;
const int M = 4;
typedef struct
{
    char nombre[50];
    int cursado;
    int inscriptos[4];
} carrera;
void cargar(FILE *archi)
{
    if ((archi = fopen(NArchivo, "w+")) == NULL)
        printf("Hubo un error al crear el archivo\n");
    else
    {
        carrera aux;
        for (int i = 0; i < N; i++)
        {
            printf("Ingrese el nombre de la carrera\n");
            fflush(stdin);
            gets(aux.nombre);
            printf("Ingrese la cantidad de a%cos de cursado\n", 164);
            scanf("%d", &aux.cursado);
            for (int j = 0; j < M; j++)
            {
                printf("Ingrese la cantidad de inscriptos en %d\n", (2018 + j));
                scanf("%d", &aux.inscriptos[j]);
            }
            fwrite(&aux, sizeof(carrera), 1, archi);
        }
        fclose(archi);
    }
}
void buscarMaximo(carrera a, int i, int *maximo, int *indice)
{
    if (i == N)
        return;
    if (a.inscriptos[i] > *maximo)
    {
        *maximo = a.inscriptos[i];
        *indice = i;
    }
    buscarMaximo(a, i + 1, &*maximo, &*indice);
}
void buscarCodigo(FILE *archi)
{
    if ((archi = fopen(NArchivo, "r+")) == NULL)
        printf("Hubo un error al leer el archivo\n");
    else
    {
        int codigo, maximo = -1, i;
        carrera aux;
        printf("Ingrese el codigo de la carrera que quiere buscar\n");
        scanf("%d", &codigo);
        codigo--;
        fseek(archi, (sizeof(carrera) * codigo), SEEK_SET);
        fread(&aux, sizeof(carrera), 1, archi);
        buscarMaximo(aux, 0, &maximo, &i);
        printf("La carrera es: %s y su a%co con mas inscriptos fue: %d\n", aux.nombre, 164, (2018 + i));
        fclose(archi);
    }
}
void modificarCursado(FILE *archi)
{
    if ((archi = fopen(NArchivo, "r+")) == NULL)
        printf("Hubo un error al leer el archivo\n");
    else
    {
        int codigo, cursado;
        carrera aux;
        printf("Ingrese el codigo de la carrera que quiere modificar\n");
        scanf("%d", &codigo);
        codigo--;
        printf("Ingrese el a%co de cursado que quiere modificar\n", 164);
        scanf("%d", &cursado);
        fseek(archi, (sizeof(carrera) * codigo), SEEK_SET);
        cursado -= 2018;
        fread(&aux, sizeof(carrera), 1, archi);
        printf("Ingrese la cantidad de alumnos inscriptos modificada\n");
        scanf("%d", &aux.inscriptos[cursado]);
        fclose(archi);
        if ((archi = fopen(NArchivo, "r+")) == NULL)
            printf("Hubo un error al modificar el archivo\n");
        else
        {
            fseek(archi, (sizeof(carrera) * codigo), SEEK_SET);
            fwrite(&aux, sizeof(carrera), 1, archi);
            fclose(archi);
        }
    }
}
void ordenar(carrera a[], int totales[])
{
    for (int i = 0; i < N; i++)
    {
        totales[i] = 0;
        for (int j = 0; j < M; j++)
        {
            totales[i] += a[i].inscriptos[j];
        }
        int k, cota, auxTotales;
        carrera auxCarrera;
        cota = N - 1;
        k = 1;
        while (k != -1)
        {
            k = -1;
            for (int i = 0; i < cota; i++)
            {
                if (totales[i] > totales[i + 1])
                {
                    auxTotales = totales[i];
                    totales[i] = totales[i + 1];
                    totales[i + 1] = auxTotales;
                    auxCarrera = a[i];
                    a[i] = a[i + 1];
                    a[i + 1] = auxCarrera;
                    k = i;
                }
            }
            cota = k;
        }
    }
}
void mostrarOrdenado(FILE *archi)
{
    if ((archi = fopen(NArchivo, "r+")) == NULL)
        printf("Hubo un error al leer el archivo\n");
    else
    {
        carrera aux[N];
        int totales[N];
        fread(&aux, sizeof(carrera), N, archi);
        ordenar(aux, totales);
        for (int i = 0; i < N; i++)
        {
            printf("La %d carrera es %s, con %d a%cos de cursado y %d inscriptos\n", i, aux[i].nombre, aux[i].cursado, 164, totales[i]);
        }
        fclose(archi);
    }
}
void mostrarMaximos(carrera aux[], int i, int *maximo)
{
    if(i == N)
        return;
    if(aux[i].inscriptos[2] > *maximo)
        *maximo = aux[i].inscriptos[2];
    mostrarMaximos(aux, i+1, &*maximo);
    if(aux[i].inscriptos[2] == *maximo)
        printf("La carrera %s tuvo el maximo de inscriptos en 2020 con %d inscriptos\n", aux[i].nombre, *maximo);
    return;
}
void inscriptos2020(FILE *archi)
{
    if ((archi = fopen(NArchivo, "r+")) == NULL)
        printf("Hubo un error al leer el archivo\n");
    else
    {
        carrera aux[N];
        int maximo = -1;
        fread(&aux, sizeof(carrera), N, archi);
        mostrarMaximos(aux, 0, &maximo);
        fclose(archi);
    }
}
int main()
{
    FILE *archi = NULL;
    cargar(archi);
    buscarCodigo(archi);
    modificarCursado(archi);
    mostrarOrdenado(archi);
    inscriptos2020(archi);
    return 7;
}
/*Lote de prueba:
LCC
5
600
845
300
800
LSI
4
1000
700
900
200
TUPW
3
680
879
900
600
1
3
2020
200
*/