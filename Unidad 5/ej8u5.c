/* Ejercicio 8
La Facultad de Ciencias Exactas organizó el Congreso de Informática, y necesita administrar la información relativa a
los 10 tutoriales que se proponen en dicho evento.
Realizar un programa, que a través de un menú de opciones permita:
a) Ingresar los datos correspondientes a cada tutorial: número de tutorial (1-10) y título.
b) Registrar las inscripciones, ingresando el DNI del inscripto y el número de tutorial al que desea asistir.
c) Eliminar alguna inscripción, en cuyo caso se ingresarán los mismos datos que en el ítem anterior.
d) Dado el número de un tutorial, mostrar su título y la cantidad de inscriptos en él.
e) Dado el DNI de una persona, informar el/los tutoriales (número y título) en los que se inscribió.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 10
typedef struct
{
   char titulo[80];
   int cant;
} tutorial;
typedef struct
{
   int dni;
   int nro;
} persona;
struct nodoT
{
   tutorial tuto;
   struct nodoT *sig;
};
typedef struct nodoT *cab;
struct nodoP
{
   persona alumno;
   struct nodoP *cab;
};
typedef struct nodoP *cabP;
