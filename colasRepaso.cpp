#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string nombre;
    double precio;
    Nodo *siguiente;
};

Nodo *frente = NULL;
Nodo *final = NULL;

string nombre;
double precio;
int cantidad;


void push(string,double);
void pop(string&, double&);
int main(){

cout<<"Digite la cantidad de elementos"<<endl;
cin>>cantidad;

for(int i = 0; i<cantidad; i++){
    cout<<"Digite el nombre de la hamburguesa"<<endl;
    cin>>nombre;
    cout<<"Digite el precio de la hamburguesa"<<endl;
    cin>>precio;
    push(nombre,precio);
}

cout<<"\n******Mostrando los datos*******\n";
while(frente!=NULL){
    pop(nombre,precio);
    cout<<"Nombre de la hamburguesa: "<<nombre<<endl;
    cout<<"Precio de la hamburguesa: "<<precio<<endl;
}
    return 0;
}

void push(string n, double p){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre=n;
    nuevo_nodo->precio=p;
    if(frente==NULL){
        frente = nuevo_nodo;
    }else{
        final->siguiente = nuevo_nodo;
    }
    final = nuevo_nodo;
}

void pop(string &n, double &p){
    n=frente->nombre;
    p=frente->precio;
    Nodo *aux = frente;
    if(frente==final){
        frente = NULL;
        final = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;

}
