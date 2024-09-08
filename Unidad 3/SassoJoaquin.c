/*
Sasso Rodriguez Joaquin Nicolas
DNI: 44991289
Registro: E010-272
Carrera: LCC
*/
#include<stdio.h>
#include<math.h>
void cargar(int N, float a[N][N])
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            printf("Ingrese el valor de la fila: %d, columna: %d\n", (i+1), (j+1));
            scanf("%f", &a[i][j]);
        }
    }
}
float sumarTercerCol(int N, float a[N][N])
{
    float sum = 0;
    for(int i = 0; i < N; i++)
        sum += a[i][2];
    return sum;
}
void sumarFila(int N, float a[N], float *sumFilaDos)
{
    for(int j = 0; j < N; j++)
        *sumFilaDos += a[j];
}
int contarPares(int N, float a[N][N])
{
    int cont = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if (fmod(a[i][j], 2) == 0)
                cont++;   
        }
    }
    return cont;
}
int contarPositivosDiagonal(int N, float a[N][N])
{
    int cont = 0;
    for(int i = 0; i < N; i++)
    {
        if(a[i][i] > 0)
           cont++;
    }
    return cont;
}
int main()
{
    int N, positivosDiagonal = 0;
    float sumTercerCol = 0, sumFilaDos = 0;
    printf("Ingrese N\n");
    scanf("%d", &N);
    float a[N][N];
    cargar(N, a);
    sumTercerCol = sumarTercerCol(N, a);
    printf("La suma de los elementos de la tercer columna es de %.2f\n", sumTercerCol);
    sumarFila(N, a[1], &sumFilaDos);
    printf("La suma de los elementos de la fila 2 es de %.2f\n", sumFilaDos);
    printf("La cantidad de elementos pares es de %d\n", contarPares(N, a));
    positivosDiagonal= contarPositivosDiagonal(N, a);
    printf("La cantidad de positivos en la diagonal principal es de: %d\n", positivosDiagonal);
    return 7;
}
/*Lote de prueba
4
3 
58 
-16 
42
4 
-1 
9 
43
5 
14 
-8 
19
6 
87 
4 
6

*/