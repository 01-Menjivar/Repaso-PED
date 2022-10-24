#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    struct dato *siguiente; //Apunta al siguiente nodo
};

Nodo *lista = NULL;

// 0->1->2->NULL Lista simple
// NULL 0 <-> 1 <-> 2 <-> 3 Lista doblemente enlazada

//Declaracion de funciones
void Insertar(int);
int main(){

    return 0;
}

void Insertar(int n){
Nodo *nuevo_nodo = new Nodo();
Nodo *aux1 = lista; /*Creamos una variable aux para guardar el valor
que queremos ingresar a la lista;
*/
if(nuevo_nodo!=NULL){ //Si el nodo no esta vacio

}else{
    cout<<"No se pueden agregar mas nodos"<<endl;
}
}