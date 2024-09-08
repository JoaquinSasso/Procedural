/*Ejercicio 3
Generar un arreglo de registros que posea la siguiente información de 10 alumnos de procedural: Nombre, Apellido
y DNI.
a) Cargar los datos de los alumnos.
b) Listar los alumnos cargados.
c) Indicar cuántos alumnos tiene DNI mayor a 40 millones.
*/
#include <stdio.h>
#include <string.h>
const int N = 10;
struct persona
{
    char nombre[50];
    int dni;
};
void cargar(struct persona alumnos[])
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el nombre del alumno %d\n", (i + 1));
        fflush(stdin);
        gets(alumnos[i].nombre);
        printf("Ingrese el DNI del alumno %d\n", (i + 1));
        scanf("%d", &alumnos[i].dni);
    }
}
void mostrar(struct persona alumnos[])
{
    for(int i = 0; i < N; i++)
    {
        printf("%s, DNI: %d\n", alumnos[i].nombre, alumnos[i].dni);
    }
}
void contadorDNI(struct persona alumnos[])
{
    int cont = 0;
    for (int i = 0; i < N; i++)
    {
        if(alumnos[i].dni > 40000000)
        {
            cont++;
        }
    }
    printf("La cantidad de alumnos con DNI superior a 40M es de: %d", cont);
}
int main()
{
    struct persona alumnos[N];
    cargar(alumnos);
    mostrar(alumnos);
    contadorDNI(alumnos);
    return 7;
}
/*Bloque de prueba
Joaquin Sasso
44991289
Marta Garcia
23675489
Pedro Lopez
38956720
Maria Sanchez
45897354
Pablo Martin
46756890
Vilchez Valentin
42345921
Luis Martinez
23478023
Guadalupe Ortega
12456760
Ludmila Perez
47827654
Lorenzo Olmos
39872654

*/
//5 Alumnos con DNI mayor a 40 Millones