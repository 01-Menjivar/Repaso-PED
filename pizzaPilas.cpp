#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string nombre;
    double precio;
    Nodo *siguiente;
};

Nodo *pila = NULL;

void push(string, double);
void pop(string &, double &);

int main(){

    int cantidad;
    double precio;
    string nombre;

    cout<<"Digite el numero de pizzas: "<<endl;
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Escriba el nombre de la pizza: "<<endl;
        cin>>nombre;
        cout<<"Digite el precio de la pizza: "<<endl;
        cin>>precio;
        push(nombre,precio);
    }

    cout<<"\nMostrando los elementos: \n"<<endl;
    while(pila!=NULL){
        pop(nombre,precio);
        cout<<"Nombre de la pizza: "<<nombre<<endl;
        cout<<"Precio: "<<precio<<endl;
        cout<<"\n";
    }

    return 0;
}

void push(string n, double p){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre = n;
    nuevo_nodo->precio = p;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;

}

void pop(string &n, double &p){
    Nodo *aux = pila;
    n = aux->nombre;
    p = aux->precio;
    pila = aux->siguiente;
    delete aux;
}