/*Ejercicio 2
Dada la frase “Programación Procedural 2023”, leerla desde teclado en una cadena de caracteres y:
a) Reemplazar el 2 por un 0 (Solo cambiar ese carácter)
b) Copiar la palabra “Programación” a una nueva cadena de caracteres.
c) Contar la cantidad de vocales de la frase.
*/
#include <stdio.h>
#include <string.h>
const int N = 100;
void espaciador(char frase[])
{
    for(int i = 0; i < N; i++)
    {
        frase[i] = ' ';
    }
}
void cargar(char frase[])
{
    printf("Ingrese la frase que desee:\n");
    fflush(stdin);
    gets(frase);
}
void cambiar(char frase[]) //Funcion cambia solo el primer 2 de la frase que, corresponde al milenio
{
    int i = 0;
    while ((frase[i] != '2') && (i <= N))
    {
        i++;
    }
    if (i < N)
    {
        frase[i] = '0';
    }
}
void copiar(char frase[], char copia[])
{
    int i = 0;
    while ((frase[i] != ' ') && (i < N))
    {
        copia[i] = frase[i];
        i++;
    }
}
void contadorVocales(char frase[])
{
    int contador = 0;
    for (int i = 0; i < N; i++)
    {
        switch(frase[i])
        {
        case 'a' :
            contador++;
            break;
        case 'e':
            contador++;
            break;
        case 'i':
            contador++;
            break;
        case 'o':
            contador++;
            break;
        case 'u':
            contador++;
            break;
        case 'A' :
            contador++;
            break;
        case 'E':
            contador++;
            break;
        case 'I':
            contador++;
            break;
        case 'O':
            contador++;
            break;
        case 'U':
            contador++;
            break;
        }
    }
    printf("La cantidad de vocales en la frase es de: %d\n", contador);
}
int main()
{
    char frase[N];
    char copia[N];
    espaciador(frase);
    cargar(frase);
    cambiar(frase);
    printf("Tu frase cambio a: %s\n", frase);
    copiar(frase, copia);
    printf("Tu copia contiene: %s\n", copia);
    contadorVocales(frase);
    return 1;
}