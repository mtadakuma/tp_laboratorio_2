#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define CANT 20


int main()
{
    char seguir='s';
    int opcion=0;

    Persona misPersonas[CANT]; //Estructuras de la cantidad definida
    Persona auxiliarPersona;  //Auxiliar para ordenamiento
    Contadores grafico[3]; //Creo estructuras de contador y las inicializo en 0

    //variables para guardar la informacion ingresada en forma de string y poder compararla
    char auxiliarNombreStr[50]; //String de entrada
    char auxiliarEdadStr[50]; //String de entrada
    char auxiliarDniStr[50]; //String de entrada
    int auxiliarEdad; //Auxiliar donde se pasa el string de entrada
    int auxiliarDni; //Auxiliar donde se pasa el string de entrada

    int indiceLibre; //Lugar libre
    int indiceBusquedaDni; //Lugar buscado por Dni
    int i,j, max=0; //variables de control

    int contMenores=0; //Contadores
    int contMedios=0; //Contadores
    int contMayores=0; //Contadores

    inicializarEstructura(misPersonas,CANT, -1); //Inicializa todos los valores a -1
    inicializarEstructuraContadores(grafico, 3, 0);

    while(seguir == 's')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                indiceLibre = buscarEstadoLibre(misPersonas,CANT, -1); //Devolvera un entero mayor a 0 si esta dentro de la estructura
                if(indiceLibre == -1) //Indice fuera del array
                {
                    printf("Maximo numero de ingresos permitidos\n");
                    break;
                }
                else
                {
                    if(pedirStringLetras("Ingrese el Nombre (sin espacios ni comas):", auxiliarNombreStr) == 0) //Guardo el nombre ingresado en el aux y lo valido
                    {
                        printf("El nombre debe estar compuesto solo por letras\n");
                        break;
                    }
                    else
                    {
                        for(i=0; auxiliarNombreStr[i]; i++)
                        {
                            auxiliarNombreStr[i] = tolower(auxiliarNombreStr[i]);
                        }
                        auxiliarNombreStr[0] = toupper(auxiliarNombreStr[0]);
                    }
                }

                //------------------------------------------------------------ Validado el nombre

                if(pedirStringNumeros("Ingrese edad:", auxiliarEdadStr)==0)
                {
                    printf("La edad debe estar compuesta solo por numeros\n");
                    break;
                }
                else
                {
                    auxiliarEdad = atoi(auxiliarEdadStr); //Convierto el String en Int con funcion atoi
                    if(auxiliarEdad <= 0 || auxiliarEdad >=100)
                    {
                        printf("La edad no puede ser negativa, ni 0, ni mayor a 100\n");
                        break;
                    }
                }

                //------------------------------------------------------------ Validada la edad y los contadores para el grafico

                if(pedirStringNumeros("Ingrese DNI:", auxiliarDniStr)==0)
                {
                    printf("El Dni debe estar compuesto solo por numeros sin comas ni puntos\n");
                    break;
                }
                else
                {
                    if(strlen(auxiliarDniStr) != 8)
                    {
                        printf("El Dni debe estar compuesto por 8 numeros sin puntos ni comas\n");
                        break;
                    }
                    else
                    {
                        auxiliarDni = atoi(auxiliarDniStr); //Convierto el String en Int con funcion atoi
                    }
                }
                //------------------------------------------------------------ Validado el dni

                if(auxiliarEdad <= 18)
                {
                    contMenores++;
                }
                else if (auxiliarEdad > 18 && auxiliarEdad<=35)
                {
                    contMedios++;
                }
                else
                {
                    contMayores++;
                }

                //Si todos los datos son correctos puedo sumar en los contadores las cargas correctas

                //Paso los valores a sus respectivas estructuras
                strcpy(misPersonas[indiceLibre].nombre, auxiliarNombreStr); //Copio el nombre en la estructura
                misPersonas[indiceLibre].edad = auxiliarEdad; //Copio Edad
                misPersonas[indiceLibre].dni = auxiliarDni; //Copio Dni
                misPersonas[indiceLibre].estado = 0; //Cambio el estado para decir que ya esta cargado

                printf("Carga exitosa\n");
                break;
            case 2:
                if(pedirStringNumeros("Ingrese DNI:", auxiliarDniStr)==0)
                {
                    printf("El Dni debe estar compuesto solo por numeros sin comas ni puntos\n");
                    break;
                }
                else
                {
                    if(strlen(auxiliarDniStr) != 8)
                    {
                        printf("El Dni debe estar compuesto por 8 numeros sin puntos ni comas\n");
                        break;
                    }
                    else
                    {
                        auxiliarDni = atoi(auxiliarDniStr); //Convierto el String en Int con funcion atoi
                    }
                }

                indiceBusquedaDni = buscarDni(misPersonas, CANT, auxiliarDni); //Busca el dni ingresado en las estructuras
                if(indiceBusquedaDni == -1) //Si no lo encuentra
                {
                    printf("No se encuentra Dni. Por favor ingrese Dni valido\n");
                    break;
                }

                misPersonas[indiceBusquedaDni].estado = -1; //Si lo encuentra lo da de baja logico
                misPersonas[indiceBusquedaDni].edad = auxiliarEdad; //Verifica la edad para eliminarla del grafico

                if(auxiliarEdad <= 18) //Resta en los contadores para que el grafico no muestre la persona dada de baja
                {
                    contMenores--;
                }
                else if (auxiliarEdad > 18 && auxiliarEdad<=35)
                {
                    contMedios--;
                }
                else
                {
                    contMayores--;
                }

                printf("Persona borrada\n");
                break;
            case 3:
                for(i=0; i<CANT-1; i++)
                {
                    if(misPersonas[i].estado == -1)
                    {
                        continue;
                    }
                    for(j=i+1; j<CANT;j++)
                    {
                        if(misPersonas[j].estado == -1)
                        {
                            continue;
                        }
                        if(strcmp(misPersonas[i].nombre, misPersonas[j].nombre)>0)
                        {
                            auxiliarPersona = misPersonas[j];
                            misPersonas[j] = misPersonas[i];
                            misPersonas[i] = auxiliarPersona;
                        }
                    }
                }
                //Ordeno todas las entradas y ahora los muestro

                printf("\nNombre\tEdad\tDni\n"); //Lo separo en dos solo para verificar
                for(i=0; i<CANT; i++)
                {
                    if(misPersonas[i].estado != -1)
                    {
                        printf("%s\t%d\t%d\n", misPersonas[i].nombre, misPersonas[i].edad, misPersonas[i].dni);
                    }
                }
                break;
            case 4:
                grafico[0].contador = contMenores; //Copio el valor de los contadores en la estructura
                grafico[1].contador = contMedios; //Copio el valor de los contadores en la estructura
                grafico[2].contador = contMayores; //Copio el valor de los contadores en la estructura

                printf("\n");
                for (i = 0; i < 3; i++) //Recorre la estructura para encontrar la maxima fila
                {
                    if (grafico[i].contador > max)
                    {
                        max = grafico[i].contador;
                    }
                }

                for (i = max; i > 0; i--) //Va contando desde la fila mas alta a la mas baja
                {
                    for (j = 0; j < 3; j++) //Cuenta desde la primer columna hasta la ultima
                    {
                        if (grafico[j].contador >= i) //Si se intersectan las busquedas imprime un * sino un espacio
                        {
                            printf("  *  ");
                        }
                        else
                        {
                            printf("     ");
                        }
                    }
                    printf("\n");
                }
                printf("<18 ");
                printf(" 19-35");
                printf(" >35\n");
                break;
            case 5:
                printf("Creado por Miguel Angel Tadakuma - 2017\n");
                printf("\nGracias por utilizar este programa.\n");
                seguir = 'n';
                break;
            default:
                printf("Opcion incorrecta, ingrese opcion entre 1 y 5.");
                break;
        }
    system("pause");
    system("cls");
    }
    return 0;
}
