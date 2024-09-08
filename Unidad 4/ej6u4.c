/*Ejercicio 6
Construir un programa en lenguaje C que a través de funciones recursivas resuelva los siguientes ítems:
a) Cargar un arreglo de enteros, de N componentes.
b) Generar un subarreglo con las componentes del arreglo cargado, cuyo valor es mayor o igual al Promedio.
c) Indicar cuantas componentes del subarreglo son mayores al promedio y cuantas iguales a éste.
d) Ingresar un número y decir si se encuentra en el subarreglo.
e) Realice el ítem anterior si el arreglo original estuviera ordenado ascendentemente.
Nota: Hacer mapa de memoria para un subprograma
*/
#include<stdio.h>
const int N=5;
void carga(int arre[N], int i)
{
    if (i==N)
    {
        return;
    }
    else
    {
        printf("\ningresar el elemento %d\n", i+1);
        fflush(stdin);
        scanf("%d", &arre[i]);
        return carga(arre, i+1);
    }
    
}
void sacartot(int arre[N], int i, int *tot)
{
    if(i==N)
        {
            return;
        }
        else
        {
            *tot+=arre[i];
            return sacartot(arre, i+1, &*tot);
        }
}
void cargasub(int arre[N], int suba[N], int i, int *c, int prom)
{
    if(i==N)
    {
        return;
    }
    else
    {
        if (arre[i]>=prom)
        {
            
            suba[*c]=arre[i];
            *c=*c+1;
            
        }
        return cargasub(arre, suba, i+1, &*c, prom);
    }
}
void cuenta(int suba[N],int i, int c, int prom, int *mayor, int *igual)
{
    if(i==c)
    {
        return;
    }
    else
    {
        if (suba[i]> prom)
        {
            *mayor+=1;
        }
        else{
             if(suba[i]== prom)
                {
                    *igual+=1;
                }
            }
        return cuenta(suba, i+1, c, prom, &*mayor, &*igual);
    }
}
void buscar(int suba[N], int c, int i, int elem, int *ind)
{
    if ((i>c) || (elem==suba[i]))
    {
        *ind=i;
        return;
    }
    else
    {
        return buscar(suba, c, i+1, elem, &*ind);
    }
    
}
int main()
{
    int arre[N], suba[N], c=0, i=0, tot=0, prom, mayor=0, igual=0, elem, indice=0;
    carga(arre, i);
    sacartot(arre, i, &tot);
    prom=(tot/N);
    cargasub(arre, suba, i, &c, prom);
    cuenta(suba, i, c, prom, &mayor, &igual);
    printf("\nla cantidad de elementos mayores que el promedio es de: %d y la cantidad de elementos iguales es: %d\n", mayor, igual);
    printf("\ningresar el numero a buscar\n");
    fflush(stdin);
    scanf("%d", &elem);
    buscar(suba, c, i, elem, &indice);
    if (indice>c)
    {
        printf("\nno se encontro el elemento\n");
    }
    else
    {
        printf("\nel elemento se encontro en el indice %d\n", indice);
    }
    
    return 7;
}

/*lote de prueba
5
4
7
7
3

*/