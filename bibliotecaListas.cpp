#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    string titulo;
    string estante;
    string isbn;
    string genero;
    string autor;
    Nodo *siguiente;
};

Nodo *lista = NULL;

void push(string, string, string, string, string);
void pop();

int main()
{
    string titulo;
    string estante;
    string isbn;
    string genero;
    string autor;

    int cantidad;
    cout<<"Digite la cantidad de elementos"<<endl;
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Digite el titulo"<<endl;
        cin>>titulo;
        cout<<"Digite el numero de estante"<<endl;
        cin>>estante;
        cout<<"Digite el numero de ISBN"<<endl;
        cin>>isbn;
        cout<<"Digite el genero del libro"<<endl;
        cin>>genero;
        cout<<"Digite el auto del libro"<<endl;
        cin>>autor;
        push(titulo,estante,isbn,genero,autor);
    }

    pop();

    return 0;
}
void push(string t, string e, string n, string g, string a)
{
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->titulo = t;
    nuevo_nodo->estante = e;
    nuevo_nodo->isbn = n;
    nuevo_nodo->genero = g;
    nuevo_nodo->autor = a;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (aux1 == NULL)
    {
        lista = nuevo_nodo;
    }
    else
    {
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void pop(){
    Nodo *actual = new Nodo();
    actual = lista;
    while (actual!=NULL)
    {
        cout<<actual->titulo<<endl;
        cout<<actual->estante<<endl;
        cout<<actual->isbn<<endl;
        cout<<actual->genero<<endl;
        cout<<actual->autor<<endl;
        actual = actual->siguiente;
    }
    

}