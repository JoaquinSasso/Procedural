/*Ejercicio 2
Dado un arreglo de N componentes enteras hacer en forma recursiva:
a) Cargar el arreglo.
b) Mostrar el arreglo en forma invertida.
c) Decir cuántas componentes son positivas y cuantas negativas. (hacer una función que devuelva ambos 
resultados).
Nota: Hacer mapa de memoria para un subprograma*/
#include <stdio.h>
const int N = 3;
void cargar(int a[], int i) //Consigna A
{
    if (i == N)
        return;
    else
    {
        printf("Ingrese el valor de la componente %d \n", i);
        fflush(stdin);
        scanf("%d", &a[i]);
        return cargar(a, i + 1);
    }
}
void mostrarInvertido(int a[], int i) //Consigna B
{
    if (i == -1)
        return;
    else
    {
        printf("%d", a[i]);
        return mostrarInvertido(a, i - 1);
    }
}
void contarPosYNeg(int a[], int i, int *contPos, int *contNeg) //Consigna C
{
    if(i == -1)
    return;
    else
    {
        if(a[i] > 0)
        *contPos += 1;
        if(a[i] < 0)
        *contNeg += 1;
        return contarPosYNeg(a, i-1, &*contPos, &*contNeg);
    }
}
int main()
{
    int i = 0, a[N], contPos = 0, contNeg = 0;
    cargar(a, i);
    i = N-1;
    mostrarInvertido(a, i);
    contarPosYNeg(a, i, &contPos, &contNeg);
    printf("\nLa cantidad de postivos es de %d", contPos);
    printf("\nLa cantidad de negativos es de: %d", contNeg);
    return 7;

}
/*Lote de prueba
5
-8
7
*/