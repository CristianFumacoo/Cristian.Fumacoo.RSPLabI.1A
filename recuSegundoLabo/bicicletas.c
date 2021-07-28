#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bicicletas.h"
#include "LinkedList.h"

int bicicleta_setId(eBici* this,int id)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->id_bike = id;
            retorno = 1;
        }
    return retorno;
}

int bicicleta_setNombre(eBici* this,char* nombre)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(this->nombre,nombre);
            retorno = 1;
        }
    return retorno;
}

int bicicleta_setTipo(eBici* this,char* tipo)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(this->tipo,tipo);
            retorno = 1;
        }
    return retorno;
}

int bicicleta_setTiempo(eBici* this,int tiempo)
{
    int retorno = 0;

        if(this != NULL)
        {
            this->tiempo = tiempo;
            retorno = 1;
        }
    return retorno;
}

int bicicleta_getId(eBici* this,int* id)
{
    int retorno = 0;

        if(this != NULL)
        {
            *id = this->id_bike;
            retorno = 1;
        }
    return retorno;
}

int bicicleta_getNombre(eBici* this,char* nombre)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(nombre,this->nombre);
            retorno = 1;
        }
    return retorno;
}

int bicicleta_getTipo(eBici* this,char* tipo)
{
    int retorno = 0;

        if(this != NULL)
        {
            strcpy(tipo,this->tipo);
            retorno = 1;
        }
    return retorno;
}

int bicicleta_getTiempo(eBici* this,int* tiempo)
{
    int retorno = 0;

        if(this != NULL)
        {
            *tiempo = this->tiempo;
            retorno = 1;
        }
    return retorno;
}

void numRandom(void* num)
{
    int max = 120;
    int min = 50;
    eBici* b;
    b = (eBici*) num;

    b->tiempo = rand() % (max - min + 1) + min;
}

int existeTipo(LinkedList* bici,char* auxTipo)
{
    int retorno = 0;
    int tam = ll_len(bici);
    eBici* aux;
    aux = (eBici*) bici;
    for(int i = 0;i < tam;i++)
    {
        aux = ll_get(bici,i);

        if(strcmp(aux->tipo,auxTipo) == 0)
        {
            retorno = 1;
        }
    }
    return retorno;
}

int buscarTipo(void* this, char* auxTipo)
{
    int retorno = 0;
    eBici* b;
    b = (eBici*) this;

    if(strcmp(b->tipo,auxTipo) == 0)
    {
        retorno = 1;
    }

    return retorno;
}

int ordenar(void* this ,void* this2)
{
    int retorno = 0;
    eBici* b;
    eBici* b2;
    b = (eBici*) this;
    b2 = (eBici*) this2;

    if(strcmp(b->tipo,b2->tipo) > 0)
    {
        //printf("Fue mayor\n");
        retorno = 1;
    }
    else if(strcmp(b->tipo,b2->tipo) < 0)
    {
        //printf("Fue menor\n");
        retorno = -1;
    }
    else if(strcmp(b->tipo,b2->tipo) == 0)
    {
        if(b->tiempo > b2->tiempo)
        {
            retorno = 1;
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}








































eBici* bicicleta_new()
{
    eBici* this;

    this = malloc(sizeof(eBici));

    return this;
}


eBici* bicicleta_newParametros(char* idStr,char* nombreStr,char* tipoStr,char* tiempo)
{
    eBici* this;
    this = bicicleta_new();

    if(bicicleta_setId(this,atoi(idStr))&&
       bicicleta_setNombre(this,nombreStr)&&
       bicicleta_setTipo(this,tipoStr)&&
       bicicleta_setTiempo(this,atoi(tiempo)))
    {
         return this;
    }

    return NULL;
}

void mostrarBicicleta(eBici* b)
{
    if(b != NULL)
    {
        printf("\n%d %10s %10s %10d\n",b->id_bike,b->nombre,b->tipo,b->tiempo);
    }
}
void mostrarBicicletas(LinkedList* list)
{
    int tam;
    eBici* aux = NULL;
    if(list != NULL)
    {
        tam = (eBici*) ll_len(list);
        printf("%s%10s%12s%11s\n","ID","NOMBRE","TIPO","TIEMPO");
        for(int i = 0;i<tam;i++)
        {
            aux = ll_get(list,i);
            if(aux != NULL)
            {
                mostrarBicicleta(aux);
            }
        }
        printf("............................\n\n");
    }
}














