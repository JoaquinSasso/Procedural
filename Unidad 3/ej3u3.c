/*Ejercicio 3
Un laboratorio abastece a 30 farmacias de la provincia. Dicho laboratorio comercializa 80 medicamentos (1..80) de
los que se debe registrar: Código de medicamento, nombre y precio unitario.
Se ingresan las ventas realizadas ordenada por farmacia. Por cada venta a una farmacia se ingresa: código de
medicamento y cantidad de unidades, finalizando con código de medicamento igual a 0 (cero)
Codificar un programa en C, que utilizando funciones permita:
1. Calcular y mostrar total de unidades vendidas de cada uno de los medicamentos.
2. Escribir el/los códigos/s del/los medicamento/s por el que se recaudó mayor importe.
3. Indicar la cantidad de unidades vendidas para un código de medicamento ingresado por teclado.
4. Dado el nombre de un medicamento indicar el importe total recaudado y la cantidad de unidades vendidas.
5. Indicar la cantidad de unidades vendida a cada farmacia y el importe total que pagó cada una.*/
#include<stdio.h>
#include<string.h>
#define F 30 
#define N 80
struct producto{
  int cod;
  char nombre[80];
  float precio;
  int total;
};
struct farmacia
{
  struct producto med[F];
};
void cargar(struct farmacia farmacias[F])
{
  for(int i = 0; i < N; i++)
  {
		printf("Ingrese el codigo del medicamento\n");
    scanf("%d", &farmacias[0].med[i].cod);
    printf("Ingrese el nombre del medicamento\n");
    fflush(stdin);
    gets(farmacias[0].med[i].nombre);
    printf("Ingrese el precio del medicamento\n");
    scanf("%f", &farmacias[0].med[i].precio);
    farmacias[0].med[i].total = 0;
  }
  for(int i = 1; i < F; i++)
  {
    farmacias[i] = farmacias[0];
  }
}
int buscaindice(int c, struct farmacia farmacias[F])
{
  int i=0;
  farmacias[3].med[N+1].cod = -100;
  while((c!=farmacias[3].med[i].cod)&&(i<=N))
  	{
     i++;
  	}
  if(i == N)
    i = -1;
  return i;
}
void cargarventas(struct farmacia farmacias[F]){
  int cod, cant,indice;
  	for(int i=0;i<F;i++)
		{
  		printf("\ningresar codigo de medicamento\n");
			fflush(stdin);
      scanf("%d", &cod);
      	while(cod!=0)
        {
					indice=buscaindice(cod,farmacias);
					if(indice>0)
          {
         		printf("\ningresar cantidad de unidades vendidas\n");
         	 	fflush(stdin);
         	 	scanf("%d", &cant);
						farmacias[i].med[indice].total+=cant;
  					printf("\ningresar codigo de medicamento\n");
						fflush(stdin);
     				scanf("%d", &cod);
          }
        }
    }
return;
}


void recaud(struct farmacia farmacias[F]){  // punto 2
  float max=0, import;
  int i;
  for(i=0;i<F;i++){
    for(int j = 0; j < N; j++)
    {
   		import= farmacias[i].med[j].precio * farmacias[i].med[j].total;
   		if(max<import){
     		max=import;
			}
    } 
  }
  for(i=0;i<F;i++){
    for(int j = 0; j < N; j++)
    {
        import= farmacias[i].med[j].precio * farmacias[i].med[j].total;
    	if(import == max) {
        printf("El medicamento con codigo: %d tiene el maximo de importe recaudado\n", farmacias[i].med[j].cod);
    }
  }
  }
  return;
}

void cantidadPorCodigo(struct farmacia farmacias[F])
{
  int codigo, indice, total = 0;
  printf("Ingrese el codigo que desea buscar\n");
  scanf("%d", &codigo);
  indice = buscaindice(codigo, farmacias);
  if (indice > 0)
  {
    for(int i = 0; i < F; i++)
    {
      total += farmacias[i].med[indice].total;
    }
    printf("El medicamento se vendio %d veces en total\n", total);
  }
  else
    printf("El medicamento no se encuentra cargado\n");
}
void buscanom(struct farmacia farmacias[F])
{
  int i = 0;
  char nomb[80];
  printf("\ningresar el nombre del medicamento\n");
  fflush(stdin);
  gets(nomb);
  	while((strcmp(nomb,farmacias[0].med[i].nombre)!=0) && (i<=N))
    {
      i++;
    }
		if(i<N)
    {
      printf("\nEl importe total recaudado del medicamento es de: %2.f\n", farmacias[0].med[i].total * farmacias[0].med[i].precio);
			printf("\nLa cantidad de unidades vendidas es de: %d\n", farmacias[0].med[i].total);
    }
return;
}
int main(){

  struct farmacia farmacias[N];
	cargar(farmacias);
	cargarventas(farmacias);
  recaud(farmacias); //punto 2
	buscanom(farmacias); // punto 4
  
  return 7;
}