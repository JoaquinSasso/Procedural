/*
La Facultad de Ciencias Exactas organizó el Congreso de Informática, y necesita administrar la información relativa a
los 10 tutoriales que se proponen en dicho evento.
Realizar un programa, que a través de un menú de opciones permita:
a) Ingresar los datos correspondientes a cada tutorial: número de tutorial (1-10) y título.
b) Registrar las inscripciones, ingresando el DNI del inscripto y el número de tutorial al que desea asistir.
c) Eliminar alguna inscripción, en cuyo caso se ingresarán los mismos datos que en el ítem anterior.
d) Dado el número de un tutorial, mostrar su título y la cantidad de inscriptos en él.
e) Dado el DNI de una persona, informar el/los tutoriales (número y título) en los que se inscribió.
Nota: Para cada ítem emplear al menos una función recursiva.
*/
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#define N 3
struct nodo
{
    int dni;
    struct nodo *sig;
};
typedef struct nodo *puntero;
struct tutorial
{
    char nomb[120];
    int canti;
    puntero cab;
};
void crear(struct tutorial arre[N], int i)
{
    if (i == N)
        return;
    arre[i].cab = NULL;
    arre[i].canti = 0;
    crear(arre, i + 1);
}
void carga(struct tutorial arre[N], int i)
{
    if (i == N)
        return;
    printf("Ingresar titulo del tutorial %d\n", i + 1);
    fflush(stdin);
    gets(arre[i].nomb);
    carga(arre, i + 1);
}
void insertar(struct tutorial arre[N])
{
    int num, dni;
    printf("Ingresar numero de tutorial (numero del 1 al 3, 0 para finalizar)\n");
    scanf("%d", &num);
    if (num == 0)
        return;
    printf("Ingresar DNI\n");
    scanf("%d", &dni);
    puntero nuevo;
    nuevo = (puntero)malloc(sizeof(puntero));
    nuevo->sig = arre[num - 1].cab;
    arre[num - 1].cab = nuevo;
    arre[num - 1].canti += 1;
    insertar(arre);
}
void elim(struct tutorial arre[N], int dni, int ind)
{
    puntero nuevo, ant;
    if (!((ind >= 0) && (ind < N)))
    {
        printf("El numero de tutorial es incorrecto\n");
        return;
    }
    if (arre[ind].cab == NULL)
    {
        printf("El tutorial no tiene ningun inscripto\n");
        return;
    }
    nuevo = arre[ind].cab;
    while ((nuevo->dni != dni) && (nuevo->sig != NULL))
    {
        ant = nuevo;
        nuevo = nuevo->sig;
    }
    if ((nuevo->dni != dni) && (nuevo->sig == NULL))
    {
        printf("La persona no se encuentra inscripta a este tutorial\n");
        return;
    }
    ant->sig = nuevo->sig;
    free(nuevo);
    printf("Se elimino la persona indicada\n");
    return;
}
void muestra(struct tutorial arre[N])
{
    int num;
    printf("Ingresar el numero del tutorial que se desea saber el titulo y cantidad de inscriptos\n");
    scanf("%d", &num);
    printf("\nel tutorial de titulo: %s tiene una cantidad de inscriptos de: %d\n", arre[num-1].nomb, arre[num-1].canti);
    return;
}
void muestra2(struct tutorial arre[N], int dni, int i)
{
    puntero nuevo;
    if (i == N)
    {
        return;
    }
    else
    {
        nuevo = arre[i].cab;
        while ((nuevo->dni != dni) && (nuevo->sig != NULL))
        {
            nuevo = nuevo->sig;
        }
        if (nuevo->dni == dni)
        {
            printf("\nla persona se inscribio en el tutorial numero %d titulado: %s\n", i + 1, arre[i].nomb);
            muestra2(arre, dni, i + 1);
        }
        muestra2(arre, dni, i + 1);
    }
}
int main()
{
    int dni, ind, num, dni2, opcion;
    struct tutorial arre[N];
    crear(arre, 0);
    printf("Ingrese la opcion que desea\n");
    printf("1.Cargar nombres de turoriales\n2.Cargar personas\n3.Eliminar una inscripcion\n4.Mostrar el titulo y cantidad de inscriptos a un tutorial\n5.Mostrar los tutoriales a los que una persona esta inscripta\n0.Finalizar\n");
    scanf("%d", &opcion);
    while(opcion != 0)
    {
    switch (opcion)
    {
    case 1:
        carga(arre, 0);
        break;
    case 2:
        insertar(arre);
        break;
    case 3:
        printf("Se eliminara una persona, ingrese sus datos\n");
        printf("Ingresar dni\n");
        scanf("%d", &dni);
        printf("Ingresar numero de tutorial\n");
        scanf("%d", &ind);
        elim(arre, dni, ind);
        break;
    case 4:
        muestra(arre);
        break;
    case 5:
        printf("Ingrese el dni de una persona para ver a que tutoriales esta inscripto\n");
        scanf("%d", &dni2);
        muestra2(arre, dni2, 0);
        break;
    default:
        printf("El numero no corresponde a nunguna opcion\n");
        break;
    }
    printf("1.Cargar nombres de turoriales\n2.Cargar personas\n3.Eliminar una inscripcion\n4.Mostrar el titulo y cantidad de inscriptos a un tutorial\n5.Mostrar los tutoriales a los que una persona esta inscripta\n0.Finalizar\n");
    scanf("%d", &opcion);
    }
    return 7;
}
/*lote de prueba:
programacion procedural pt1
programacion procedural pt2
programacion procedural pt3
45885130
1
45241152
1
45222363
1
45885130
2
54283233
2
32345232
2
45885130
3
12321333
3
12312332
3


*/