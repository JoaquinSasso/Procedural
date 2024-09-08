/*Ejercicio 9
El Ministerio de Producción ha lanzado un Plan de Promoción de Capacitación de Empleados (PPCE) para las PYMES
(Pequeñas y Medianas Empresas). La siguiente tabla detalla los montos financiados para el año actual (expresados
en millones de pesos) según las distintas categorías/sectores, lo que permite clasificar cada una de las empresas.

Categoría / Sector  | Agropecuario  | Industria y Minería   |   Comercio    | Servicios   | Construcción    |
        Micro       |       2       |           7,5         |       9       |     2,5     |       3,5       |
        Pequeña     |       13      |           45,5        |       55      |     15      |       22,5      |
        Mediana     |       100     |           360         |       450     |     125     |       180       |

a) Indicar el monto total financiado para una categoría ingresada por teclado.
b) Indicar el monto total financiado para el sector de Servicios, sin importar la categoría de la empresa.
c) Emitir un listado con el total financiado, sin importar la categoría/ sector.
d) Emitir un listado con los montos superiores a uno ingresado por teclado, y a continuación los inferiores e iguales,
indicando sector y categoría.
*/
#include <stdio.h>
#include <string.h>
const int F = 3;
const int C = 5;
void cargar(float a[F][C])
{
   a[0][0] = 2;    // Micro / Agropecuario
   a[0][1] = 7.5;  // Micro / Industria y Minería
   a[0][2] = 9;    // Micro / Comercio
   a[0][3] = 2.5;  // Micro /  Servicios
   a[0][4] = 3.5;  // Micro / Construcción
   a[1][0] = 13;   // Pequeña / Agropecuario
   a[1][1] = 45.5; // Pequeña / Industria y Minería
   a[1][2] = 55;   // Pequeña / Comercio
   a[1][3] = 15;   // Pequeña / Servicios
   a[1][4] = 22.5; // Pequeña / Construcción
   a[2][0] = 100;  // Mediana / Agropecuario
   a[2][1] = 360;  // Mediana / Industria y Minería
   a[2][2] = 450;  // Mediana / Comercio
   a[2][3] = 125;  // Mediana / Servicios
   a[2][4] = 180;  // Mediana / Construcción
   return;
}
float montoCategoria(float a[C], int i)
{
   if (i == C)
      return 0;
   else
      return a[i] + montoCategoria(a, i + 1);
}
float montoServicios(float a[F][C], int i)
{
   if (i == F)
      return 0;
   else
      return a[i][3] + montoServicios(a, i + 1);
}
float listadoFinanciado(float a[F][C], int i, int j)
{
   if (i == F)
      return 0;
   else if (j < C)
   {
      printf("La categoria %d sector %d tuvo una financiacion de $%.1f Millones\n", i + 1, j + 1, a[i][j]);
      return a[i][j] + listadoFinanciado(a, i, j + 1);
   }
   else
      return listadoFinanciado(a, i + 1, 0);
}
void compararMontos(float a[F][C], float monto, int i, int j)
{
   if(i == F)
      return;
   else if(j < C)
   {
      if(a[i][j] > monto)
         printf("El monto de la categoria: %d, sector: %d supero el monto\n", i+1, j+1);
      compararMontos(a, monto, i, j+1);
      if(a[i][j] <= monto)
         printf("El monto de la categoria: %d, sector: %d igualo o no supero el monto\n", i+1, j+1);
   }
   else
      return compararMontos(a, monto, i+1, 0);
}
int main()
{
   float a[F][C], monto;
   int cat ,i = 0;
   cargar(a);
   printf("Ingrese la categoria a la que desea calcular el monto total\n0:Micro\n1:Pequena\n2:Mediana\n");
   scanf("%d", &cat);
   if ((cat >= 0) && (cat < 3))
      printf("El monto total de la categoria es de: $%.1f Millones\n", montoCategoria(a[cat], i));
   printf("El monto total del sector servicios es de: $%.1f Millones\n", montoServicios(a, i));
   printf("La financiacion total fue de: $%.1f Millones\n", listadoFinanciado(a, i, i));
   printf("Ingrese el monto que desee comparar\n");
   scanf("%f", &monto);
   compararMontos(a, monto, i, i);
   return 7;
}