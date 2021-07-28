#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "bicicletas.h"
#include "LinkedList.h"

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    FILE* pArchivo;
    int retorno= 0;

    pArchivo=fopen(path,"r");
    if(pArchivo != NULL && pArrayList != NULL)
    {
        retorno = parser_BicicletasFromText(pArchivo,pArrayList);
    }
    fclose(pArchivo);

    return retorno;
}

int controller_saveAsText(char* path, LinkedList* pArrayList)
{
    int retorno = 0;
    eBici* b;
    int id;
    int tiempo;
    int dosis1;
    int dosis2;
    int sinVacunar;

    char auxId[101];
    char auxNombre[101];
    char auxTipo[101];
    char auxTiempo[101];

    FILE* pFile=fopen(path,"w");

    if(pFile!=NULL && pArrayList !=NULL)
    {
        fprintf(pFile,"id,nombre,tipo,tiempo\n");
        for(int i= 0; i < ll_len(pArrayList); i++)
        {
            b = ll_get(pArrayList,i);

            bicicleta_getId(b,&id);
            bicicleta_getNombre(b,&auxNombre);
            bicicleta_getTipo(b,&auxTipo);
            bicicleta_getTiempo(b,&tiempo);

            sprintf(auxId, "%d", id);
            sprintf(auxTiempo,"%d",tiempo);

            fprintf(pFile,"%s,%s,%s,%s\n",auxId,auxNombre,auxTipo,auxTiempo);
            printf("%s,%s,%s,%s\n",auxId,auxNombre,auxTipo,auxTiempo);
        }
        fclose(pFile);
        retorno = 1;
    }

    return retorno;
}
