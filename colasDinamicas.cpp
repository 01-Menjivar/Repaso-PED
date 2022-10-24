#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *front = NULL;
Nodo *final = NULL;

void push(int);
void pop(int &);

int main(){

    int cantidad,dato;

cout<<"Digite el numero de elementos: "<<endl;
cin>>cantidad;

for(int i = 0; i<cantidad; i++){
    cout<<"Digite el elemento: ";
    cin>>dato;
    push(dato);
}

cout<<"Mostrando los elementos: "<<endl;
while (front!=NULL)
{
    pop(dato);
    cout<<"El numero es: "<<dato<<endl;

}

    return 0;
}

void push(int n){
Nodo *new_nodo = new Nodo();
new_nodo->dato = n;
new_nodo->siguiente = NULL;
if(front==NULL){
    front = new_nodo;
}else{
    final->siguiente = new_nodo;
}
final = new_nodo;
}

void pop(int &n){
    n=front->dato;
    Nodo *aux = front;
    if(front==final){
        front = NULL;
        final = NULL;
    }else{
        front = front->siguiente;
    }
    delete aux;
}
