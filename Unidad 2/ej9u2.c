/*Ejercicio 9
En la Facultad se realiza un congreso para el cual se destinan 6 salas de conferencias y cada una representa un área
temática. En cada sala se dictan 4 conferencias en distintos turnos. Por cada interesado se ingresa número del área
temática (1-6), y turno al que quiere asistir (1-4). La Facultad desea llevar un registro de la cantidad de alumnos
inscriptos en cada área y en cada turno, para ello realizar los siguientes items:
a) Carga de los datos. La carga es desordenada, cada alumno indica área y turno. No se sabe la cantidad de alumnos.
b) Indicar la cantidad de inscriptos en cada turno de cada área.
c) Dada un área temática, indicar el promedio de inscriptos.
*/
#include <stdio.h>
const int F = 6;              // Cantidad de filas/salas/areas
const int C = 4;              // Cantidad de columnas/turnos
void cerear(int matriz[F][C]) // Matriz tiene salas/turnos
{
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            matriz[i][j] = 0; // Se asignan todos los elementos en 0;
        }
    }
}
void cargar(int matriz[F][C]) // Matriz tiene salas/turnos
{
    int sala, turno;
    printf("Ingrese sala, 0 para detener\n");
    scanf("%d", &sala);
    while (sala != 0)
    {
        printf("Ingrese turno\n");
        scanf("%d", &turno);
        matriz[sala - 1][turno - 1]++;
        printf("Ingrese sala, 0 para detener\n");
        scanf("%d", &sala);
    }
}
void contarAreas(int matriz[F][C])
{
    int sum;
    for (int i = 0; i < F; i++) // Itera por todas las filas del arreglo
    {
        sum = 0;
        for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
        {
            sum += matriz[i][j];
        }
        printf("La cantidad de inscritos al area tematica %d es de: %d\n", (i + 1), sum);
    }
}
void promediarSala(int matriz[F][C])
{
    int area, sum = 0;
    printf("Ingrese la sala que quiere promediar\n");
    scanf("%d", &area);
    for (int j = 0; j < C; j++) // Itera por todas las columnas del arreglo
    {
        sum += matriz[area - 1][j];
    }
    printf("El promedio de inscriptos por turno en la sala %d es de: %d", (area - 1), (sum / C));
}
int main()
{
    int matriz[F][C];
    cerear(matriz);
    cargar(matriz);
    contarAreas(matriz);
    promediarSala(matriz);
    return 7;
}
/*Lote de prueba
1
2
1
3
1
4
1
5
2
1
2
3
2
4
3
4
3
3
3
1
4
1
4
3
4
3
4
3
5
2
5
2
5
1
5
1
5
2
6
1
6
1
6
2
6
3
6
4
0
*/