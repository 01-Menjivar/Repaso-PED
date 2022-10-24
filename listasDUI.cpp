#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string nombre;
    int DUI;
    Nodo *siguiente;
};

Nodo *lista = NULL;
string nombre; 
int DUI, cantidad;

void push(string,int);
void pop();

int main(){

    cout<<"Digite la cantidad de personas"<<endl;
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Digite el nombre: ";
        cin>>nombre;
        cout<<"Digite el DUI de la persona: ";
        cin>>DUI;
        push(nombre,DUI);

    }

    pop();
    


    return 0;
}

void push(string n, int id){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre = n;
    nuevo_nodo->DUI = id;
    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1!=NULL)&&(aux1->DUI<=id)){
        aux2 = aux1;
        aux1=aux1->siguiente;
    }

    if(lista==aux1){
        lista = nuevo_nodo;
    }else{
        aux2->siguiente = nuevo_nodo;
    }
    nuevo_nodo->siguiente = aux1;
}

void pop(){
    Nodo *actual = new Nodo();
    actual = lista;
    while (actual!=NULL)
    {
       cout<<"Nombre: "<<actual->nombre<<endl;
    cout<<"DUI: "<<actual->DUI<<endl;
    actual = actual->siguiente;
    }
}

