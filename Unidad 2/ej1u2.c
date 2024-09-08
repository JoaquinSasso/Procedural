/*Ejercicio 1
Generar un arreglo con 20 números enteros y codificar un programa en C que permita:
a) Indicar si alguno de los números generados es cero.
b) Escribir el contenido de las componentes que se encuentren en las posiciones pares.
c) Indicar cantidad de números pares que contiene.
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
const int N = 20;
void generador(int arreglo[])
{
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        arreglo[i] = rand() % 21; // Se carga un numero de maximo 20 y minimo 0 a la posicion actual del arreglo
    }
}
void muestra(int arreglo[]) // Muestra el valor de todas las componentes del arreglo. Consigna 2
{
    for (int i = 0; i < N; i++) // Itera por todos los elementos del arreglo
    {
        printf("La componente %d, tiene un valor de: %d\n", (i + 1), arreglo[i]);
    }
    return;
}
void buscar(int arreglo[])
{
    int i = 0;
    while ((arreglo[i] != 0) && (i <= N))
    {
        {
            i++;
        }
    }
    if (i == N)
    {
        printf("No se encontro un 0\n");
    }
    else
    {
        printf("Se encontro un 0\n");
    }
}
void muestraPares(int arreglo[])
{
    for (int i = 2; i < N; i += 2)
    {
        printf("La componente %d tiene valor %d\n", i, arreglo[i]);
    }
}
void contadorPares(int arreglo[])
{
    int contador = 0;
    for (int i = 0; i < N; i++)
    {
        if (((arreglo[i]) % 2) == 0)
        {
            contador++;
        }
    }
    printf("La cantidad de componentes con numeros pares es de %d\n", contador);
}
int main()
{
    int arreglo[N];
    generador(arreglo);
    muestra(arreglo);
    buscar(arreglo);
    muestraPares(arreglo);
    contadorPares(arreglo);
    return 1;
}