/*Ejercicio 4
Una agencia de empleo registra los datos de 50 postulantes a un puesto de trabajo. De cada uno registra nombre,
sexo, dni, edad y codigo de localidad donde vive (1…19).
Se pide que usando funciones para cada ítem, resuelva lo siguiente:
a) Indicar cuantas postulantes mujeres tienen menos de 30 años.
b) Indicar la edad promedio de los postulantes varones.
b) Mostrar los nombres de los postulantes y el dni de quienes viven en la localidad 14.*/
#include<stdio.h>
#include<string.h>
const int N = 6;
struct persona
{
    char nombre[50];
    char sexo;
    int dni;
    int edad;
    int localidad;
};
void cargar(struct persona postulantes[])
{
    for(int i = 0; i < N; i++)
    {
        printf("Ingrese el nombre del postulante:\n");
        fflush(stdin);
        gets(postulantes[i].nombre);
        printf("Ingrese el sexo del postulante:\n");
        fflush(stdin);
        scanf("%c", &postulantes[i].sexo);
        printf("Ingrese el DNI del postulante:\n");
        scanf("%d", &postulantes[i].dni);
        printf("Ingrese la edad del postulante:\n");
        scanf("%d", &postulantes[i].edad);
        printf("Ingrese el codigo de localidad (1-19) del postulante:\n");
        scanf("%d", &postulantes[i].localidad);
    }
}
void contarMujeres(struct persona postulantes[])
{
    int contadorMujeres = 0;
    for(int i = 0; i < N; i++)
    {
        if((postulantes[i].sexo == 'M') && (postulantes[i].edad < 30))
        {
            contadorMujeres++;
        }
    }
    printf("La cantidad de mujeres con edad menor a 30 es de: %d\n", contadorMujeres);
}
void promedioHombres(struct persona postulantes[])
{
    int contTotal = 0, sumTotal = 0;
    for(int i = 0; i < N; i++)
    {
        if(postulantes[i].sexo == 'H')
        {
            contTotal++;
            sumTotal+= postulantes[i].edad;
        }
    }
    int promedio = sumTotal / contTotal;
    printf("El promedio de edad de los hombres es de %d\n", promedio);
}
void mostrarZona(struct persona postulantes[])
{
    for(int i = 0; i < N; i++){
        if(postulantes[i].localidad == 14)
        {
            printf("El postulante %s, con DNi %d, vive en la zona 14\n", postulantes[i].nombre, postulantes[i].dni);
        }
    }
}
int main()
{
    struct persona postulantes[N];
    cargar(postulantes);
    contarMujeres(postulantes);
    promedioHombres(postulantes);
    mostrarZona(postulantes);
    return 9;
}
/*Bloque de prueba
Marta Diaz
M
32476787
29
14
Roberto Gomez
H
23342442
24
14
Ruben Ortega
H
23423452
62
5
Romina Sanchez
M
424453255
24
3
Humberto Rodriguez
H
123445545
56
17
Maria Teresa De Calcuta
M
12345678
54
10

*/