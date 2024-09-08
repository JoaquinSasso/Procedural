/*Un comercio almacena información de productos para la venta, por cada uno se conoce: nombre, tipo (1 bazar, 2: muebles, 3: manteleria), precio de venta y stock.
Se pide que usando funciones para cada item, resuelva lo siguiente
a) Ingresar una cantidad de productos y generar un arreglo dinámico para almacenar los datos de cada uno.
b)Decir la cantidad de productos de manteleria con stock 0 y la cantidad cuyo precio es menor a 1000 (hacer una función que devuelva ambos resultados). 
c) indicar el precio promedio de los productos con stock mayor 10.
d) Mostrar los nombres y stock de los productos cuyo precio de venta sea mayor a uno ingresado por teclado (hacer una función recursiva)*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct
{
	char nombre[50];
	int tipo;
	int stock;
	float precio;
}producto;
void cargar(producto arre[], int n)
{
	for(int i = 0; i < n; i++)
	{
		printf("Ingrese el nombre del producto %d\n", (i+1));
		fflush(stdin);
		gets(arre[i].nombre);
		printf("Ingrese el tipo del producto\n");
		scanf("%d", &arre[i].tipo);
		printf("Ingrese el stock del producto\n");
		scanf("%d", &arre[i].stock);
		printf("Ingrese el precio del producto\n");
		scanf("%f", &arre[i].precio);
	}
}
void contador(producto arre[], int n, int *baratos, int *manteleria)
{	
	for(int i = 0; i < n; i++)
	{
		if((arre[i].tipo == 3) && (arre[i].stock == 0))
			*manteleria = *manteleria +1;
		if(arre[i].precio < 1000)
			*baratos = *baratos + 1;
	}
}
void promediar(producto arre[], int n)
{
	int cant = 0;
	float total = 0;
	for(int i = 0; i < n; i++)
	{
		if(arre[i].stock > 10)
		{
			cant++;
			total += arre[i].precio;
		}
	}
	printf("El precio promedio de los productos con stock superior a 10 es de %.2f\n", (total / cant));
}
void mostrar(producto arre[], int n, int minimo, int i)
{
	if(i == n)
		return;
	if(arre[i].precio > minimo)
		printf("El producto %s tiene un precio de venta de %.2f\n", arre[i].nombre, arre[i].precio);
	mostrar(arre, n, minimo, i+1);
}
int main()
{
	producto *arre;
	int n, baratos = 0, manteleria = 0, minimo;
	printf("Ingrese la cantidad de productos\n");
	scanf("%d", &n);
	arre = (producto*) malloc(sizeof(producto)*n);
	cargar(arre, n);
	contador(arre, n, &baratos, &manteleria);
	printf("La cantidad de productos de manteleria con stock 0 es de: %d\n", manteleria);
	printf("La cantidad de productos cuyo precio es menor a 1000 es de %d\n", baratos);
	promediar(arre, n);
	printf("Ingrese el precio de venta minimo a mostrar\n");
	scanf("%d", &minimo);
	mostrar(arre, n, minimo, 0);
	return 0;
}
/*Lote de prueba
8
Mesa
2
4
15320.56
Repasador
3
21
1560
Agua
1
42
446
Placard
2
3
65870
Cubre Mesas
3
12
12000
Mantel
3
0
8650
Silla
2
12
8700
Galletas
1
43
650.76
*/