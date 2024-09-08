/*Ejercicio 2
Programa 3:
Codificar una función que permita mostrar Número de Registro y Nombre de alumnos que aprobaron ambas
materias.*/
#include<stdio.h>
#include<string.h>
typedef struct 
{
    char nombre[50];
    int registro;
    char resultado;
}alumno;
void mostrar(FILE *algebra, FILE *procedural)
{
    alumno a, p;
    if((algebra = fopen("alumnosAL.dat", "rb")) == NULL)
        printf("Hubo un error\n");
    else if((procedural = fopen("alumnosPP.dat", "rb")) == NULL)
        printf("Hubo un error\n");
    else
    {
        while((fread(&a, sizeof(alumno), 1, algebra)) && (fread(&p, sizeof(alumno), 1, procedural)))
        {
            if((a.resultado == 'A') && (p.resultado == 'A'))
                printf("El alumno: %s, con registro: %d aprobo ambas materias\n", a.nombre, a.registro);
        }
    }
}
int main()
{
    FILE *procedural = NULL, *algebra = NULL;
    mostrar(algebra, procedural);
    fclose(procedural);
    fclose(algebra);
    return 7;
}