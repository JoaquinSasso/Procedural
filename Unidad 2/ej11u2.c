/*Ejercicio 11
Un supermercado ingresa las ventas de los últimos 6 meses, realizadas en los 8 departamentos de venta que posee.
Por cada venta se ingresa mes (1 ... 12), número de departamento (1 ... 8) e importe. Las ventas no traen ningún
orden particular. Realizar un programa en C, que a través de funciones permita:
a) Almacenar la información en una tabla que posea por cada mes, el importe total de ventas de cada departamento.
La carga finaliza con mes igual a cero.
b) Dado un mes, mostrar en el programa principal el departamento que menos vendió (suponer único).
c) Mostrar el importe promedio de venta del supermercado.
d) Dado un mes y un departamento, indicar si supera el importe promedio del ítem anterior.*/
#include <stdio.h>
const int F = 2; //Departamentos
const int C = 3; //Meses
void cerear(float matriz[F][C])
{
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            matriz[i][j] = 0; // Se asignan todos los elementos en 0;
        }
    }
}
void cargar(float matriz[F][C]) // Matriz tiene departamentos/meses
{
    int dep, mes;
    float imp;
    printf("Ingrese el mes, 0 para detener\n");
    scanf("%d", &mes);
    while (mes != 0)
    {
        printf("Ingrese el departamento\n");
        scanf("%d", &dep);
        printf("Ingrese la el importe de ventas\n");
        scanf("%f", &imp);
        matriz[dep - 1][mes - 1] += imp;
        printf("Ingrese el mes, 0 para detener\n");
        scanf("%d", &mes);
    }
}
int minimoMensual(float matriz[F][C])
{
    int mes, minDep;
    float minCant = 999999;
    printf("Ingrese el mes en el que desea buscar el departamento con las menor ventas\n");
    scanf("%d", &mes);
    for (int i = 0; i < C; i++)
    {
        if(matriz[i][mes-1] < minCant)
        {
            minCant = matriz[i][mes-1];
            minDep = i;
        }
    }
    return minDep+1;
}
float promedioSupermercado(float matriz[F][C])
{
    float sum = 0, prom;
    for (int i = 0; i < F;  i++)
    {
        for (int j = 0; i < C; j++)
        {
            sum += matriz[i][j];
        }
    }
    prom = (sum/F)/C;
    printf("El promedio de importe mensual por departamento es de: %.2f\n", prom);
    return prom;
}
void compararProm(float matriz[F][C], float prom)
{
    int dep, mes;
    printf("Ingrese el departamento que desea comprobar\n");
    scanf("%d", &dep);
    printf("Ingrese el mes que desea comprobar\n");
    scanf("%d", &mes);
    if(matriz[dep-1][mes-1] <= prom)
    {
        printf("El departamento no supero el promedio mensual");
    }
    else
        printf("El departamento supero el promedio mensual");
}
int main()
{
    float matriz[F][C], prom;
    cerear(matriz);
    cargar(matriz);
    printf("El departamento %d tuvo el minimo de ventas mensual\n", minimoMensual(matriz));
    prom = promedioSupermercado(matriz);
    compararProm(matriz, prom);
    return 7;
}