/*Ejercicio 1
Crear un arreglo de 50 números enteros y cargarlo generando cada numero de manera aleatoria.
Codificar un programa en C que permita:
1. Indicar en el main si cantidad de números mayores a cero es mayor o igual a la cantidad de números menores a
cero.
2. Indicar en el main, la sumatoria de las componentes que se encuentren en las posiciones pares y la sumatoria de
las que está en posiciones impares.
3. Leer un número e indicar si se encuentra en el arreglo indicar su posición (puede estar repetido). */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
const int N = 50;
void generador(int arreglo[N]) // Iterando entre todas las componentes y asignarles un numero aleatorio (0-20)
{
    srand(time(NULL));
    for (int i = 0; i < N; i++) // Itera por todas las componentes del arreglo
    {
        arreglo[i] = rand() % 21; // Se carga un numero de maximo 20 y minimo 0 a la posicion actual del arreglo
    }
}
void sumador(int arreglo[N], int *sumPares, int *sumImpares)
{
    for (int i = 0; i < N; i++) // Itera por todas las componentes del arreglo
    {
        if(i % 2 != 0)
        {
            *sumImpares+= arreglo[i];
        }
        else
        {
            *sumPares+= arreglo[i];
        }
    }
}
void buscar(int arreglo[])
{  
    int num, i = 0;
    printf("Ingrese el numero que desea buscar\n");
    scanf("%d", &num);
    arreglo[N+1] = -1;
    while ((num != arreglo[i]) && (i <= N))
    {
        i++;
    }
    if(i < N){
        printf("El numero se encuentra en el indice: %d\n", i);
    }
    else
    {
         printf("El numero no se encuentra en el arreglo\n");
    }
}
int main()
{
    int arreglo[N];
    int sumPares = 0, sumImpares = 0;
    generador(arreglo);
    sumador(arreglo, &sumPares, &sumImpares);
    printf("La sumatoria de pares es de: %d y la de impares es de: %d\n", sumPares, sumImpares);
    buscar(arreglo);
    return 7;
}