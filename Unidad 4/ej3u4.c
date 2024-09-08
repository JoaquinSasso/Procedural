/*Ejercicio 3
Dada una tabla de N x M números enteros hacer en forma recursiva:
a) Cargar la información ordenada por columnas.
b) Mostrar el contenido de la tabla con formato de reales.*/
#include <stdio.h>
const int F = 2;
const int C = 3;
void cargar(int a[F][C], int i, int j)
{
    if(j == C)
    return;
    if(i < F)
    {
        printf("Ingrese el valor de la componente:(%d,%d)\n", i, j);
        scanf("%d", &a[i][j]);
        return cargar(a, i+1, j);
    }
    else
        return cargar(a, 0, j+1);
}
void mostrar(int a[F][C], int i, int j)
{
    if(i == F)
    return;
    if(j < C)
    {
        printf("|  %.2f  |",((float)a[i][j]));
        return mostrar(a, i, j+1);
    }
    else
    {
        printf("\n");
        return mostrar(a, i+1, 0);
    }
}
int main()
{
    int a[F][C], i = 0, j = 0;
    cargar(a, i, j);
    mostrar(a, i, j);
    return 7;
}