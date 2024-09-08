/*Ejercicio 11
El concesionario CarVenta ha organizado un concurso entre su tres grupos de vendedores que consiste en brindarle un viaje a 
Bariloche al grupo que más venda. 
Para ello ha entregado la cartera de clientes en un único archivo (conteniendo Nombre completo, y nro de teléfono) para
repartirla en tres archivos distintos tomando del archivo principal el primer cliente y guardarlo en el archivo del primer grupo,
luego, el segundo cliente, para guardarlo en el archivo del segundo grupo y así hasta terminar de repartir todos el listado de
clientes. 
Cuentan con un periodo de tiempo de 6 meses para acumular sus ventas, por cada venta, se registrará, grupo del vendedor que 
vendió, y monto de la venta, la carga de las ventas finaliza con un importe de venta negativo.
Finalizado el concurso el dueño del concesionario necesita saber:
1. Cantidad de clientes asignado a cada grupo
2. mayor monto de venta de cada grupo.
3. promedio de venta de cada grupo
4. Grupo ganador*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
const int N = 3;
typedef struct
{
char nombre[40];
int telefono;
} cliente;

typedef struct lista{
float monto;
struct lista *sig;
}nodo;

typedef struct
{
float montoVentas;
int cantClientes;
FILE *archivo;
nodo *cabeza;
}vendedor;

int abrirArchivos(FILE *principal, vendedor grupos[])
{
  int error = 0;
  if ((principal=fopen("principal.dat","r+")) == NULL)
    error = 1;
  if ((grupos[0].archivo=fopen("grupo1.dat","r+")) == NULL)
    error = 1;
  if ((grupos[1].archivo=fopen("grupo2.dat","r+")) == NULL)
    error = 1;
  if ((grupos[2].archivo=fopen("grupo3.dat","r+")) == NULL)
    error = 1;
  return error;
}
void cerrarArchivos(FILE *principal, vendedor grupos[])
{
  fclose(principal);
  for (int i = 0; i < N; i++)
  {
    fclose(grupos[i].archivo);
  }
}
void cargarClientes(FILE *principal)
{
  cliente c;
  rewind(principal);
  printf("Ingrese el nombre del cliente\n");
  fflush(stdin);
  gets(c.nombre);
  while((strcmp(c.nombre,"FIN")) != 0)
  {  
    printf("Ingrese el telefono del cliente\n");
    fflush(stdin);
    scanf("%d", &c.telefono);
    fwrite(&c,sizeof(cliente),1,principal);
    printf("Escriba el nombre del cliente o FIN para terminar\n");
    fflush(stdin);
    gets(c.nombre);
  }
  return;
}

void distribuirClientes(vendedor grupos[], FILE *principal)
{
  cliente c;
  int i = 0;
  rewind(principal);
  for(i=0;i<N;i++)
    rewind(grupos[i].archivo);
  while(fread(&c, sizeof(cliente),1,principal))
    {
      switch (i)
      {
        case 0:
          fwrite(&c,sizeof(cliente),1,grupos[0].archivo);
          grupos[0].cantClientes++;
          break;
        case 1:
          fwrite(&c,sizeof(cliente),1,grupos[1].archivo);
          grupos[1].cantClientes++;
          break;
        case 2:
          fwrite(&c,sizeof(cliente),1,grupos[2].archivo);
          grupos[2].cantClientes++;
          break;
      }
      if(i < 2)
        i++;
      else
        i = 0;
    }
  return;
}
void iniciarGrupos(vendedor grupos[])
{
  for(int i = 0; i < N; i++)
    {
      grupos[i].cabeza = NULL;
      grupos[i].montoVentas = 0;
      grupos[i].cantClientes = 0;
    }
}
void cargarVentas(vendedor grupos[])
{
  float importe;
  int gr;
  printf("Ingrese el importe de la venta o negativo para terminar\n");
  scanf("%f", &importe);
  while(importe > 0)
    {
      nodo *nuevo = (nodo*)malloc(sizeof(nodo));
      nuevo->monto = importe;
      printf("Ingrese el grup del vendedor\n");
      scanf("%d", &gr);
      nuevo->sig = grupos[gr-1].cabeza;
      grupos[gr-1].cabeza = nuevo;
      grupos[gr-1].montoVentas += importe;
      printf("Ingrese el importe de la venta o negativo para terminar\n");
      scanf("%f", &importe);
    }
}
void mostrarCantidadDeClientes(vendedor grupos[])
{
  for (int i = 0; i < N; i++)
  {
    printf("La cantidad de clientes asignados a el grupo %d es de %d\n", (i+1), grupos[i].cantClientes);
  }
}
void montoMaximo(vendedor grupos[])
{
  nodo *actual;
  float max;
  for (int i = 0; i < N; i++)
  {
    max = -1;
    actual = grupos[i].cabeza;
    while (actual != NULL)
    {
      if(actual->monto > max)
        max = actual->monto;
      actual = actual->sig;
    }
    printf("El monto maximo del grupo %d es de %.2f\n", (i+1), max);
  }
  
}
int main() {
  FILE *principal;
  vendedor grupos[3];
  if ((principal=fopen("principal.dat","w+")) == NULL)
    printf("No se pudo abrir el archivo");
  if ((grupos[0].archivo=fopen("grupo1.dat","w+")) == NULL)
      printf("No se pudo abrir el archivo");
  if ((grupos[1].archivo=fopen("grupo2.dat","w+")) == NULL)
      printf("No se pudo abrir el archivo");
  if ((grupos[2].archivo=fopen("grupo3.dat","w+")) == NULL)
      printf("No se pudo abrir el archivo");
  else
  {
    cargarClientes(principal);
    iniciarGrupos(grupos);
    distribuirClientes(grupos, principal);
    cerrarArchivos(principal, grupos);
    cargarVentas(grupos);
    mostrarCantidadDeClientes(grupos);
    montoMaximo(grupos);
  }
  return 0;
}
/*Lote de prueba
Leonel Messi
2645996209
Fernando Torres
2645945679
Ronaldinho Gaucho
2645896432
Lui Kang
2648901234
Smurf Cat
2647812459
Pedro Sanchez
25435345678
Juan Suarez
26435585278
Angel Di Maria
25433456789
Nicolas Vargas
25433458236
Alexis MacAlister
20202020202
Emiliano Martinez
23232323232
Cristian Romero
13131313131
FIN
5000000
1
3000000
3
7000000
1
2764830
2
5000000
3
3375870
1
6783452
3
2345670
2
5678900
3
6543215
2
-1
*/

