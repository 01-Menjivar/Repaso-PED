#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string nombre;
    float edad;
    Nodo *siguiente;
};

Nodo *lista = NULL;
string nombre;
float edad;
int cantidad;

void push(string,float);
void pop();
void promedio();
void menu();

int main(){

   cout<<"Digite la cantidad de elementos"<<endl;
   cin>>cantidad;

   for(int i = 0; i<cantidad; i++){
    cout<<"Digite el nombre de la persona: "<<endl;
    cin>>nombre;
    cout<<"Digite la edad: "<<endl;
    cin>>edad;
    push(nombre,edad);
   }

   cout<<"\n*****Mostrando resultados*******\n";
   pop();
    cout<<"\nEl promedio de edades es: "<<endl;
    promedio();
    
    return 0;
}


void push(string n, float e){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre =n;
    nuevo_nodo->edad=e;
    nuevo_nodo->siguiente = lista;

    lista = nuevo_nodo;
}


void pop(){
    Nodo *actual = new Nodo();
    actual = lista;
    while (actual!=NULL)
    {
        cout<<actual->nombre<<endl;
        cout<<actual->edad<<endl;
        actual = actual->siguiente;
    }

}

void promedio(){
    Nodo *actual = lista;
    float suma = 0; 
    float promedio;
    while (actual!=NULL)
    {
    suma = suma+actual->edad;
    actual = actual->siguiente;
    }
    promedio = suma/cantidad;

    cout<<promedio<<endl;

}