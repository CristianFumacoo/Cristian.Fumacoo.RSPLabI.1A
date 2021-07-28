#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "LinkedList.h"
#include "bicicletas.h"

int parser_BicicletasFromText(FILE* pFile, LinkedList* pArrayList)
{
    char auxId[51];
    char auxBici[51];
    char auxTipo[51];
    char auxTiempo[51];
    int retorno = 0;
    int flagOnce = 1;
    eBici* pBici;

    if(pFile!=NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce=0;
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxBici,auxTipo,auxTiempo);
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxBici,auxTipo,auxTiempo);

            pBici = bicicleta_newParametros(auxId,auxBici,auxTipo,auxTiempo);

            if(pBici != NULL)
            {
                retorno = 1;
                ll_add(pArrayList,pBici);
            }
        }
    }

    return retorno;
}

