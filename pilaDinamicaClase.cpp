#include <iostream>
#include <stdlib.h>
using namespace std;

// Variable global
struct Nodo *pila = NULL;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void push(int);
void pop(int &);

// Adicionales
// Funcion de vacia
bool Vacia()
{
    // Genera un 0 o 1
    return pila == NULL;
    // Si se cumple la condicion genera un 1 y cuenta como "true" o sea que esta vacia
    // De lo contrario genera un o, un "false" o sea que no esta vacia
}

// Funcion para conocer el ultimo elemento
int Ultimo()
{
    if (pila == NULL)
    {
        cout << "No hay elementos";
    }
    else
    {
        return pila->dato;
    }
}

// Funcion para imprimir
void imprimir()
{
    Nodo *aux = pila;
    while (aux != NULL)
    {
        cout << "Elementos de la pila: " << aux->dato << endl;
        aux = aux->siguiente; // Para que vata recorriendo
    }
}

int main()
{

    push(8);
    push(6);
    push(7);
    cout << Ultimo();

    return 0;
}

void push(int n)
{ // Creamos la funcion que acepte solo el dato
    // Reservamos memoria;
    Nodo *nuevo_nodo = new Nodo();
    // Asignamos el valor al nuevo nodo
    nuevo_nodo->dato = n; // El nuevo nodo que creamos manda a llamar a dato para almacenar el n del usuario
    // Llamamos al siguiente e igualamos a pila
    nuevo_nodo->siguiente = pila; // El nuevo nodo tiene que apuntar al siguiente
    pila = nuevo_nodo;
}

void pop(int &n)
{
    if (pila != NULL)
    {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }
}