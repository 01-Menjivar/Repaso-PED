#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    double pago;
    Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *final = NULL;

void push(double);
void pop(double &);
void sumar(double &);
double pago;

int main(){

    int cantidad;

    cout<<"Digite el numero de pagos: ";
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Digite el pago: "<<endl;
        cin>>pago;
        push(pago);
    }

    sumar(pago);

    return 0;
}

void push(double p){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->pago = p;
    if(frente==NULL){
        frente = nuevo_nodo;
    }else{
        final->siguiente = nuevo_nodo;
    }
    final = nuevo_nodo;
}

void pop(double &p){
    p = frente->pago;
    Nodo *aux = frente;
    if(frente==final){
        frente = NULL;
        final = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;
}

void sumar(double &p){
    double suma = 0;
    while(frente!=NULL){
    pop(pago);
    suma = suma+pago;
    }
    cout<<"La suma de pago es: "<<suma<<endl;
}
