/*Ejercicio 8
Realizar un programa en lenguaje C, que usando funciones óptimas realice lo siguiente:
a) Generar y cargar un arreglo bidimensional de enteros de 3x4.
b) Mostrar en el main la suma de los elementos con valor impar.
c). Ingresar un número de fila y mostrar en el main la cantidad de elementos mayores a 10 (realice una función que
devuelva la cantidad al main).
*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
const int F = 3;                 // Cantidad de filas
const int C = 4;                 // Cantidad de columnas
void generador(int matriz[F][C]) // Iterando entre todas las filas y todas las columnas se puede acceder a todos los elementos y asignarles un numero aleatorio (0-200)
{
    srand(time(NULL));
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            matriz[i][j] = rand() % 21; // Se carga un numero de maximo 20 y minimo 0 a la posicion actual del arreglo
        }
    }
}
int sumarImpares(int matriz[F][C])
{
    int cont = 0;
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            if ((matriz[i][j] % 2) != 0)
            {
                cont++;
            }
        }
    }
    return cont;
}
void seleccionarFila(int matriz[F][C])
{
    int cont = 0, fila;
    printf("Ingrese la fila que desea buscar:\n");
    scanf("%d", &fila);
    for (int i = 0; i < F; i++) // Itera por todas las filas de la columna 3
    {
        if (matriz[fila][i] > 10)
        {
            cont++;
        }
    }
    printf("La cantidad de elementos superiores a 10 es de: %d\n", cont);
}
int main()
{
    int sumaImpar;
    int matriz[F][C];
    generador(matriz);
    sumaImpar = sumarImpares(matriz);
    printf("La suma de los valores impares es de %d\n", sumaImpar);
    seleccionarFila(matriz);
    return 7;
}