#include "LinkedList.h"

typedef struct
{
    int id_bike;
    char nombre[51];
    char tipo[51];
    int tiempo;
}eBici;

eBici* bicicleta_new();
eBici* bicicleta_newParametros(char*,char*,char*,char*);

void mostrarBicicleta(eBici*);
void mostrarBicicletas(LinkedList*);

/** \brief Genera un numero random entre 50 y 120
 *
 * \param void* Recibe el elemento
 * \return void
 *
 */
void numRandom(void*);

/** \brief Verifica que el tipo ingresado sea valido
 *
 * \param LinkedList* Recibe la lista
 * \param char* Recibe el nombre del tipo a buscar
 * \return int
 *
 */
int existeTipo(LinkedList*,char*);

/** \brief Compara el tipo ingresado con los de la lista
 *
 * \param void* recibe el elemento
 * \param char* recibe el tipo
 * \return int Devuelve 1 si es igual y 0 si no
 *
 */
int buscarTipo(void*,char*);

/** \brief Compara los elementos para ser ordenados
 *
 * \param void* Elemento numero 1
 * \param void* Elemento numero 2
 * \return int Devuelve 1 si es mayor, -1 si es menor y 0 si es igual
 *
 */
int ordenar(void*,void*);

int bicicleta_setId(eBici*,int);
int bicicleta_getId(eBici*,int*);

int bicicleta_setNombre(eBici*,char*);
int bicicleta_getNombre(eBici*,char*);

int bicicleta_setTipo(eBici*,char*);
int bicicleta_getTipo(eBici*,char*);

int bicicleta_setTiempo(eBici*,int);
int bicicleta_getTiempo(eBici*,int*);



