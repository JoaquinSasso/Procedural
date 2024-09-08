/*Ejercicio 2
Un local comercial de ventas de repuestos de automotores desea obtener cierta información sobre todas las ventas
registradas en un periodo de tiempo dado. El comercio cuenta con 250 artículos, almacenados en una estructura y
de los cuales se conocen los siguientes datos: Código, Nombre, Precio Unitario y Stock.
Se procesan las ventas y los datos ingresados de cada una son: Nombre del artículo, Cantidad de unidades vendidas
(con esta información actualizar el stock de cada artículo). El ingreso de ventas termina con nombre igual “FIN”.
Se pide realizar un programa en C, que utilizando subprogramas óptimos y estructuras adecuadas permita:
1. Procesar las ventas registradas en ese periodo de tiempo.
2. Mostrar en el main la cantidad de artículos que quedaron con stock nulo y cuantos tienen un precio mayor a
$7000.
3. Imprimir los nombres de los 20 artículos que quedaron con mayor stock.
4. Indicar para cada artículo el monto total obtenido por ventas.
*/
#include <stdio.h>
#include <string.h>
const int N = 4;
struct articulo
{
    int cod;
    char nombre[80];
    float precio;
    int stock;
    float montoTotal;
};
void cargar(struct articulo arreglo[])
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el codigo del articulo\n");
        scanf("%d", &arreglo[i].cod);
        printf("Ingrese el nombre del articulo\n");
        getchar();
        gets(arreglo[i].nombre);
        printf("Ingrese el precio del articulo\n");
        scanf("%f", &arreglo[i].precio);
        printf("Ingrese el stock del articulo\n");
        scanf("%d", &arreglo[i].stock);
        arreglo[i].montoTotal = 0;
    }
}
int buscar(char nombre[], struct articulo arreglo[])
{
    strcpy(arreglo[N + 1].nombre, " ");
    int i = 0;
    while ((strcmp(nombre, arreglo[i].nombre) != 0) && (i <= N))
    {
        i++;
    }
    return i;
}
void cargarVentas(struct articulo arreglo[]) // Son cargas distintos, uno carga los datos de los articulos y el otro las ventas
{
    int cant, indice;
    char nombre[80];
    printf("Ingrese el nombre del articulo, FIN para terminar\n");
    fflush(stdin);
    gets(nombre);
    while (strcmp(nombre, "FIN") != 0)
    {
        printf("Ingrese la cantidad de articulos vendidos\n");
        scanf("%d", &cant);
        indice = buscar(nombre, arreglo);
        arreglo[indice].stock -= cant;
        arreglo[indice].montoTotal += cant*arreglo[indice].precio;
        printf("Ingrese el nombre del articulo, FIN para terminar\n");
        getchar(); // Use el getchar en vez de fflush(stdin), si quiere lo cambio
        gets(nombre);
    }
}
