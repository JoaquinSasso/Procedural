/*Ejercicio 5
Un local comercial de ventas de repuestos de automotores desea obtener cierta información sobre todas las ventas
registradas en un periodo de tiempo dado. Para ello el comercio cuenta con los siguientes datos, almacenados en
una estructura, referidos a los 250 artículos que están a la venta: Código, Nombre, Precio Unitario y Stock.
Los datos ingresados de cada una de las ventas efectuadas en ese periodo son: Nombre del artículo, Cantidad de
unidades vendidas. El ingreso de ventas termina con nombre “FIN”.
Se pide realizar un programa en C, que utilizando subprograma óptimos y estructuras adecuadas permita:
a) Procesar las ventas registradas en ese periodo de tiempo
b) Mostrar los nombre de aquellos artículos que quedaron con stock nulo.
c) Indicar el stock de un artículo cuyo código se ingresa por teclado.
d) Indicar el monto total obtenido por las ventas de los productos. */
#include <stdio.h>
#include <string.h>
const int N = 5;
struct datos
{
    int cod;
    char nombre[50];
    float precio;
    int stock;
};
void cargar(struct datos prod[])
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el codigo de producto\n");
        scanf("%d", &prod[i].cod);
        printf("Ingrese el nombre del producto\n");
        fflush(stdin);
        gets(prod[i].nombre);
        printf("Ingrese el precio del producto\n");
        scanf("%f", &prod[i].precio);
        printf("Ingrese el stock del producto\n");
        scanf("%d", &prod[i].stock);
    }
}
float ventas(struct datos prod[])
{
    char nombre[50];
    int cant;
    float ganancia;
    printf("Ingrese el nombre del producto, FIN para terminar\n");
    fflush(stdin);
    gets(nombre);
    while (strcmp(nombre, "FIN") != 0)
    {
        int i = 0;
        printf("Ingrese la cantidad de productos vendidos\n");
        scanf("%d", &cant);
        while ((strcmp(nombre, prod[i].nombre) != 0) && (i <= N))
        {
            i++;
        }
        if (i < N)
        {
            prod[i].stock -= cant;
            ganancia += prod[i].precio;
        }
        else
        {
            printf("No se encontro el producto\n");
        }
        printf("Ingrese el nombre del producto, FIN para terminar\n");
        fflush(stdin);
        gets(nombre);
    }
    return (ganancia);
}
void stockNulo(struct datos prod[])
{
    for (int i = 0; i < N; i++)
    {
        if (prod[i].stock <= 0)
        {
            printf("El producto :%s, se quedo sin stock\n", prod[i].nombre);
        }
    }
}
void comprobarStock(struct datos prod[])
{
    int cod, i = 0;
    printf("Ingrese el codigo del producto para controlar stock\n");
    scanf("%d", &cod);
    while ((cod != prod[i].cod) && (i <= N))
    {
        i++;
    }
    if (i < N)
    {
        printf("El stock del producto es de: %d\n", prod[i].stock);
    }
}
int main()
{
    struct datos prod[N];
    float ganancia;
    cargar(prod);
    ganancia = ventas(prod);
    stockNulo(prod);
    comprobarStock(prod);
    printf("La ganancia con ventas de productos fue de: %.2f", ganancia);
    return 7;
}
/*Bloque de prueba:
1
Jean Azul
7527.65
7
2
Camisa Verde
8652.76
4
3
Gorro Amarillo
2765.86
4
4
Camisa Blanca
8500.12
10
5
Pantalon Cargo Negro
12650.76
6
Pantalon Cargo Negro
6
Camisa Blanca
4
Gorro Amarillo
3
FIN
*/