#include<iostream>
using namespace std;


struct Nodo{
int dato;
Nodo *izquierdo;
Nodo *derecho;
Nodo *padre;
};

struct Nodo*Crear(int n, struct Nodo *padre){
    //Reservar la memoria
    struct Nodo *nuevo_nodo = new Nodo();
    //Asignar ek valor que el usuario ingresa
    nuevo_nodo->dato = n;
    
    

}