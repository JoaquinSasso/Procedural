#include<stdio.h>
#define cant 5
void ordenarSub(int sub[])
{
   int j;
   int aux;
   for(int i = 0; i < cant; i++)
   {
      j = i;
      aux = sub[i];
      while(aux > sub[j-1])
      {
         sub[j] = sub[j-1];
         j--;
      }
      sub[j] = aux;
   }
}
void mostrar(int sub[])
{
      for (int i = 0; i < cant; i++)
   {
      printf("%d, ",sub[i]);
   }
   printf("\n");
}
int main()
{
   int sub[cant];
   sub[0] = 1;
   sub[1] = 9;
   sub[2] = 4;
   sub[3] = -2;
   sub[4] = 12;
   mostrar(sub);
   ordenarSub(sub);
   mostrar(sub);
   return 0;
}