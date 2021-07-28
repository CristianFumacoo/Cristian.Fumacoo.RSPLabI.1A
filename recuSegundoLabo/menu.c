#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menu()
{
    int opc;

    printf("Bienvenido a mis Bicicletas\n\n");
    printf("1.Cargar Archivo\n");
    printf("2.Mostrar Bicis\n");
    printf("3.Crear Tiempos\n");
    printf("4.Filtrar por Tipo\n");
    printf("5.Ordenar\n");
    printf("Opcion: ");
    scanf("%d",&opc);

    return opc;
}

