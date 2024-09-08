/*Ejercicio 6
Una tienda de ropa comercializa 50 productos diferentes. Por cada producto se conoce: código (número entero que
varía entre 1 y 50), precio de costo y stock.
La tienda hace compras a 22 proveedores, de los cuales se conoce: Nombre y Número de Proveedor (es un número
entre 1000 y 1022).
Se pide redactar un algoritmo en C que, usando estructuras de datos óptimas y subprogramas eficientes, permita:
a) Almacenar en estructuras de datos adecuadas la información de los Productos y de los Proveedores.
b) Procesar las compras realizadas a los Proveedores, sabiendo que por cada compra se conoce el Número de
Proveedor, Código de Producto y Cantidad de unidades compradas. Con la información de cada compra se debe
actualizar el stock del producto y contar para cada proveedor la compra realizada.
c) Informar cuánto dinero hay invertido en cada producto.
d) Generar una nueva estructura de datos que contenga todos los datos de aquellos Proveedores a quienes se les
haya realizado más de 10 compras.
e) Mostrar la estructura de datos generada en el inciso d) ordenada alfabéticamente por Nombre de proveedor.
f) Ingresar por teclado un Nombre de proveedor e informar su Número y cantidad de compras realizadas. Nota:
Utilizar la estructura de datos generada en el inciso d).*/
#include <stdio.h>
#include <string.h>
const int N = 10;
const int M = 8;
const int ComprasTop = 10;
struct prenda
{
    char nombre[50];
    int stock;
    int cod;
    float precio;
};
struct proveedor
{
    char nombre[50];
    int cod;
    int ventas;
};
void cargarPrendas(struct prenda producto[]) // Solicita y almacena en una arreglo de registros a todos los productos
{
    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el codigo del producto\n");
        scanf("%d", &producto[i].cod);
        printf("Ingrese el nombre del producto\n");
        getchar();
        gets(producto[i].nombre);
        printf("Ingrese el precio del producto\n");
        scanf("%f", &producto[i].precio);
        printf("Ingrese el stock del producto\n");
        scanf("%d", &producto[i].stock);
    }
}
void cargarProveedores(struct proveedor proveedor[]) // Solicita y almacena en una arreglo de registros a todos los proveedores
{
    for (int i = 0; i < M; i++)
    {
        printf("Ingrese el codigo del proveedor\n");
        scanf("%d", &proveedor[i].cod);
        printf("Ingrese el nombre del proveedor\n");
        getchar();
        gets(proveedor[i].nombre);
        proveedor[i].ventas = 0;
    }
}
int sumarAProducto(int cant, int codProducto, struct prenda producto[]) // Suma las compras al stock del producto
{
    int exito = 0, i = 0;
    while ((codProducto != producto[i].cod) && (i <= N))
    {
        i++;
    }
    if (i < N)
    {
        producto[i].stock += cant;
        exito = 1;
    }
    return exito;
}
void sumarVentas(int cant, int codProveedor, struct proveedor proveedor[], struct prenda producto[], int codProducto) // Verifica que el codigo de producto y el codigo de proovedor sean correctos y suma las compras al proveedor
{
    int i = 0, fallo;
    while ((codProveedor != proveedor[i].cod) && (i <= M))
    {
        i++;
    }
    if (i < M)
    {
        proveedor[i].ventas += cant;
        fallo = sumarAProducto(cant, codProducto, producto);
    }
    else
    {
        printf("No se encontro el proveedor\n");
    }
    if (fallo == 0)
    {
        printf("No se encontro el producto\n");
        proveedor[i].ventas -= cant;
    }
}
void cargarCompras(struct prenda producto[], struct proveedor proveedor[]) // Solicita los datos de las compras y realiza las operaciones a traves de subprocesos
{
    int codProducto, cant, codProveedor;
    printf("Ingrese el codigo del producto, -1 para detener\n");
    scanf("%d", &codProducto);
    while (codProducto != -1)
    {
        printf("Ingrese la cantidad de productos comprados\n");
        scanf("%d", &cant);
        printf("Ingrese el codigo del proovedor al que se compro el producto\n");
        scanf("%d", &codProveedor);
        sumarVentas(cant, codProveedor, proveedor, producto, codProducto);
        printf("Ingrese el codigo del producto, -1 para detener\n");
        scanf("%d", &codProducto);
    }
}
void calcularInversion(struct prenda producto[]) // Realiza el calculo de inversion para cada producto y lo muestra en pantalla
{
    for (int i = 0; i < N; i++)
    {
        printf("El producto: %s, tiene una inversion de %f\n", producto[i].nombre, (producto[i].precio * producto[i].stock));
    }
}
int generarLista(struct proveedor proveedor[]) // Cuenta la cantidad de componenetes que cumplen con la condicion del subarreglo
{
    int topLong = 0;
    for (int i = 0; i < M; i++)
    {
        if (proveedor[i].ventas > ComprasTop)
        {
            topLong++;
        }
    }
    return topLong;
}
void cargarLista(struct proveedor proveedor[], struct proveedor top[]) // Copia en el subarreglo para los proovedores con mas de 10 ventas
{
    int j = 0;
    for (int i = 0; i < M; i++)
    {
        if (proveedor[i].ventas > ComprasTop)
        {
            top[j] = proveedor[i];
            j++;
        }
    }
}
void ordenarLista(struct proveedor top[], int topLong) // Ordena la lista ordenada alfabeticamente
{
    int j;
    char nombre[50];
    struct proveedor aux;
    for (int i = 0; i < topLong; i++)
    {
        j = i - 1;
        aux = top[i];
        strcpy(nombre, top[i].nombre);
        while ((j >= 0) && (strcmp(top[j].nombre, nombre) > 0))
        {
            top[j + 1] = top[j];
            j--;
        }
        top[j + 1] = aux;
    }
}
void mostrarLista(struct proveedor top[], int topLong) // Muestra la lista ordenada alfabeticamente con los proveedores que tienen mas de 10 ventas
{
    for (int i = 0; i < topLong; i++)
    {
        printf("El proveedor: %s, con numero: %d, tiene %d ventas\n", top[i].nombre, top[i].cod, top[i].ventas);
    }
}
void buscarEnLista(struct proveedor top[], int topLong) // Busca a un proveedor en la lista a traves del nombre solicitado
{
    int sup = topLong - 1, inf = 0, medio;
    medio = (sup + inf) / 2;
    char nombre[50];
    printf("Ingrese el nombre del proovedor que desea buscar:\n");
    getchar();
    gets(nombre);
    while ((inf <= sup) && (strcmp(nombre, top[medio].nombre) != 0))
    {
        if (strcmp(nombre, top[medio].nombre) == -1)
        {
            sup = medio - 1;
        }
        else
        {
            inf = medio + 1;
        }
        medio = (sup + inf) / 2;
    }
    if (inf <= sup)
    {
        printf("El proveedor tiene el codigo: %d, y ha logrado %d ventas\n", top[medio].cod, top[medio].ventas);
    }
    else
    {
        printf("El proveedor no esta en la lista\n");
    }
    return;
}
int main()
{
    struct prenda producto[N];
    struct proveedor proveedor[M];
    int topLong;
    cargarPrendas(producto);            // Actividad A)
    cargarProveedores(proveedor);       // Actividad A)
    cargarCompras(producto, proveedor); // Actividad B)
    calcularInversion(producto);        // Actividad C)
    printf("\n\n");
    topLong = generarLista(proveedor);  // Actividad D)
    struct proveedor top[topLong];
    cargarLista(proveedor, top); // Actividad E)
    ordenarLista(top, topLong);  // Actividad E)
    mostrarLista(top, topLong);  // Actividad E)
    buscarEnLista(top, topLong); // Actividad F)
    return 7;
}
/*Los productos se cargan en el siguiente orden:
Codigo del producto
Nombre del producto
Precio del producto
Cantida de stock

Los proveedores se cargan en el siguiente orden:
Codigo del proveedor
Nombre del proveedor

Las ventas se cargan en el siguiente orden:
Codigo de producto
Cantidad de productos comprados
Codigo de Proveedor

Bloque de prueba:
1
Jean Azul
7527.65
7
2
Camisa Verde
8652.76
4
3
Gorro Amarillo
2765.86
4
4
Camisa Blanca
8500.12
10
5
Pantalon Cargo Negro
12650.76
6
6
Saco Negro
10575.25
2
7
Vestido Estampado de Flores
12563.02
4
8
Falda Celeste
5670.86
4
9
Botas de Cuero
25643.72
3
10
Zapatos de Cuero marron
32789.45
2
1
Indumentaria Net
2
Zepellin Indumentarias
3
Agrupacion Textil
4
Argentina Prendas
5
Grupo King
6
Fabrica China
7
Falabella
8
Textiles Internacionales
1
8
2
2
12
1
3
11
3
4
7
4
5
12
5
6
13
7
7
12
6
8
5
8
9
2
1
10
4
1
-1
Fabrica China


Proveedor 1: 18
Proveedor 2: 8
Proveedor 3: 11
Proveedor 4: 7
Proveedor 5: 12
Proveedor 6: 12
Proveedor 7: 13
Proveedor 8: 5
5 proveedores entran al top
*/