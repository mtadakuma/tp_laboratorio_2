#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int estado;
    int dni;

}Persona;

typedef struct {
   int contador;
}Contadores;

int validarSoloNumeros (char str[]);
int validarSoloLetras (char str[]);
void pedirString(char mensaje[],char input[]);
int pedirStringLetras(char mensaje[],char input[]);
int pedirStringNumeros(char mensaje[],char input[]);
void inicializarEstructura(Persona misPersonas[],int cantidadDeElementos,int valor);
void inicializarEstructuraContadores(Contadores grafico[],int cantidadDeElementos,int valor);
int buscarEstadoLibre(Persona misPersonas[],int cantidadDeElementos,int valor);
int buscarDni(Persona misPersonas[],int cantidadDeElementos,int valor);

#endif // FUNCIONES_H_INCLUDED


