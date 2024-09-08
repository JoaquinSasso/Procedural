/*Ejercicio 2
Programa 2:
a) Generar un archivo alumnosAL.dat que contiene la siguiente información correspondiente a los alumnos que
cursan la materia Algebra Lineal: Nombre, Número de Registro y Resultado de un parcial (‘A’: Aprobado – ‘R’:
Reprobado). El archivo debe estar ordenado por Número de Registro.
b) Codificar una función que permita mostrar la información de cada uno de los alumnos
*/
#include<stdio.h>
#include<string.h>
typedef struct 
{
    char nombre[50];
    int registro;
    char resultado;
}alumno;
void cargar(FILE *archi)
{
    alumno a;
    fpos_t x;
    printf("Ingrese el numero de registro: \n");
    scanf("%d", &a.registro);
    while (a.registro)
    {
        fseek(archi, 0, SEEK_END);
        fgetpos(archi, &x);
        printf("Ingrese el nombre\n");
        fflush(stdin);
        gets(a.nombre);
        printf("Ingrese A si aprobo y R si reprobo\n");
        fflush(stdin);
        scanf("%c", &a.resultado);
        fwrite(&a, sizeof(alumno), 1, archi);
        printf("Ingrese el numero de registro: \n");
        scanf("%d", &a.registro);
    }
}
void mostrar(FILE *archi)
{
    alumno a;
    if((archi = fopen("alumnosAL.dat", "rb")) == NULL)
        printf("Hubo un error\n");
    else
    {
        while(fread(&a, sizeof(alumno), 1, archi))
        {
            if(a.resultado == 'A')
                printf("El registro es: %d, el nombre del alumno es: %s y aprobo\n", a.registro, a.nombre);
            if(a.resultado == 'R')
                printf("El registro es: %d, el nombre del alumno es: %s y reprobo\n", a.registro, a.nombre);
        }
    }
}
int main()
{
    FILE *archi;
    if((archi = fopen("alumnosAL.dat", "wb")) == NULL)
        printf("Hubo un error");
    else
    {
        cargar(archi);
        fclose(archi);
        mostrar(archi);
        fclose(archi);
    }
    return 7;
}
/*Lote de prueba
272
Joaquin
R
465
Nicolas
A
521
Tomas
A
583
Julio
R
674
Mauro
A
689
Juan
R
746
Mario
A
0

*/