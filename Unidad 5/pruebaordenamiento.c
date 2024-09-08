#include<stdlib.h>
#include<stdio.h>
struct lista
{
    int n;
    struct lista *sig;
};
typedef struct lista *nodo;
void cargar(nodo *cab)
{
    int num;
    printf("Ingrese el numero\n");
    scanf("%d",&num);
    if(num == 100)
        return;
    nodo actual;
    actual = (nodo) malloc(sizeof(struct lista));
    actual->sig = *cab;
    *cab = actual;
    actual->n = num;
    cargar(&*cab);
    return;
}
void mostrar(nodo actual)
{
    if(actual == NULL)
    {
        printf("Se llego al NULL\n");
        return;
    }
    printf("El numero es: %d\n", actual->n);
    mostrar(actual->sig);
}
void ordenar(nodo cab)
{
    int aux;
    nodo k, cota, p;
    k = NULL;
    cota = NULL;
    while (k != cab)
    {
        k = cab;
        p = cab;
        while (p->sig != cota)
        {
            if(p->n > p->sig->n)
            {
                aux = p->sig->n;
                p->sig->n = p->n;
                p->n = aux;
                k = p;
            }
            p = p->sig;
        }
        cota = k->sig;
    }
}
void liberarNodos(nodo actual)
{
   if(actual == NULL)
      return;
   liberarNodos(actual->sig);
   free(actual);
   return;
}
int main()
{
nodo cab = NULL;
cargar(&cab);
mostrar(cab);
ordenar(cab);
mostrar(cab);
liberarNodos(cab);
}
/* Lote de prueba
10
5
0
-5
12
100 */