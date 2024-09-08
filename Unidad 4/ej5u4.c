/*Realizar un programa en C que, utilizando solo funciones recursivas, permita:
d) Generar un arreglo que cuente para cada lenguaje, los encuestados que lo eligieron.
e) Mostrar el/los lenguajes/s que se eligió por menos de 4000 encuestados.
f) Indicar el lenguaje más elegido. (suponer único)
g) Mostrar el total de encuestas realizadas.
h) Mostrar la cantidad de lenguajes que fueron elegidos por menos de 5000 encuestados y cuantos por más de
9000 encuestados (hacer una función recursiva que devuelva las dos cantidades).
i) Realizar el mapa de memoria cuando se invoca a la función construida en el punto d).*/
#include <stdio.h>
#include <string.h>
const int N = 6;
void cerear(int a[], int i)
{
    if (i == -1)
        return;
    else
    {
        a[i] = 0;
        return cerear(a, i - 1);
    }
}
int cargar(int a[])
{
    int num;
    printf("Ingrese el numero del lenguaje, 0 para detener\n");
    scanf("%d", &num);
    if (num == 0)
        return 0;
    if (num != 0)
    {
        printf("Ingrese la cantidad de votos para el lenguaje %d\n", num);
        scanf("%d", &a[num - 1]);
        return a[num - 1] + cargar(a);
    }
}

void mostrarMin4000YBuscarMax(int a[], int i, int *max, int *iMax)
{
    if (i == -1)
        return;
    else
    {

        if (a[i] > 4000)
        {
            printf("El lenguaje %d tuvo mas de 4000 votos\n", (i + 1));
            if (a[i] > *max)
            {
                *max = a[i];
                *iMax = i;
            }
        }
        return mostrarMin4000YBuscarMax(a, i-1, &*max, &*iMax);
    }
}

void mostrarBasadoEnVotos(int a[], int *mayor, int *menor, int i)
{
    if (i == -1)
        return;
    else if (a[i] < 5000)
        *menor += 1;
    if (a[i] > 9000)
        *mayor += 1;
    return mostrarBasadoEnVotos(a, &*mayor, &*menor, i - 1);
}
int main()
{
    int a[N];
    int i = N - 1, mayor = 0, menor = 0, max = 0, iMax;
    cerear(a, i);
    printf("La cantidad total de votos fue de %d\n", cargar(a));
    mostrarMin4000YBuscarMax(a, i, &max, &iMax);
    printf("El lenguaje mas votado fue el %d\n", (iMax + 1));
    mostrarBasadoEnVotos(a, &mayor, &menor, i);
    printf("Hubieron %d lenguajes con menos de 4000 votos\n", menor);
    printf("Hubieron %d lenguajes con mas de 9000 votos\n", mayor);
    return 7;
}
/*Lote de prueba
1
10500
2
8250
3
2400
4
3460
5
6320
6
9800
0
*/