#include <string.h>
#include "funciones.h"


/** \brief Verifica si el numero recibido es numerico
 * \param str cadena a ser analizada
 * \return 1 si es numerico, 0 si no lo es
 */
int validarSoloNumeros (char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
       {
           return 0;
       }
       i++;
   }
   return 1;
}

/** \brief Verifica si el numero recibido es solo letras
 * \param str cadena a ser analizada
 * \return 1 si es Solo letras, 0 si no lo es
 */
int validarSoloLetras (char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
       {
            return 0;
       }
       i++;
   }
   return 1;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void pedirString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int pedirStringLetras(char mensaje[],char input[])
{
    char aux[256];
    pedirString(mensaje,aux);
    if(validarSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int pedirStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    pedirString(mensaje,aux);
    if(validarSoloNumeros(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Inicializa una estructura de Personas con el valor recibido
 * \param Persona es la estructura a ser inicializada
 * \param cantidadDeElementos Indica la cantidad de estructuras
 * \param valor es el valor que se reemplazará
 * \return void
 *
 */
void inicializarEstructura(Persona misPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        misPersonas[i].estado = valor; //Inicializa todos los valores de estado a -1 por lo que no hay nada cargado
    }
}

/**
 * \brief Inicializa una estructura de Contadores con el valor recibido
 * \param Contadores es la estructura a ser inicializada
 * \param cantidadDeElementos Indica la cantidad de estructuras
 * \param valor es el valor que se reemplazará
 * \return void
 */
void inicializarEstructuraContadores(Contadores grafico[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        grafico[i].contador = valor; //Inicializa todos los valores de estado a -1 por lo que no hay nada cargado
    }
}

/**
 * \brief Busca la primer ocurrencia de un valor en un array de Personas
 * \param misPersonas la estructura en la cual buscar
 * \param cantidadDeElementos Indica la cantidad de estructuras
 * \param valor es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */
int buscarEstadoLibre(Persona misPersonas[],int cantidadDeElementos,int valor)
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(misPersonas[i].estado == valor)
        {
            return i;
        }
    }
    return -1;
}

/** \brief Busca el dni ingresar por el usuario en las estructuras
 *
 * \param misPersonas la estructura en la cual buscar
 * \param cantidadDeElementos Indica la cantidad de estructuras
 * \param valor es el valor que se busca
 * \return Si no hay ocurrencia (-1) y si la hay, la posición de la misma
 *
 */

int buscarDni(Persona misPersonas[],int cantidadDeElementos,int valor) //busca el dni en la estructura
{
    int i;
    for(i=0;i < cantidadDeElementos; i++)
    {
        if(misPersonas[i].dni == valor)
        {
            return i;
        }
    }
    return -1;
}
