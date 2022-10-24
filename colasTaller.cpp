#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string modelo;
    int placa;
    string color;
    Nodo *siguiente;
};

int opc;
Nodo *frente = NULL;
Nodo *final = NULL;

void push(string, int, string);
void pop(string &, int &, string &);
void menu();

int main(){

    menu();

    return 0;
}

void menu(){
    string modelo,color;
    int placa;
    do{
    cout<<"\nMENU\n";
    cout<<"1.Agregar nuevo auto"<<endl;
    cout<<"2. Mostrar los autos"<<endl;
    cout<<"3. Eliminar el primer auto"<<endl;
    cout<<"4. Salir"<<endl;
    cout<<"Opcion: ";
    cin>>opc;
    switch (opc)
    {
    case 1:
    cout<<"Digite el modelo del auto"<<endl;
    cin>>modelo;
    cout<<"Digite la placa del auto"<<endl;
    cin>>placa;
    cout<<"Digite el color del auto"<<endl;
    cin>>color;
    push(modelo,placa,color);
    break;
    case 2:
    cout<<"\nMostrando datos"<<endl;
    while (frente!=NULL)
    {
       pop(modelo,placa,color);
       cout<<"Modelo: "<<modelo<<endl;
       cout<<"Placa: "<<placa<<endl;
       cout<<"Color: "<<color<<endl;
       cout<<"\n";
    }
    break;
    case 3: 
    pop(modelo,placa,color);
    break;
    case 4:
    break;
    }
    }while(opc!=4);
}

void push(string m, int p, string c){
Nodo *nuevo_nodo = new Nodo();
nuevo_nodo->modelo = m;
nuevo_nodo->placa = p;
nuevo_nodo->color = c;
if(frente==NULL){
    frente = nuevo_nodo;
}else{
    final->siguiente = nuevo_nodo;
}
final = nuevo_nodo;
}

void pop(string &m, int &p, string &c){
    m = frente->modelo;
    p = frente->placa;
    c = frente->color;
    Nodo *aux = frente;
    if(frente==final){
        frente = NULL;
        final = NULL;
    }else{
        frente = frente->siguiente;
    }
    delete aux;
}

