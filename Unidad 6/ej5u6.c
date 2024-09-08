/*Ejercicio 5
Una biblioteca procesa diariamente el archivo, “TITULOS.DAT”. Este archivo almacena la información para cada libro:
Código (de 1 a 500), Título, Autor y Cantidad de ejemplares disponibles. El archivo está ordenado en forma
secuencial por código a partir de 1.
Se pide realizar un programa óptimo que a través del uso de funciones genere un menú de opciones que responda a
las siguientes solicitudes:
a) Dado el código de un libro, mostrar el título y la cantidad de ejemplares disponibles.
b) Dado el título de un libro, mostrar el autor.
c) Dado un Autor, mostrar todos los libros de su autoría registrados.
d) Agregar un nuevo libro al archivo.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const char NArchivo[] = "TITULOS.dat";
int N = 5;
typedef struct
{
   int cod;
   char titulo[50];
   char autor[50];
   int cantidad;
} libro;

void cargar(FILE *archi)
{
   if ((archi = fopen(NArchivo, "wb")) == NULL)
      printf("Hubo un error al crear el archivo\n");
   else
   {
      libro a;
      fpos_t x;
      for (int i = 1; i <= N; i++)
      {
         printf("Ingrese el titulo del libro %d\n", i);
         fflush(stdin);
         gets(a.titulo);
         printf("Ingrese el autor del libro\n");
         fflush(stdin);
         gets(a.autor);
         printf("Ingrese la cantidad de ejemplares del libro\n");
         scanf("%d", &a.cantidad);
         a.cod = i;
         fseek(archi, 0, SEEK_END);
         fgetpos(archi, &x);
         fwrite(&a, sizeof(libro), 1, archi);
      }
      fclose(archi);
   }
}
void buscarCodigo(FILE *archi)
{
   libro a;
   if ((archi = fopen(NArchivo, "rb")) == NULL)
      printf("Hubo un error al abrir el archivo en modo lectura\n");
   else
   {
      int cod;
      printf("Ingrese el codigo del libro que desea buscar\n");
      scanf("%d", &cod);
      fread(&a, sizeof(libro), 1, archi);
      while ((a.cod != cod) && fread(&a, sizeof(libro), 1, archi) != 0)
         ;
      if (a.cod != cod)
         printf("No se encontro el codigo\n");
      else
         printf("El titulo del libro es: %s y tiene %d ejemplares disponibles\n", a.titulo, a.cantidad);
      fclose(archi);
   }
}
void buscarTitulo(FILE *archi)
{
   libro a;
   if ((archi = fopen(NArchivo, "rb")) == NULL)
      printf("Hubo un error al abrir el archivo en modo lectura\n");
   else
   {
      char titulo[50];
      printf("Ingrese el titulo del libro que desea buscar\n");
      fflush(stdin);
      gets(titulo);
      fread(&a, sizeof(libro), 1, archi);
      while ((strcmp(a.titulo, titulo) != 0) && fread(&a, sizeof(libro), 1, archi) != 0)
         ;
      if (strcmp(a.titulo, titulo) != 0)
         printf("No se encontro el codigo\n");
      else
         printf("El autor del libro es: %s \n", a.autor);
      fclose(archi);
   }
}
void buscarAutor(FILE *archi)
{
   libro a;
   if ((archi = fopen(NArchivo, "rb")) == NULL)
      printf("Hubo un error al abrir el archivo en modo lectura\n");
   else
   {
      char autor[50];
      printf("Ingrese el titulo del libro que desea buscar\n");
      fflush(stdin);
      gets(autor);
      for (int i = 0; i < N; i++)
      {
         fread(&a, sizeof(libro), 1, archi);
         if (strcmp(a.autor, autor) == 0)
            printf("El autor escribio: %s \n", a.titulo);
      }
      fclose(archi);
   }
}
void agregarLibro(FILE *archi)
{
   if ((archi = fopen(NArchivo, "ab")) == NULL)
      printf("No se pudo abrir el archivo para modificarlo\n");
   else
   {
      libro a;
      printf("Ingrese el titulo del libro\n");
      fflush(stdin);
      gets(a.titulo);
      printf("Ingrese el autor del libro\n");
      fflush(stdin);
      gets(a.autor);
      printf("Ingrese la cantidad de ejemplares del libro\n");
      scanf("%d", &a.cantidad);
      N = N + 1;
      a.cod = N;
      fwrite(&a, sizeof(libro), 1, archi);
   }
   fclose(archi);
}
int main()
{
   FILE *archi = NULL;
   int opcion;
   printf("Seleccione una opcion del menu:\n0:Cerrar programa\n1:Cargar libros\n");
   scanf("%d", &opcion);
   while (opcion != 0)
   {
      switch (opcion)
      {
      case 1:
         cargar(archi);
         break;
      case 2:
         buscarCodigo(archi);
         break;
      case 3:
         buscarTitulo(archi);
         break;
      case 4:
         buscarAutor(archi);
         break;
      case 5:
         agregarLibro(archi);
         printf("El valor de N es: %d\n", N);
         break;
      default:
         printf("El numero ingresado no corresponde a una opcion\n");
         break;
      }
      printf("Seleccione una opcion del menu:\n0:Cerrar programa\n1:Cargar libros\n2:Buscar un libro por codigo\n3:Buscar un libro por titulo\n4:Buscar todos los libros de un autor\n5:Agregar un libro\n");
      scanf("%d", &opcion);
   }
   return 7;
}
/*Lote de prueba
1
Mi lucha
Adolf Hitler
9
La Biblia
Jesus de Nazaret
666
Mecanismos de Redstone
Luca Oliva
777
Como vender una grafica
Juan Cruz Torti Bogni
0
Fortnite para Principiantes
Luca Oliva
3

Luna de Pluton
Drozz Roztank
8
*/