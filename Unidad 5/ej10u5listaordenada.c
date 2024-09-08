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
void ordenar(nodo cab)
{
    datos aux;
    nodo k, cota, p;
    k = NULL;
    cota = NULL;
    while (k != cab)
    {
        k = cab;
        p = cab;
        while (p->sig != cota)
        {
            if(p->alumno.promedio < p->sig->alumno.promedio)
            {
                aux = p->sig->alumno;
                p->sig->alumno = p->alumno;
                p->alumno = aux;
                k = p;
            }
            p = p->sig;
        }
        cota = k->sig;
    }
}
void mostrar(nodo actual)
{
   if(actual == NULL)
      return;
   printf("El alumno %s con promedio: %.2f esta cursando %d a%co\n", actual->alumno.nombre, actual->alumno.promedio, actual->alumno.curso, 164);
   mostrar(actual->sig);
}
void minimoFacultad(facultad a[], int i, int *min, int *minI)
{
   if(i == N)
   {
      printf("La facultad con menos alumnos es: %s, con %d alumnos\n", a[*minI].nombre, *min);
      return;
   }
   if(a->cant < *min)
   {
      *min = a->cant;
      *minI = i;
   }
   minimoFacultad(a, i+1, &*min, &*minI);
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
      actual = actual->sig;
   }
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
   liberarNodos(a[i].cab);
   liberarLista(a, i+1);
}
int main()
{
   facultad a[N];
   int i = 0, facu, min = 9999, minI;
   char nombreFacu[50];
   cargarFacultades(a, i);
   cargarAlumnos(a, i);
   printf("Ingrese el nombre de la facultad que desea ordenar\n");
   fflush(stdin);
   gets(nombreFacu);
   facu = buscarIndice(a, nombreFacu, i);
   ordenar(a[facu].cab);
   mostrar(a[facu].cab);
   minimoFacultad(a, i, &min, &minI);
   printf("La cantidad de alumnos con promedio 7 o mayor, en segundo a%co para adelante es: %d\n", 164, contarPromedios(a, i));
   liberarLista(a, i);
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
FAUD
*/
