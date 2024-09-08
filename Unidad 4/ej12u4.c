/*Ejercicio 12
Una cadena de comidas rápidas necesita información estratégica que permita apoyar la toma de decisiones en
relación a las ventas realizadas en cada una de las 4 sucursales que dispone en la ciudad. De cada sucursal se
conoce: número, nombre, dirección y teléfono. En cuanto a los 10 productos distintos que comercializa, se conoce:
código de producto, nombre, calorías y precio. Por cada venta realizada, se ingresa el número de sucursal, código de
producto y cantidad. Esta información no tiene ningún orden en particular, y el ingreso termina con número de
sucursal 0. Concretamente necesita conocer:
a) Cantidad de productos vendidos por sucursal.
b) Importe total de productos vendidos por sucursal.
c) Obtener la sucursal (nombre) y el producto (nombre y precio), que registró el mayor importe de venta.
d) Dado un número de sucursal, indicar el producto (todos los datos) que registró el mayor consumo de calorías
(suponer único).
e) Dado un número de producto, indicar la sucursal (nombre y teléfono) donde se registró el menor importe
vendido.
NOTA: Es importante optimizar el código, por lo tanto, cuando deba trabajar sobre una fila de la tabla, pasar sólo la
fila. Realice un menú de opciones y validar los datos de entrada.*/
#include <stdio.h>
#include <string.h>
#define N 2 // Sucursales
#define M 3 // Productos
struct sucursal
{
    char nombre[50];
    char dir[50];
    int tel;
    int cant[M];
    int cantTotal;
    float impTotal;
};
struct producto
{
    char nombre[50];
    int cal;
    float precio;
    int cant;
};
void inicializarSucursales(struct sucursal s[N], int i)
{
    if (i == N)
        return;
    else
    {
        s[i].cantTotal = 0;
        s[i].impTotal = 0;
        s[i].tel = 0;
        for (int j = 0; j < M; j++)
        {
            s[i].cant[j] = 0;
        }
        return inicializarSucursales(s, i + 1);
    }
}
void inicializarProductos(struct producto p[M], int i)
{
    if (i == M)
        return;
    else
    {
        p[i].cant = 0;
        p[i].cal = 0;
        return inicializarProductos(p, i + 1);
    }
}
void cargarProducto(struct producto p[M], int codP)
{
    printf("El producto no esta cargado, se solicitaran los datos\n");
    printf("Ingrese el nombre del producto\n");
    fflush(stdin);
    gets(p[codP - 1].nombre);
    printf("Ingrese las calorias del producto\n");
    scanf("%d", &p[codP - 1].cal);
    printf("Ingrese el precio del producto\n");
    scanf("%f", &p[codP - 1].precio);
}
void cargarSucursal(struct sucursal s[N], int codS)
{
    printf("La sucursal no esta cargada, se solicitaran los datos\n");
    printf("Ingrese el nombre de la sucursal\n");
    fflush(stdin);
    gets(s[codS - 1].nombre);
    printf("Ingrese la direccion de la sucursal\n");
    fflush(stdin);
    gets(s[codS - 1].dir);
    printf("Ingrese el telefono de la sucursal\n");
    scanf("%d", &s[codS - 1].tel);
}
void cargar(struct sucursal s[N], struct producto p[M])
{
    int codP, codS, cant;
    printf("Ingrese el codigo de producto vendido (1-%d), 0 para detener carga\n", M);
    scanf("%d", &codP);
    if (codP == 0)
        return;
    if ((codP > M) || (codP < 0))
    {
        printf("El producto no existe\n");
        return cargar(s, p);
    }
    if (p[codP - 1].cal == 0)
        cargarProducto(p, codP);
    printf("Ingrese el numero de la sucursal a la que se vendio (1-%d)\n", N);
    scanf("%d", &codS);
    if ((codS > N) || (codS <= 0))
    {
        printf("La sucursal no existe\n");
        return cargar(s, p);
    }
    if (s[codS - 1].tel == 0)
        cargarSucursal(s, codS);
    printf("Ingrese la cantidad vendida\n");
    scanf("%d", &cant);
    p[codP - 1].cant += cant;
    s[codS - 1].cantTotal += cant;
    s[codS - 1].impTotal += cant * p[codP - 1].precio;
    s[codS - 1].cant[codP - 1] += cant;
    return cargar(s, p);
}
void cantDeVentasSucursal(struct sucursal s[N], int i)
{
    if (i == N)
        return;
    printf("La cantidad de ventas de la sucursal: %s fue de %d\n", s[i].nombre, s[i].cantTotal);
    return cantDeVentasSucursal(s, i + 1);
}
void impDeVentasSucursal(struct sucursal s[N], int i)
{
    if (i == N)
        return;
    printf("El importe de ventas de la sucursal: %s fue de %.2f\n", s[i].nombre, s[i].impTotal);
    return impDeVentasSucursal(s, i + 1);
}
void maxSucursal(struct sucursal s[N], int i, int *max, int *iMax)
{
    if (i == N)
    {
        printf("La sucursal con importe maximo es: %s con un importe de %.2f\n", s[*iMax].nombre, s[*iMax].impTotal);
        return;
    }
    if (s[i].impTotal > *max)
    {
        *max = s[i].impTotal;
        *iMax = i;
    }
    return maxSucursal(s, i + 1, &*max, &*iMax);
}
void maxProducto(struct producto p[M], int i, int *max, int *iMax)
{
    if (i == M)
    {
        printf("El producto con importe maximo es: %s con un precio de %.2f y un importe de %.2f\n", p[*iMax].nombre, p[*iMax].precio, (p[*iMax].cant * p[*iMax].precio));
        return;
    }
    if ((p[i].cant * p[i].precio) > *max)
    {
        *max = p[i].cant * p[i].precio;
        *iMax = i;
    }
    return maxProducto(p, i + 1, &*max, &*iMax);
}
void caloriasProductoEnSucursal(struct sucursal s, struct producto p[M], int *max, int *iMax, int j)
{
    if (j == M)
    {
        printf("El producto con mas calorias consumidas fue: %s, con %d calorias y un precio de %.2f", p[*iMax].nombre, p[*iMax].cal, p[*iMax].precio);
        return;
    }
    if ((s.cant[j] * p[j].cal) > *max)
    {
        *max = (s.cant[j] * p[j].cal);
        *iMax = j;
    }
    return caloriasProductoEnSucursal(s, p, &*max, &*iMax, j+1);
}
int main()
{
    int menu, i = 0, max, iMax, codS;
    struct sucursal s[N];
    struct producto p[M];
    inicializarSucursales(s, i);
    inicializarProductos(p, i);
    printf("MENU\n");
    printf("  1:Carga \n  2:Total de productos vendidos por sucursal\n  3:Importe total por sucursal\n  4:Sucursal y producto con maximo importe\n  5:Producto con mayor consumo de calorias en una sucursal\n  6:Sucursal de menor venta para un producto\n");
    printf("Seleccione la opcion requerida, 0 para detener ejecucion:\n");
    scanf("%d", &menu);
    while (menu != 0)
    {
        switch (menu)
        {
        case 1:
            cargar(s, p);
            break;
        case 2:
            cantDeVentasSucursal(s, i);
            break;
        case 3:
            impDeVentasSucursal(s, i);
            break;
        case 4:
            max = -1;
            maxSucursal(s, i, &max, &iMax);
            max = -1;
            maxProducto(p, i, &max, &iMax);
            break;
        case 5:
            max = -1;
            printf("Ingrese el numero de la sucursal en la que quiere buscar el producto con mas calorias consumidas\n");
            scanf("%d", &codS);
            if ((codS > N) || (codS <= 0))
                printf("La sucursal no existe\n");
            else
                caloriasProductoEnSucursal(s[codS - 1], p, &max, &iMax, i);
            break;
        default:
            break;
        }
        printf("\nMENU\n");
        printf("  1:Carga \n  2:Total de productos vendidos por sucursal\n  3:Importe total por sucursal\n  4:Sucursal y producto con maximo importe\n  5:Producto con mayor consumo de calorias en una sucursal\n  6:Sucursal de menor venta para un producto\n");
        printf("Seleccione la opcion requerida, 0 para detener ejecucion:\n");
        scanf("%d", &menu);
    }
    return 7;
}
/*Lote de prueba
1
1
Frijol
874
962.8
1
Alimentos Congelados
Av. Ignacio de la Rosa 920 Oeste
42175693
5
2
Prepizzas
1520
525.32
2
Proveedora Alimenticia
Av. Libertador Gral San Martin 1435 Este
2648792345
9
3
Carne Molida
1132
952
1
10
1
1
7
1
2
4
3
2
5
2
2
8
2
1
3
0

*/