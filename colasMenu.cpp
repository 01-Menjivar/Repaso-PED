#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *final = NULL;

int numero;

void push(int);
void pop(int &n);
void menu();


int main(){

menu();

    return 0;
}

void menu(){
    int opc;
    do{
        cout<<"\nMENU\n"<<endl;
        cout<<"1. Insertar elementos"<<endl;
        cout<<"2. Mostrar elementos"<<endl;
        cout<<"3.Mostrar elementos mayores a 15"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Opcion ";
        cin>>opc;
        switch (opc)
        {
        case 1:
        cout<<"Digite el numero"<<endl;
        cin>>numero;
        push(numero);
        break;
        case 2:
        while(frente!=NULL){
        pop(numero);
        cout<<"El digito es: "<<numero<<endl;
        }
        break;
        case 3:
        cout<<"\nLos digitos mayores a 15 son: "<<endl;
        while(frente!=NULL){
        pop(numero);
        if(numero>15){
            cout<<numero<<endl;
        }
        }
        break;
        case 4:
        break;
        }
    }while(opc!=4);
}

void push(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;
    if(frente==NULL){
        frente = nuevo_nodo;
    }else{
        final->siguiente = nuevo_nodo;
    }
    final = nuevo_nodo;

}

void pop(int &n){
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