/*Sasso Joaquin
Registro: E010-272
DNI: 44991289
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
   char nombre[50];
   int num;
   char turno[15];
} persona;
struct nodo
{
   persona socio;
   struct nodo *sig;
};
typedef struct nodo *puntero;
void cargar(puntero *cab)
{
   int numero;
   printf("Ingrese el numero del socio, 0 para detener\n");
   scanf("%d", &numero);
   if (!numero)
      return;
   puntero nuevo;
   nuevo = (puntero)malloc(sizeof(struct nodo));
   nuevo->sig = *cab;
   *cab = nuevo;
   printf("Ingrese el nombre del socio\n");
   fflush(stdin);
   gets(nuevo->socio.nombre);
   printf("Ingrese el turno\n");
   fflush(stdin);
   gets(nuevo->socio.turno);
   nuevo->socio.num = numero;
   cargar(&*cab);
}
void mostrarManiana(puntero actual)
{
   if (actual == NULL)
      return;
   if (strcmp(actual->socio.turno, "maniana") == 0)
   {
      printf("\n");
      printf("El socio se llama %s\n", actual->socio.nombre);
      printf("El socio esta en el turno %s\n", actual->socio.turno);
      printf("El socio tiene el numero %d\n", actual->socio.num);
   }
   mostrarManiana(actual->sig);
}
void mostrar(puntero actual)
{
   if(actual == NULL)
      return;
   printf("\n");
   printf("El socio se llama %s\n", actual->socio.nombre);
   printf("El socio esta en el turno %s\n", actual->socio.turno);
   printf("El socio tiene el numero %d\n", actual->socio.num);
   mostrar(actual->sig);
}
void buscarSocio(puntero actual)
{
   int socio;
   printf("Ingrese el numero del socio que desea buscar\n");
   scanf("%d", &socio);
   while ((actual != NULL) && (actual->socio.num != socio))
      actual = actual->sig;
   if ((actual == NULL) && (actual->socio.num != socio))
      printf("No se encontro al socio\n");
   else
      printf("El socio esta en el turno: %s\n", actual->socio.turno);
   return;
}
void eliminar(puntero cab)
{
   puntero actual, anterior;
   anterior = cab;
   actual = cab;
   while (actual != NULL)
   {
      if (strcmp(actual->socio.turno, "noche") == 0)
      {
         anterior->sig = actual->sig;
         free(actual);
         actual = NULL;
      }
      else
      {
         anterior = actual;
         actual = actual->sig;
      }
   }
   return;
}
void liberarNodos(puntero actual)
{
   if(actual == NULL)
      return;
   free(actual);
   liberarNodos(actual->sig);
}
int main()
{
   puntero cab = NULL;
   cargar(&cab);
   mostrarManiana(cab);
   printf("\n");
   buscarSocio(cab);
   printf("\n");
   eliminar(cab);
   mostrar(cab);
   liberarNodos(cab);
   return 0;
}
/*Lote de prueba
1250
Lucia Castro
maniana
1820
Leonel Ruiz
noche
1700
Pablo Sosa
maniana
0
1820
*/