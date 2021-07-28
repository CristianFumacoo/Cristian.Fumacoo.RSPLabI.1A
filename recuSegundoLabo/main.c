#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bicicletas.h"
#include "LinkedList.h"
#include "controller.h"
#include "parser.h"

int main()
{
    LinkedList* this = ll_newLinkedList();
    LinkedList* filtradasPorTipo = ll_newLinkedList();
    LinkedList* ordenadas = ll_newLinkedList();
    char respuesta = 's';
    char nombreArchivo[51];
    char tipoElegido[51];
    srand(time(NULL));

    do
    {
        switch(menu())
        {
        case 1:
            printf("Ingrese nombre del archivo sin extension: ");
            fflush(stdin);
            scanf("%s",&nombreArchivo);

            if(controller_loadFromText(strcat(nombreArchivo,".csv"),this))
            {
                printf("Archivo cargado correctamente.\n");
            }
            else
            {
                printf("Error.\n");
            }
            system("pause");
            system("cls");
            break;
        case 2:
            mostrarBicicletas(this);
            system("pause");
            system("cls");
            break;
        case 3:
            this = ll_map(this,numRandom);
            system("pause");
            system("cls");
            break;
        case 4:
            printf("Ingrese el tipo: ");
            fflush(stdin);
            scanf("%s",&tipoElegido);

            if(existeTipo(this,&tipoElegido))
            {
                filtradasPorTipo = ll_filter(this,buscarTipo,&tipoElegido);

                if(controller_saveAsText("filtradosPorTipo.csv",filtradasPorTipo))
                {
                    printf("Archivo creado correctamente.\n");
                }
                else
                {
                    printf("Error al crear el archivo.\n");
                }
            }
            else
            {
                printf("No existe ninguna bici de ese tipo.\n");
            }

            system("pause");
            system("cls");
            break;
        case 5:
            ll_sort(this,ordenar,1);

            if(controller_saveAsText("ordenados.csv",this))
            {
                printf("Archivo creado correctamente.\n");
            }
            else
            {
                printf("Error al crear el archivo.\n");
            }
            system("pause");
            system("cls");
            break;

        }
    }
    while(respuesta == 's');


    return 0;
}
