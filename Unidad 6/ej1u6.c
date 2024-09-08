/*Ejercicio 1
Almacenar la información de los asistentes a unas jornadas de capacitación, de cada asistente se conoce su nombre y
edad.
Utilizando funciones óptimas realice lo siguiente:
a) Genere un archivo de acceso secuencial con la información de los asistentes a las jornadas.
b) Muestre los nombres de los asistentes mayores de 40 años.*/
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nombre[50];
    int edad;
} personas;
void cargar(FILE *xarchi)
{
    personas p;
    fpos_t x;
    printf("Ingrese el nombre(termina con FIN)\n");
    gets(p.nombre);
    while (strcmp((p.nombre), "FIN"))
    {
        fseek(xarchi, 0, SEEK_END);
        fgetpos(xarchi, &x);
        printf("Ingrese la edad:\n");
        scanf("%d", &p.edad);
        fwrite(&p, sizeof(p), 1, xarchi);
        printf("Ingrese el nombre (termina con FIN):\n");
        fflush(stdin);
        gets(p.nombre);
    }
}
void mostrar(FILE *archi)
{
    personas p;
    if((archi = fopen("ej1u6.txt", "r")) == NULL)
        printf("Hubo un error\n");
    else
    {
        while(fread(&p, sizeof(personas), 1, archi))
        {
            if(p.edad > 40)
                printf("El nombre del asistente es: %s y tiene %d a%cos", p.nombre, p.edad, 164);
        }
    }
}
int main()
{
    FILE *archi;
    if ((archi = fopen("ej1u6.txt", "w")) == NULL)
        printf("Hubo un error\n");
    else
    {
        cargar(archi);
        fclose(archi);
        mostrar(archi);
        fclose(archi);
    }
    return 7;
}
/*Lote de prueba:
Joaquin
20
Tomi
53
Nico
19
FIN
*/