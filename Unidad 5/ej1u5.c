/*Ejercicio 1
Escribir un programa en lenguaje C que usando funciones permita:
a) Crear y cargar 2 arreglos dinámicos de componentes enteras MxM (mismo tamaño) ingresada por teclado.
b) Calcular el producto escalar.
El producto escalar es una operación donde al multiplicar dos arreglos se obtiene un único valor.
A * B = A[0] * B[0] + A[1] * B[1] +…+ A[N-1] * B[N-1]
c) Generar una nueva estructura con los valores pares contenidos en uno de los arreglos (realizar un subprograma
que solicite memoria para la nueva estructura y la devuelva cargada).
d) Realizar el mapa de memoria con el siguiente lote de prueba, específicamente al momento de la carga de un
vector, creación y carga de la nueva estructura.
Arreglo A={1, 2, 3}
Arreglo B={4, 5, 6}*/
#include <stdio.h>
#include <malloc.h>
#define M 3
void cargar(int arre[M], int i)
{
    if (i == M)
        return;
    else
    {
        printf("Ingrese la componente: [%d]\n", i);
        scanf("%d", &arre[i]);
        return cargar(arre, i + 1);
    }
}
void mostrar(int *arre, int i)
{
    if (i == M)
        return;
    else
    {
        printf("La compomnente:[%d] es %d\n", i, arre[i]);
        return mostrar(arre, i + 1);
    }
}
void productoEscalar(int *a, int *b, int i, int *res)
{
    if (i == M)
        return;
    else
    {
        *res += a[i] * b[i];
        productoEscalar(a, b, i + 1, res);
    }
}
void subArreglo_Pares(int *arre, int *sub)
{
    int cont = 0, j = 0;
    for (int i = 0; i < M; i++)
    {
        if ((arre[i] % 2) == 0)
            cont++;
    }
    sub = (int *)malloc(sizeof(int) * cont);
    for (int i = 0; i < M; i++)
    {
        if ((arre[i] % 2) == 0)
        {
            sub[j] = arre[i];
            j++;
        }
    }
    for (int i = 0; i < cont; i++)
    {
        printf("La componente:[%d] es %d\n", i, sub[i]);
    }
    return;
}
int main()
{
    int *arre, *arre2, i = 0, *sub, res = 0;
    arre = (int *)malloc(sizeof(int) * M);
    arre2 = (int *)malloc(sizeof(int) * M);
    cargar(arre, i);
    cargar(arre2, i);
    mostrar(arre, i);
    productoEscalar(arre, arre2, i, &res);
    printf("El producto escalar es:%d\n", res);
    subArreglo_Pares(arre, sub);
    return 7;
    free(arre);
    free(arre2);
    free(sub);
    arre = NULL;
    arre2 = NULL;
    sub = NULL;
}
/*Lote de prueba
1
2
3
4
5
6
*/
