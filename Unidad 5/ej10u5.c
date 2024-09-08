/* Ejercicio 10
La UNSJ todos los años otorga becas, para lo cual se ingresa el número de facultades participantes, de las misma se
ingresan los nombres y de cada una las inscripciones de los alumnos aspirantes a las becas de ayuda económica. Se
ingresa, en forma ordenada por facultad, los datos de cada alumno: Nombre, promedio y año que cursa.
Se pide, un programa que permita:
a) Realizar un listado ordenado por promedio, de los alumnos inscriptos en una determinada facultad cuyo nombre
se ingresa por teclado. (Mostrar nombre del alumno, promedio y año que cursa).
b) Indicar el nombre de la facultad que tiene menos inscriptos y la cantidad de inscriptos suponer único).
c) Mostrar por cada facultad la cantidad de alumnos con promedio mayor o igual a 7, que cursan de segundo año en
adelante. Usar una función recursiva. */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define N 3
typedef struct
{
   char nombre[50];
   float promedio;
   int curso;
} datos;
struct lista
{
   datos alumno;
   struct lista *sig;
};
typedef struct lista *nodo;
typedef struct
{
   char nombre[50];
   int cant;
   nodo cab;
} facultad;

void cargarFacultades(facultad a[], int i)
{
   if(i == N)
      return;
   a[i].cab = NULL;
   a[i].cant = 0;
   printf("Ingrese el nombre de la facultad %d\n", (i+1));
   fflush(stdin);
   gets(a[i].nombre);
   cargarFacultades(a, i+1);
}
void cargarAlumnos(facultad a[], int i)
{
   nodo nuevo;
   char bandera[50];
   if(i == N)
      return;
   nuevo = (nodo) malloc(sizeof(struct lista));
   printf("El alumno se cargara en la facultad %d\n", i+1);
   printf("Ingrese el nombre del alumno, FIN para finalizar con esta facultad\n");
   fflush(stdin);
   gets(bandera);
   if(strcmp(bandera, "FIN") == 0)
      cargarAlumnos(a, i+1);
   else
   {
   nuevo->sig = a[i].cab;
   a[i].cab = nuevo;
   a[i].cant += 1;
   strcpy(nuevo->alumno.nombre, bandera);
   printf("Ingrese el promedio del alumno\n");
   scanf("%f", &nuevo->alumno.promedio);
   printf("Ingrese el a%co que cursa el alumno\n", 164);
   scanf("%d", &nuevo->alumno.curso);
   cargarAlumnos(a, i);
   }
}
int buscarIndice(facultad a[], char nombre[], int i)
{
   if(i == N)
   {
      printf("La facultad no existe, intente nuevamente\n");
      return -1;
   }
   if(strcmp(a[i].nombre, nombre) != 0)
      return buscarIndice(a, nombre, i+1);
   return i;
}
int contarAlumnos(facultad a[], int i)
{
   int cant = 0;
   nodo actual;
   actual = a[i].cab;
   while(actual != NULL)
   {
      cant++;
      actual = actual->sig;
   }
   return cant;
}
void cargarSub(facultad a[], nodo actual, int cant, datos sub[], int i)
{
   if((i == cant) || (actual == NULL))
      return;
   sub[i] = actual->alumno;
   cargarSub(a, actual->sig, cant, sub, i+1);
}
void ordenarSub(datos sub[], int cant)
{
   int j, i = 0;
   datos aux;
   for(i = 0; i < cant; i++)
   {
      j = i;
      aux = sub[i];
      while(aux.promedio > sub[j-1].promedio)
      {
         sub[j] = sub[j-1];
         j--;
      }
      sub[j] = aux;
   }
}
void mostrarSub(datos sub[], int cant, int i)
{
   if(i == cant)
      return;
   printf("El alumno %s, tiene un promedio de %.2f y cursa %d a%co", sub[i].nombre, sub[i].promedio, sub[i].curso, 164);
   printf("\n");
   mostrarSub(sub, cant, i+1);
}
void minimoFacultad(facultad a[], int i, int *min, int *minI)
{
   int alumnos;
   if(i == N)
   {
      printf("La facultad con menos alumnos es: %s, con %d alumnos", a[*minI].nombre, *min);
      return;
   }
   alumnos = contarAlumnos(a, i);
   if(alumnos < *min)
   {
      *min = alumnos;
      *minI = i;
   }
   minimoFacultad(a, i, &*min, &*minI);
}
int contarPromedios(facultad a[], int i)
{
   if(i == N)
      return 0;
   int cant= 0;
   nodo actual;
   actual = a[i].cab;
   while (actual != NULL)
   {
      if((actual->alumno.promedio >= 7) && (actual->alumno.curso >= 2))
      cant++;
   }
   actual = actual->sig;
   return cant + contarPromedios(a, i+1);
}
void liberarNodos(nodo actual)
{
   if(actual == NULL)
      return;
   liberarNodos(actual->sig);
   free(actual);
   return;
}
void liberarLista(facultad a[], int i)
{
   if(i == N)
      return;
   nodo actual = a[i].cab;
   liberarNodos(actual);
   liberarLista(a, i+1);
}
int main()
{
   facultad a[N];
   int cant, i = 0, facu = -1, min = 9999, minI;
   char nombreFacu[50];
   datos *sub;
   nodo actual;
   cargarFacultades(a, i);
   cargarAlumnos(a, i);
   printf("Ingrese el nombre de la facultad que desea ordenar\n");
   fflush(stdin);
   gets(nombreFacu);
   while(facu == -1)
     facu = buscarIndice(a, nombreFacu, i);
   cant = contarAlumnos(a, facu);
   sub = (datos*) malloc(sizeof(datos)*cant);
   actual = a[facu].cab;
   cargarSub(a, actual, cant, sub, i);
   ordenarSub(sub, cant);
   mostrarSub(sub, cant, i);
   minimoFacultad(a, i, &min, &minI);
   printf("La cantidad de alumnos con promedio 7 o mayor, en segundo a%co para adelante es: %d\n", 164, contarPromedios(a, i));
   liberarLista(a, i);
   free(sub);
   return 0;
}
/* Lote de prueba
FCEFN
FI
FAUD
Sasso Joaquin
9.75
1
Reynoso Nicolas
6.65
2
Fernandez Juan
8.25
4
FIN
Sasso Tomas
7.37
4
Esteban Carrizo
8
1
Valdez Nahuel
6.5
3
FIN
Mercado Giuliana
9
2
Sanchez Jeremias
6
1
Rodriguez Pedro
9
3
Flores Mauro
8
2
FIN
*/
