const int N = 4;
const int M = 3;

void cerear(int arreglo[N][M])
{
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         arreglo[i][j] = 0;
      }
   }
}
void cargar(int arreglo[N][M])
{
   int tipo = 0;
   int cantidad = 0;
   for (int i = 0; i < M; i++)
   {
      printf("Ingrese las ventas al negocio %d\n", i + 1);
      printf("Ingrese el tipo de cerverza, 0 para detener\n");
      scanf("%d", &tipo);
      while (tipo != 0)
      {
         printf("Ingrese la cantidad de ventas\n");
         scanf("%d", &cantidad);
         arreglo[tipo-1][i] += cantidad;
         printf("Ingrese el tipo de cerverza, 0 para detener\n");
         scanf("%d", &tipo);
      }
   }
}

void calcularTotalTipo(int arreglo[N][M])
{
   int total = 0;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < M; j++)
      {
         total += arreglo[i][j];
      }
      printf("Total de ventas del tipo %d: %d\n", i + 1, total);
      total = 0;
   }
}

int calcularTotal(int arreglo[N][M], int tipo)
{
   int total = 0;
   for (int i = 0; i < N; i++)
   {
      total += arreglo[tipo-1][i];
   }
   return total;
}

int main()
{
   int arreglo[N][M], tipo;
   cerear(arreglo);
   cargar(arreglo);
   calcularTotalTipo(arreglo);
   printf("Ingrese el tipo de cerverza\n");
   scanf("%d", &tipo);
   printf("Total de ventas: %d\n", calcularTotal(arreglo, tipo));
}

/*Lote de prueba
3
12
1
8
2
20
1
6
0
4
10
4
14
2
24
0
3
25
2
18
3
5
0
*/