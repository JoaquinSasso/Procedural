/* Ejercicio 7
La Federación Internacional de Futbol FIFA tiene el objetivo de recopilar información de los futbolistas de los últimos
4 mundiales (años 2022,2018,2014 y 2010). Para ello se está generando una nueva base de datos con información
acotada de dichos acontecimientos. De cada mundial se conoce: Nombre del país de realización y cantidad de
estadios, de cada futbolista: Nombre y apellido, país de residencia y cantidad de goles registrados.
Realizar un programa en C que a través de funciones óptimas permita:
a) Generar un arreglo de lista a través de punteros con los datos de los jugadores para los distintos mundiales. El
ingreso de información se encuentra ordenada por año de mundial. Para cada mundial el ingreso de información
finaliza con el nombre de país igual a FIN.
b) Para un mundial ingresado por teclado, realizar una función que devuelva al programa principal la cantidad de
jugadores de Argentina y cantidad de jugadores con más de 5 goles realizados. Realizar una función recursiva
que devuelva un dato por parámetro y el otro que lo calcule la función.
c) Eliminar un jugador cuyo nombre y apellido es ingresado por teclado.
d) Generar una nueva estructura con todos aquellos jugadores que por mundial hayan convertido 3 o más goles. */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 4
typedef struct
{
   char nombre[80];
   char pais[40];
   int goles;
} jugadores;
struct nodo
{
   jugadores jugador;
   struct nodo *sig;
};
typedef struct nodo *puntero; // Estructura de los nodos de la lista de jugadoes
typedef struct                // Estructura para el arreglo de mundiales
{
   int estadios;
   char pais[40];
   puntero cab;
} mundial;
void iniciar(mundial a[N], int i)
{
   if (i == N)
      return;
   a[i].cab = NULL;
   iniciar(a, i + 1);
}
int buscarAnio()
{
   int anio, i = -1;
   printf("Ingrese el a%co del mundial\n", 164);
   scanf("%d", &anio);
   switch (anio)
   {
   case 2010:
      i = 0;
      break;
   case 2014:
      i = 1;
      break;
   case 2018:
      i = 2;
      break;
   case 2022:
      i = 3;
      break;
   }
   return i;
}
void cargarM(mundial a[])
{
   int i = -1;
   i = buscarAnio();
   if (i == -1)
      return;
   printf("Ingrese la cantidad de estadios\n");
   scanf("%d", &a[i].estadios);
   printf("Ingrese el pais anfitrion\n");
   fflush(stdin);
   gets(a[i].pais);
   cargarM(a);
}
int contador(puntero xp, int *arg)
{
   int b = 0;
   if (strcmp(xp->jugador.pais, "Argentina") == 0)
      *arg += 1;
   if (xp->jugador.goles > 5)
      b = 1;
   return b;
}
void cargarJ(mundial a[], int *arg, int *goleadores)
{
   int i = 1;
   i = buscarAnio();
   if (i == -1)
   {
      printf("El a%co no corresponde a un mundial\n", 164);
      return;
   }
   puntero nuevo;
   nuevo = (puntero)malloc(sizeof(struct nodo));
   nuevo->sig = a[i].cab;
   a[i].cab = nuevo;
   printf("Ingrese el nombre del jugador\n");
   fflush(stdin);
   gets(nuevo->jugador.nombre);
   fflush(stdin);
   printf("Ingrese el pais del jugador\n");
   gets(nuevo->jugador.pais);
   printf("Ingrese la cantidad de goles que anoto el jugador\n");
   scanf("%d", &nuevo->jugador.goles);
   *goleadores += contador(nuevo, &*arg);
   cargarJ(a, &*arg, &*goleadores);
}
void eliminar(mundial a[], char nya[], int i)
{
   if (i == N)
   {
      printf("El jugador no existe\n");
      return;
   }
   puntero nuevo = NULL, ant = NULL;
   nuevo = a[i].cab;
   if (nuevo == NULL)
   {
      printf("La cabecera %d era NULL\n", i);
      eliminar(a, nya, i + 1);
   }
   while (!(strcmp(nuevo->jugador.nombre, nya) == 0) && (nuevo->sig != NULL))
   {
      ant = nuevo;
      nuevo = nuevo->sig;
   }
   if (!(strcmp(nuevo->jugador.nombre, nya) == 0) && (nuevo->sig == NULL))
   {
      printf("El jugador no se encontraba en el mundial %d\n", i);
      eliminar(a, nya, i + 1);
   }
   else
   {
      if (ant == NULL)
         ant = a[i].cab;
      ant->sig = nuevo->sig;
      free(nuevo);
      printf("El jugador se elimino exitosamente\n");
      return;
   }
}
int masDe3(mundial a[], int i)
{
   int cant = 0;
   if (i == N)
      return 0;
   if (a[i].cab != NULL)
   {
      puntero nuevo;
      nuevo = a[i].cab;
      while (nuevo->sig != NULL)
      {
         nuevo = nuevo->sig;
         if (nuevo->jugador.goles >= 3)
            cant++;
      }
   }
   return cant + masDe3(a, i + 1);
}
int main()
{
   mundial a[N];
   int i = 0, goleadores = 0, arg = 0, subN;
   char nya[40];
   iniciar(a, i);
   printf("Se solicitaran los datos de los mundiales\n");
   cargarM(a);
   printf("Se solicitaran los datos de los jugadores\n");
   cargarJ(a, &arg, &goleadores);
   printf("Hay %d jugadores argentinos y %d jugadores que anotaron mas de 5 veces\n", arg, goleadores);
   printf("Ingrese el nombre del jugador que desea eliminar\n");
   fflush(stdin);
   gets(nya);
   eliminar(a, nya, i);
   subN = masDe3(a, i);
   printf("Hay %d jugadors con 3 o mas goles\n", subN);
   return 0;
}
//Deberian haber 5 jugadores con 3 o mas goles (si no se elmina ninguno con goles)
/*Lote de Prueba
2010
14
Sudafrica
2014
21
Brasil
2018
17
Rusia
2022
8
Qatar
0
2022
Lionel Andres Messi
Argentina
7
2018
Cristiano Ronaldo
Portugal
3
2022
Cristian Romero
Argentina
0
2010
Gerard Pique
España
1
2014
Neymar Jr
Brasil
6
2014
Robert Lewandowski
Polonia
6
2014
Muller
Alemania
3
2022
Otamendi
Argentina
0
2010
Iniesta
España
2
2022
Enzo Fernandez
Argentina
2
0
*/