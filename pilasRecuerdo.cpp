#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *pila = NULL;
int dato, cantidad;
void push(int);
void pop(int &);

int main(){

cout<<"Digite la cantidad de elementos"<<endl;
cin>>cantidad;

for (int i = 0; i<cantidad; i++){
    cout<<"Digite el dato: ";
    cin>>dato;
    push(dato);
}

while(pila!=NULL){
    pop(dato);
    cout<<dato<<endl;
}

    return 0;
}

void push(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato=n;
    nuevo_nodo->siguiente = pila;
    pila = nuevo_nodo;
}

void pop(int &n){
    Nodo *aux = pila;
    n = aux->dato;
    pila = aux->siguiente;
    delete aux;
}