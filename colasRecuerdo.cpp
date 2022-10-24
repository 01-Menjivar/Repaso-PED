#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *final = NULL;
 int dato,cantidad;

void push(int );
void pop(int &);
int main(){

    cout<<"Digite la cantidad de elementos: ";
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Digite el dato: "<<endl;
        cin>>dato;
        push(dato);
    }

    while (frente!=NULL)
    {
        pop(dato);
        cout<<dato<<endl;
    }
    


    return 0;
}
void push(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    nuevo_nodo->siguiente = NULL;
    if(frente==NULL){
        frente = nuevo_nodo;
    }else{
        final->siguiente = nuevo_nodo;
    }
    final = nuevo_nodo;
}

 void pop (int &n){
    n = frente->dato;
    Nodo *aux = frente;
    if(frente==final){
        frente = NULL;
        final = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;
}