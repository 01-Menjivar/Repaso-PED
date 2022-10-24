#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string nombre;
    int dato;
    Nodo *siguiente;
};

Nodo *pila = NULL;

void push(string,int);
void pop (string &, int &);

int main(){

    int cantidad,dato;
    string nombre;

    cout<<"Digite el numero de personas: "<<endl;
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Digite el nombre del estudiante: "<<endl;
        cin>>nombre;
        cout<<"Digite el carnet del estudiante"<<endl;
        cin>>dato;
        push(nombre,dato);
    }

    cout<<"\nMostrando los resultados: "<<endl;
    while (pila!=NULL)
    {
        pop(nombre,dato);
        cout<<"\nPersona: "<<nombre<<endl;
        cout<<"\nCarnet: "<<dato<<endl;
    }
    return 0;
}

void push(string c, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre=c;
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente=pila;
    pila = nuevo_nodo;
}

void pop(string &c, int &n){
    Nodo *aux = pila;
    c = aux->nombre;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}