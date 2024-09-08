/*Ejercicio 10
Un laboratorio abastece a 30 farmacias de la provincia (las farmacias están codificadas con números entre 1 y 30).
Dicho laboratorio comercializa 80 medicamentos (con código desde 100 hasta 179).
En forma ordenada por las farmacias se ingresan las ventas realizadas. Por cada venta se ingresa: código de
medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero)
Codificar un programa en C, que utilizando funciones permita:
a) Realizar la carga de la tabla.
b) Calcular y mostrar el total de unidades vendidas de cada uno de los medicamentos.
c) Dado el código de una farmacia, indicar el código del medicamento más vendido.*/
#include <stdio.h>
const int F = 3; // Cantidad de filas/farmacias
const int C = 5; // Cantidad de columnas/medicamentos
void cerear(int matriz[F][C])
{
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            matriz[i][j] = 0; // Se asignan todos los elementos en 0;
        }
    }
}
void cargar(int matriz[F][C]) // Matriz tiene farmacias/medicamentos
{
    for (int i = 0; i < F; i++) // Itera por todas las farmacias
    {
        int cod, cant;
        printf("Ingrese el codigo del medicamento (100-179), 0 para detener\n");
        scanf("%d", &cod);
        cod -= 100;
        while (cod != -100)
        {
            printf("Ingrese la cantidad de ventas\n");
            scanf("%d", &cant);
            matriz[i][cod] += cant;
            printf("Ingrese el codigo del medicamento (100-179), 0 para detener\n");
            scanf("%d", &cod);
            cod -= 100;
        }
    }
}
void sumarMedicamentos(int matriz[F][C])
{
    int sum;
    for (int i = 0; i < C; i++) // Itera por todos los medicamentos
    {
        sum = 0;
        for (int j = 0; j < F; j++) // Itera por todas las farmacias
        {
            sum += matriz[j][i];
        }
        printf("La cantidad de medicamentos con codigo: %d vendidos es de: %d\n", (i + 1), sum);
    }
}
void maxMedicamento(int matriz[F][C])
{
    int farmacia, maxCant = -1, maxCod;
    printf("Ingrese la farmacia en la que desea buscar el maximo\n");
    scanf("%d", &farmacia);
    for (int i = 0; i < C; i++)
    {
        if(matriz[farmacia][i] > maxCant)
        {
            maxCant = matriz[farmacia-1][i];
            maxCod = i;
        }
    }
    printf("El medicamento mas vendido tiene el codigo: %d\n", (maxCod+100));
}
int main()
{
    int matriz[F][C];
    cerear(matriz);
    cargar(matriz);
    sumarMedicamentos(matriz);
    maxMedicamento(matriz);
    return 7;
}