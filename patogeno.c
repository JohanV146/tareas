#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct patogeno 
{
    char nombre;
    char efecto;
};

struct patogeno agregarP()
{
    struct patogeno temp;
    char nombreP;
    char efectoP;
    printf("Ingrese el Nombre del Patogeno: ");
    scanf("%s",&temp.nombre);
    fflush( stdin );
    printf("Ingrese el efecto del Patogeno: ");
    scanf("%s",&temp.efecto);
    fflush( stdin );
    return temp;
}

struct vacunas 
{
    char pais;
    struct patogeno  x;
    int cantidad;
};

struct vacunas agregarV()
{
    struct vacunas temp;
    char paisV;
    int cantidadV;
    printf("Ingrese el Nombre del pais: ");
    scanf("%s",&temp.pais);
    fflush( stdin );
    printf("Ingrese la cantidad de vacunas: ");
    scanf("%d",&temp.cantidad);
    fflush( stdin );
    temp.x=agregarP();
    return temp;
}

int main()
{
    int opcion;

    do
    {
        printf( "\n   1. Incluir patogeno");
        printf( "\n   2. Incluir cantidad de vacunas");
        printf( "\n   3. Cantidad de cobertura por pais por patogeno");
        printf( "\n   4. Salir." );
        printf( "\n\n   Introduzca opcion (1-4): ");

        scanf( "%d", &opcion );
        fflush( stdin );

        switch ( opcion )
        {
            case 1: 
                agregarP();
                break;

            case 2: 
                agregarV();
                break;

            case 3: 

                break;
        }

    } while ( opcion != 4 );

    return 0;
}
