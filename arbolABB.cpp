#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;

struct Nodo{
    int dato;
    Nodo *der;
    Nodo *izq;
};

//Prototipos  
Nodo *crearNodo(int);
void Insertar(Nodo *&arbol, int );
void mostrarArbol(Nodo *arbol, int);
void menu();

Nodo *arbol = NULL;

int main(){
menu();
    return 0;
}

//Con esta funcion solo creamos el nodo

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();

    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}

void Insertar(Nodo *&arbol, int n){
    if(arbol==NULL){ //Si el arbolmesta vacio
    Nodo *nuevo_nodo = crearNodo(n);
    arbol = nuevo_nodo;
    }else{ //Si ya tiene nodos
        int valorRaiz = arbol->dato; //Necesitamos el valor de la raiz
                                     //Para saber si pertenece izquierda o derecha
        if(n<valorRaiz){ //Si el valor a ingresar es menor que el que ya tenemos
            Insertar(arbol->izq,n); //Si es menor insertamos a la izquierda
        }else{//Si el elemento es mayor a la raiz, insertamos al derecho
        Insertar(arbol->der,n);
        }                 
    }
}

//Funcion de MNU
void menu(){
    int dato,opcion;
    int cont = 0;
    do{
        cout<<"\MENU\n";
        cout<<"1.Insertar un nuevo nodo"<<endl;
        cout<<"2. Mostrar el arbol"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"opcion: "<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
        cout<<"Digite un numero: ";
        cin>>dato;
        Insertar(arbol,dato); //Insertamos un nuevo nodo
        cout<<"\n";
        system("pause");
        break;
        case 2: 
        cout<<"\nMostrando el arbol completo:\n\n";
            mostrarArbol(arbol,cont);
            cout<<"\n";
            system("pause");
        break;
        case 3: 
        break;
        }
        system("cls");

    }while(opcion!=3);

}

//Funcion para mostrar el arbol
void mostrarArbol(Nodo *arbol, int contador){
    if(arbol==NULL){
        return;
    }else{
        mostrarArbol(arbol->der,contador+1);
        for(int i = 0; i<contador; i++){
            cout<<" ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,contador+1);
    }
}