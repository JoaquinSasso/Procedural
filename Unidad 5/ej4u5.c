/*Ejercicio 4
Una multinacional dedicada a la venta de automotores cuenta con la información de los 10 planes de financiación de
las distintas unidades. Se cuenta con la siguiente información de cada adjudicatario a un plan: Numero de plan, DNI,
Nombre y Apellido, cantidad de cuotas pagadas.
a) Cargar en una estructura de datos adecuada la información que se posee.
b) Generar una nueva estructura con información de los planes que cuenten con adjudicatarios aptos para licitar
un vehículo, es decir, con más de 30 cuotas pagadas.
c) Mostrar el mapa de memoria, después de ejecutar la función que carga los datos.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

typedef struct adjudicatarios
{
   char nombre[60];
   int dni;
   int num;
   int cuotas;
} adj;
struct puntero
{
   adj adju;
   struct puntero *sig;
};
typedef struct puntero *nodo;

void iniciar(nodo planes[N], int i)
{
   if (i == N)
      return;
   planes[i]->sig = NULL;
   iniciar(planes, i + 1);
}
void cargar(nodo planes[N])
{
   nodo p, nuevo, anterior;
   int numPlan;
   printf("Ingrese el numero del plan del  adjudicatario\n");
   scanf("%d", &numPlan);
   numPlan--;
   if (numPlan == 0)
      return;
   nuevo = (adj *)malloc(sizeof(adj));
   nuevo->sig = NULL;
   if (planes[numPlan]->sig == NULL)
   {
      planes[numPlan]->sig = nuevo;
      planes[numPlan]->sig = nuevo;
   }
   else
   {
      p->sig = planes[numPlan];
      while (p != NULL)
      {
         anterior->sig = p;
         p = p->sig;
      }
      anterior->sig = nuevo;
      printf("Ingrese el Apellido y Nombre del adjudicatario\n");
      fflush(stdin);
      gets(nuevo->adju.nombre);
      printf("Ingrese el DNI del adjudicatario\n");
      scanf("%d", nuevo->adju.dni);
      printf("Ingrese la cantidad de cuotas abonadas\n");
          scanf("%d", nuevo->adju.cuotas);
      cargar(planes);
   }
}
   int main()
   {
      nodo planes[N];
      int i = 0;
      iniciar(planes, i);
      iniciar(planes, i);
      cargar(planes);
      return 0;
   }
