/*Ejercicio 7
Cargar aleatoriamente una tabla de 5x4 con números enteros y:
a) Mostrar la suma de cada una de las filas.
b) Calcular el promedio de la tercera columna.
c) Decir cuántos números mayores a 100 se ingresaron*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
const int F = 5;                 // Cantidad de filas
const int C = 4;                 // Cantidad de columnas
void generador(int matriz[F][C]) // Iterando entre todas las filas y todas las columnas se puede acceder a todos los elementos y asignarles un numero aleatorio (0-200)
{
    srand(time(NULL));
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            matriz[i][j] = rand() % 201; // Se carga un numero de maximo 200 y minimo 0 a la posicion actual del arreglo
        }
    }
}
void sumarFila(int matriz[F][C])
{
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        int sum = 0;
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            sum += matriz[i][j];
        }
        printf("La suma de la fila %d tiene como resultado %d\n", i, sum);
    }
}
void promediarColumna(int matriz[F][C])
{
    int sum = 0;
    for (int i = 0; i < F; i++) // Itera por todas las filas de la columna 3
    {
        sum += matriz[i][3];
    }
    printf("El promedio de la columna 3 es de %d\n", (sum / F));
}
void contar(int matriz[F][C])
{
    int cont = 0;
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            if (matriz[i][j] > 100)
            {
                cont++;
            }
        }
    }
    printf("La cantidad de elementos superiores a 100 es de: %d", cont);
}
int main()
{
    int matriz[F][C];
    generador(matriz);
    sumarFila(matriz);
    promediarColumna(matriz);
    contar(matriz);
}