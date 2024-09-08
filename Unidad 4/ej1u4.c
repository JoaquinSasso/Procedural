#include <stdio.h>
void FuncionA(int n)
{
    if (n)
    {
        printf("%d", n % 10);
        n = (int)n / 10;
        FuncionA(n);
    }
}
int FuncionB(int n)
{
    if (n == 0)
        return n;
    else
        return (FuncionB(n / 10)) + (n % 10);
}
int FuncionC(int x[], int n, int dato)
{
    if(n == 0)
    {
        if (dato > x[n])
            return x[0];
        else
            return dato;
    }
    else
    {
            if (dato > x[n])
            return FuncionC(x, n - 1, x[n]);
        else
            return FuncionC(x, n - 1, dato);
    }
}
int main()
{
    int a = 6745, b = 5679, c[4], n = 3, dato = 50;
    printf("Ingrese el numero de la funcion A\n");
    //scanf("%d", &a);
    FuncionA(a);
    printf("\nIngrese el numero de la funcion B\n");
    //scanf("%d", &b);
    b = FuncionB(b);
    printf("El resultado de la funcion B es: %d\n", b);
    printf("Ingrese el dato de la funcion C\n");
   // scanf("%d", &dato);
    printf("Ingrese el n de la funcion C\n");
    //scanf("%d", &n);
   /* for (int i = 0; i < 4; i++)
    {
        printf("Ingrese el valor de la componente %d\n", i);
        //scanf("%d", &c[i]);
    }*/
    c[0] = 25;
    c[1] = 18;
    c[2] = 56;
    c[3] = 35;
    n = FuncionC(c, n, dato);
    printf("El resultado de la funcion C es: %d\n", n);
    return 7;
}
/*
6745
5679
50
3
25
18
56
35

*/
