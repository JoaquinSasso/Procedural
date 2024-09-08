#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

struct nodo
{
   int numSocio;
   char nombre[50];
   char turno[10];
   struct nodo *sig;
};
typedef struct nodo *puntero;

void insertar(puntero &xp)
{
   int socio;
   puntero nuevo;
   nuevo = (puntero) malloc(sizeof(nodo));
   printf("\n Ingrese el numero de socio, 0 para terminar: ");
   scanf("%d", &socio);
   while (socio != 0)
   {
      nuevo = (puntero)malloc(sizeof(struct nodo));
      nuevo->numSocio = socio;
      printf("\n Ingrese el nombre del socio:");
      fflush(stdin);
      gets(nuevo->nombre);
      printf("\n Ingrese el turno del socio:");
      fflush(stdin);
      gets(nuevo->turno);
      nuevo->sig = xp;
      xp = nuevo;
      printf("\n Ingrese el socio 0 para terminar: ");
      scanf("%d", &socio);
   }
   return;
}

void mostrarTM(puntero actual)
{
   if (actual == NULL)
   {
      return;
   }
   if (strcmp(actual->turno, "maniana") == 0)
   {
      printf("Numero de socio: %d, Nombre: %s, Turno: %s\n", actual->numSocio, actual->nombre, actual->turno);
   }
   mostrarTM(actual->sig);
}

void buscar(puntero cab)
{
   int nrosocio;
   printf("\n Ingrese el numero que quiere encontrar\n");
   scanf("%d", &nrosocio);
   while((cab->numSocio != nrosocio) && (cab != NULL))
      {
         cab = cab->sig;
      }
   if((cab == NULL) && (cab->numSocio != nrosocio))
      printf("No se encontro al socio\n");
   else
      printf("\n El socio %d esta en el turno %s", nrosocio, cab->turno);
}

void eliminarTN(puntero ca)
{
   puntero anterior, sig;
   char tur[20];
   printf("\n Ingrese el turno que desea eliminar\n");
   fflush(stdin);
   gets(tur);
   while(ca != NULL)
   {
      if(strcmp(ca->turno, tur) == 0)
      {
         anterior->sig = ca->sig;
         sig = ca->sig;
         free(ca);
         ca = sig;
      }
      else
      {
         anterior = ca;
         ca = ca->sig;
      }
   }
}

void listar(puntero &cz)
{
   while (cz != NULL)
   {
      printf("Número de socio: %d, Nombre: %s, Turno: %s\n", cz->numSocio, cz->nombre, cz->turno);
      cz = cz->sig;
   }
}

void liberarLista(puntero &cabe)
{
   puntero p;
   while (cabe != NULL)
   {
      p = cabe;
      cabe = cabe->sig;
      free(p);
   }
   return;
}

int main()
{
   puntero cabeza;
   cabeza = NULL;
   insertar(cabeza);
   printf("Socios del turno ma%cana:\n", 164);
   mostrarTM(cabeza); // Mostrar los socios del turno mañana de forma recursiva
   buscar(cabeza);    // Busca el socio por el número
   eliminarTN(cabeza);
   printf("Lista actualizada después de eliminar los socios del turno noche:\n");
   listar(cabeza);
   liberarLista(cabeza);
   printf("Reinoso Mateo Emmanuel\n");
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