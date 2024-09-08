/*Ejercicio 3
Se registra la información de las operaciones realizadas por un cajero durante un fin de semana. De cada operación
se conoce: número de operación, importe y tipo de operación (1: cobro; 2: pago).
Utilizando funciones óptimas realice lo siguiente:
a) Genere una lista con la información de las operaciones.
b) Indique cuál es el/los número/s de mayor importe cobrado. (usar una función recursiva)
c) Con la información de la lista genere un archivo con los datos de los pagos realizados.
d) Eliminar la lista generada.
e) Indicar en el principal el importe promedio de los pagos realizados.
f) Eliminar del archivo los pagos menores a $500.*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
const char NArchi[] = "ej3u6.dat";
const char NCopia[] = "ej3u6_1.dat";
typedef struct 
{
    int num;
    float imp;
    int tipo;
} operacion;
typedef struct nod
{
    operacion ope;
    struct nod *sig;
} nodo;
typedef nodo *puntero;
void cargar(puntero *cab)
{
    puntero nuevo;
    nuevo = (puntero) malloc(sizeof(nodo));
    printf("Ingrese el numero de operacion, -1 FIN\n");
    scanf("%d", &nuevo->ope.num);
    if(nuevo->ope.num == -1)
        return;
    printf("Ingrese el importe de la operacion\n");
    scanf("%f", &nuevo->ope.imp);
    printf("Ingrese el tipo de operacion 1:cobro 2:pago\n");
    scanf("%d", &nuevo->ope.tipo);
    nuevo->sig = *cab;
    *cab = nuevo; 
    cargar(&*cab);
}
void mostrarMax(puntero actual, float *max)
{
    if(actual == NULL)
        return;
    if(actual->ope.imp > *max)
    {
        printf("Se actualizo el maximo\n");
        *max = actual->ope.imp;
    }
    mostrarMax(actual->sig, &*max);
    if(actual->ope.imp == *max)
        printf("La operacion de numero %d tiene el maximo importe\n", actual->ope.num);
}
void cargarArchivo(FILE *archi, puntero actual)
{
    if(actual == NULL)
        return;
    fpos_t x;
    fseek(archi, 0, SEEK_END);
    fgetpos(archi, &x);
    fwrite(&actual->ope, sizeof(operacion), 1, archi);
    cargarArchivo(archi, actual->sig);
}
void liberarLista(puntero actual)
{
    if(actual == NULL)
        return;
    liberarLista(actual->sig);
    free(actual);
}
float promediar(FILE *archi)
{
    operacion op;
    int cont = 0;
    float total = 0;
    if(archi = (fopen(NArchi, "rb")) == NULL)
        printf("Hubo un error\n");
    else
    {
        while(fread(&op, sizeof(operacion), 1, archi))
        {
            cont++;
            total += op.imp;
        }
    }
    return total / cont;
}
void eliminar(FILE *archi, FILE *copia)
{
    operacion op;
    if((archi = fopen(NArchi, "rb")) == NULL)
        printf("Hubo un error leyendo original\n");
    else
    {
        while (fread(&op, sizeof(operacion), 1, archi))
        {
            if(op.imp >= 500)
                fwrite(&op, sizeof(operacion), 1, copia);
        }
        fclose(archi);
        remove(NArchi);
        fclose(copia);
        if((rename(NCopia, NArchi)) == 0)
            printf("El nombre fue cambiado con exito\n");
        else
            printf("Hubo un error al cambiar el nombre\n");
    }
}
void mostrar(FILE *archi)
{
    operacion op;
    if((fopen(NArchi, "rb")) == NULL)
        printf("Hubo un error leyendo la copia\n");
    else
    {
        while(fread(&op, sizeof(operacion), 1, archi))
            printf("La operacion %d, tuvo un importe de %.2f y fue de tipo %d\n", op.num, op.imp, op.tipo);
    }
}
int main()
{
    float max = 0, promedio;
    FILE *archivo = NULL, *copia = NULL;
    puntero cab = NULL;
    cargar(&cab);
    mostrarMax(cab, &max);
    if((archivo = fopen(NArchi, "wb")) == NULL)
        printf("Hubo un error escribiendo el original\n");
    else
    {
        cargarArchivo(archivo, cab);
        fclose(archivo);
        liberarLista(cab);
        cab = NULL;
        promedio = promediar(archivo);
        printf("El promedio es: %.2f\n", promedio);
        fclose(archivo);
        if((copia = fopen(NCopia, "wb")) == NULL)
            printf("Hubo un error creando la copia\n");
        else
        {
            eliminar(archivo, copia);
            mostrar(copia);
        }

    }
    return 7;
}
/*Lote de prueba
50
580.9
1
51
580.9
2
52
290.7
1
53
100.5
2
89
530.4
1
45
136.9
2
-1

*/