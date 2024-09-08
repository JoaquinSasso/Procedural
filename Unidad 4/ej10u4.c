/*Ejercicio 10
Una empresa constructora posee la cantidad de litros de combustible que utilizó cada una de las 20 máquinas 
motoniveladoras en los últimos 12 meses. 
Generar una tabla y guardar dicha información, donde las filas representen los meses.
Realizar un programa en C, que usando funciones recursivas muestre:
a) La cantidad total de combustible que la empresa utilizó en el mes 5. (La función recursiva solo debe recibir como 
parámetro la fila del mes indicado).
b) El gasto promedio de combustible de cada una de las máquinas.
c) El mes con mayor gasto de combustible de cada una de las máquinas.
Nota: Hacer mapa de memoria para un subprograma*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int F = 12; //Meses
const int C = 20; //Maquinas
void cargar(int a[F][C], int i, int j)
{
    if(i == F)
        return;
    else if(j < C)
    {
        a[i][j] = rand() % 45;
        //printf("%d\n", a[i][j]);
        return cargar(a, i, j+1);
    }
    else
        return cargar(a, i+1, 0);
}
int gasto(int a[C], int i)
{
    if(i == C)
        return 0;
    else
        return a[i] + gasto(a, i+1);
}
int suma(int a[F][C], int i, int j)
{
    if(i == F)
        return 0;
    else
        return a[i][j] + suma(a, i+1, j);
}
void promedio(int a[F][C], int i, int j)
{
    int total = 0;
    if(j == C)
        return;
    else
    {
        total = suma(a, i, j) / F;
        printf("El promedio de la maquina %d es de: %d litros mensuales\n", j+1, total);
        return promedio(a, 0, j+1);
    }
}
void maxYminMensual(int a[F][C], int i, int j, int *iMax, int *iMin, int *min, int *max)
{
    if(j == C)
        return;
    else if(i < F)
    {
        if(a[i][j] < *min)
        {
            *min = a[i][j];
            *iMin = i;
        }
        if(a[i][j] > *max)
        {
            *max = a[i][j];
            *iMax = i;
        }
        return maxYminMensual(a, i+1, j, &*iMax, &*iMin, &*min,&* max);
    }
    else
    {
        printf("El mes con mas consumo para la maquina %d fue: %d\n", j+1, *iMax);
        printf("El mes con menor consumo para la maquina %d fue: %d\n\n", j+1, *iMin);
        *max = 0;
        *min = 999;
        return maxYminMensual(a, 0, j+1, &*iMax, &*iMin, &*min, &*max);
    }
}
int main()
{
    int a[F][C], i = 0;
    int max = 0, min = 999, iMax, iMin;
    srand(time(NULL)); //Activar para volver cada ejecucion aleatoria, desactivar para mantener ejecuciones constantes
    cargar(a, i, i);
    printf("El gasto de comustible en el mes 5 es de: %d\n", gasto(a[4], i));
    promedio(a, i, i);
    maxYminMensual(a, i, i, &iMax, &iMin, &min, &max);
    return 7;
}