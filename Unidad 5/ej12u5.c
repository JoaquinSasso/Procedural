/*Ejercicio 12 
Una empresa de desarrollo software relacionado a la música cuenta con un servicio de listas de reproducción. Las 
mismas son creadas por cada uno de sus usuarios. De cada una se conoce el nombre y la duración en horas. De cada 
canción se conoce el nombre de la lista a la que pertenece, autor y nombre, género y duración.
Realiza un programa que permita:
a) Generar una estructura adecuada para cada una de las listas como también las canciones que va a contener cada 
una de ellas. 
b) Ingresar los datos correspondientes a cada una de las listas de reproducción. 
c) Registrar el ingreso de las distintas canciones, el mismo no cuenta con un orden especifico. 
d) Dado un nombre y autor ingresado por el usuario realizar la eliminación de dicha canción de la lista 
correspondiente.
e) Generar una nueva lista de reproducción llamada “Rock alternativo” y guardar todas aquellas canciones de las 
listas existentes cuyo genero sea “Rock alternativo”.
f) Mostrar la lista generada usando una función recursiva.*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct{
    char list[50];
    char autor[50];
    char n[50];
    char genero[50];
    int duracion;
}cancion;

typedef struct can{
    cancion c;
    struct can*sig;
}canc;
typedef struct can*punt;

typedef struct playl{
    char name[20];
    float duracion;
    canc cancion;
    struct playlist*sig;
}playlist;
typedef playlist *list;

typedef struct cancion{
    char list[20];
    char autor[20];
    char name[20];
    char genero[20];
    int duracion;
};

struct playlist{
    char name[20];
    float duracion;
    struct can{
        cancion c;
        struct can*sig;
    };
    struct playlist*sig;
};
typedef struct can*nodo;
typedef struct playlist*list;
*/
void iniciar(list cab){
    cab=NULL;
}

void canciones(punt &xp, list nodo){
    punt nuevo, p, ant;
    char c[20];
    printf("Ingrese nombre de la cancion\n");
    fflush(stdin);
    gets(c);
    xp=NULL;
    while(c!="FIN"){
        nuevo=(punt)malloc(sizeof(punt));
        nodo->nuevo->c.name=c;
        printf("Ingrese el autor\n");
        fflush(stdin);
        gets(nodo->nuevo->c.autor);
        printf("Ingrese el genero\n");
        fflush(stdin);
        gets(nodo->nuevo->c.genero);
        printf("Ingrese la duracion de la cancion");
        scanf("%d", nodo->nuevo->c.duracion);
        nodo->nuevo->c.list=nodo->name;
        if(xp==NULL){
            xp=nodo->nuevo->sig;
        }
        else{
            p=xp;
            while(p!=NULL){
                ant=p;
                p=p->sig;
            }
            ant->sig=nuevo;
        }
    }
    return;
}
*/

void canciones(punt &xp, list nodo){
    punt nuevo;
    char x[20];
    printf("Ingrese nombre de la cancion\n");
    fflush(stdin);
    gets(x);
    while(x!="FIN"){
        nuevo=(punt)malloc(sizeof(punt));
        printf("Ingrese el autor \n");
        fflush(stdin);
        gets(nuevo->c.autor);
        printf("Ingrese la duracion de la cancion\n");
        scanf("%d", nuevo->c.duracion);
        printf("Ingrese genero de la cancion\n");
        fflush(stdin);
        gets(nuevo->c.genero);
        nuevo->sig=xp;
		xp=nuevo;
        printf("Ingrese nombre de la cancion\n");
        scanf("%d", x);
    }
    nodo->cancion.sig=nuevo;
    return;
}

void cargar(list &cab, punt xp){
    list nuevo, p, ant;
    char a[20];
    printf("Ingrese nombre de la playlist\n");
    fflush(stdin);
    gets(a);
    while(a!="FIN"){
        nuevo=(list)malloc(sizeof(list));
        canciones(xp, nuevo);
        if(cab==NULL){
            cab=nuevo->sig;
        }
        else{
            p=cab;
            while(p!=NULL){
                ant=p;
                p=p->sig;
            }
            ant->sig=nuevo;
        }
        printf("Ingrese nombre de la playlist\n");
        fflush(stdin);
        gets(a);
    }
    return;
}
void eliminaac(list cab, punt xp){
    char n[20], a[20];
    printf("Ingrese el nombre y el autor de la cancion a eliminar\n");
    fflush(Stdin);
    gets(n);
    fflush(stdin);
    gets(a);
    while((n!=cab->cancion.c.))
}
main(){
    list cab;
    punt xp;
    iniciar(cab);
    cargar(cab, xp);
    eliminarc(cab, xp);
}