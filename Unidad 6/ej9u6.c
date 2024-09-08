/*Ejercicio 9
Una consultora contable realiza la liquidación de haberes de los empleados de varias PYMES.
Para ello posee un archivo con información de empleados “EMPLEADOS.dat” de diferentes empresas:
Nombre del Empleado, Nombre de la Empresa, DNI, CUIT y sueldo neto. El archivo está ordenado por
nombre de empresa.
Se pide realizar un programa que:
1. Emita un listado ordenado por empresa con la liquidación de haberes de cada empleado.
Además, el listado debe incluir el total a pagar en concepto de sueldo por cada empresa.
2. Generar el archivo “EMPRESAS.dat” que almacena para cada empresa la siguiente información:
Nombre, total de empleados, total pagado en concepto de liquidación.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char NAempleados[] = "EMPLEADOS.dat";
const char NAempresas[] = "EMPRESAS.dat";
typedef struct
{
    char nombre[50];
    char empresa[50];
    int dni;
    char cuit[12];
    float sueldo;
} empleado;

typedef struct
{
    char nombre[50];
    int cantidadEmpleados;
    float pagoTotal;
} empresa;
void cargarEmpleados(FILE *empleados)
{
    empleado aux;
    printf("Ingrese el nombre de la empresa, FIN para detener\n");
    fflush(stdin);
    gets(aux.empresa);
    if (strcmp(aux.empresa, "FIN") == 0)
        return;
    printf("Ingrese el nombre del empleado, FIN para detener\n");
    fflush(stdin);
    gets(aux.nombre);
    while (strcmp(aux.nombre, "FIN") != 0)
    {
        printf("Ingrese el DNI del empleado\n");
        scanf("%d", &aux.dni);
        printf("Ingrese el CUIT del empleado\n");
        fflush(stdin);
        gets(aux.cuit);
        printf("Ingrese el sueldo del empleado\n");
        scanf("%f", &aux.sueldo);
        fwrite(&aux, sizeof(empleado), 1, empleados);
        printf("Ingrese el nombre del empleado, FIN para detener\n");
        fflush(stdin);
        gets(aux.nombre);
    }
    cargarEmpleados(empleados);
}
void mostrarLiquidacion(FILE *empleados)
{
    empleado aux;
    int i;
    float total;
    char empresaActual[50];
    rewind(empleados);
    printf("************ LISTADO DE LIQUIDACION ****************\n");
    while(fread(&aux, sizeof(empleado), 1, empleados))
    {
        strcpy(empresaActual, aux.empresa);
        printf("Lista de empleados de %s\n", empresaActual);
        printf("         DNI                Nombre              Sueldo   \n");
        i = 0;
        total = 0;
        while(strcmp(aux.empresa, empresaActual) == 0)
        {
            printf("%d  %d  %s  %.2f\n", i+1, aux.dni, aux.nombre, aux.sueldo);
            i++;
            total += aux.sueldo;
            fread(&aux, sizeof(empleado), 1, empleados);
        }
        printf("Total pagado por %s es $%.2f\n", empresaActual, total);
    }
}
int main()
{
    FILE *empleados, *empresas;
    if ((empleados = fopen(NAempleados, "w+")) == NULL)
        printf("Hubo un error al crear el archivo de empleados\n");
    else if ((empresas = fopen(NAempresas, "w+")) == NULL)
        printf("Hubo un error al crear el archivo de empleados\n");
    else
    {
        cargarEmpleados(empleados);
        fclose(empleados);
        if ((empleados = fopen(NAempleados, "r+")) == NULL)
            printf("Hubo un error al leer el archivo de empleados\n");
        else
        {
            mostrarLiquidacion(empleados);
        }
    }
    return 7;
}
/*Lote de prueba
WALLMART
Nicolas Reynoso
45832649
20-45832649-6
175897.99
Tomas Spezia
42765983
20-42765983-4
500000
FIN
CHANGO MAS
Santiago Mansilla
43839341
20-43839341-4
150000
Joaquin Sasso
44991289
20-44991289-3
750000
FIN
SUPERMERCADO DIA
Santiago Masilla
43839341
20-43839341-4
180000
Marcelo Mondre
18763892
20-18763892-1
632897.01
FIN
FIN
*/