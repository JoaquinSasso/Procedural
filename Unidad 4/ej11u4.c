/*Ejercicio 11
Dadas dos matrices cuadradas A y B de componentes enteras positivas y de dimensión N, realizar un algoritmo en C
que utilizando funciones recursivas permita:
a) Cargar cada una de las matrices (función reusable).
b) Calcular el producto escalar de una fila de A por una fila de B. Ingresar por teclado el número de cada fila.
c) Calcular el producto escalar de una columna de A por una columna de B. Ingresar por teclado el número de las
columnas.
Nota: validar el ingreso de datos. Hacer mapa de memoria para un subprograma*/
#include <stdio.h>
const int N = 2;

void cargar(int a[N][N], int i, int j)
{
    if (j == N)
        return;
    if (i < N)
    {
        printf("Ingrese el valor de la componente:(%d,%d)\n", i, j);
        scanf("%d", &a[i][j]);
        return cargar(a, i + 1, j);
    }
    else
        return cargar(a, 0, j + 1);
}
void mostrar(int a[N][N], int i, int j)
{
    if (i == N)
    {
        printf("\n");
        return;
    }
    else if (j < N)
    {
        printf("|  %d  |", a[i][j]);
        return mostrar(a, i, j + 1);
    }
    else
    {
        printf("\n");
        return mostrar(a, i + 1, 0);
    }
}
int escalarFila(int a[N], int b[N], int i)
{
    if(i == N)
        return 0;
    else
        return (a[i] * b[i]) + escalarFila(a, b, i+1);
}
int escalarColumna(int a[N][N], int  b[N][N], int i, int fA, int fB)
{
    if(i == N)
        return 0;
    else
        return (a[i][fA] * b[i][fB]) + escalarColumna(a, b, i+1, fA, fB);
}
int main()
{
    int a[N][N], b[N][N], i = 0, fA, fB;
    printf("Se solicitaran los datos de A\n");
    cargar(a, i, i);
    cargar(b, i, i);
    printf("Se solicitaran los datos de B\n");
    mostrar(a, i, i);
    mostrar(b, i, i);
    printf("Ingrese la fila de A para calcular el escalar\n");
    scanf("%d", &fA);
    printf("Ingrese la fila de B para calcular el escalar\n");
    scanf("%d", &fB);
    printf("El escalar es: %d\n", escalarFila(a[fA-1], b[fB-1], i));
    printf("Ingrese la columna de A para calcular el escalar\n");
    scanf("%d", &fA);
    printf("Ingrese la columna de B para calcular el escalar\n");
    scanf("%d", &fB);
    printf("El escalar es: %d\n", escalarColumna(a, b, i, fA-1, fB-1));
    return 7;
}
/*Lote de prueba
Para A =    1   3
            2   5

Para B =    3   4
            2   3
1
2
3
5
3
2
4
3

*/