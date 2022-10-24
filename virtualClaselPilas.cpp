//Operaciones con pila
/*Push, tope y fila*/

/*Pilas fijas con arreglos*/
/*Pilas dinamicas con la reserva de memoria*/

//Ejercicio de clase con arreglo

#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    int cima;
    int elemento[5]; //Definimos un arreglo con su size
}pila;

//Crear pila
void crearPila(Nodo *p);
//Comprobar si la pila esta vacia
int pilaVacia(Nodo *p); 
//Notese que no puede ser void 
//Porque queremos que retorne true o false

//Pila llena
int pilaLlena(Nodo *p);
//Tambien podemos usar la funcion define -> 
//#define tamano 5 //Para definir valores en una constante, util para valores como pi
//Podemos sustituir por el 5 en este codigo ej: int elementos[tamano];

//Funcion insertar
void push(Nodo *p, int n);

//Funcion de eliminar
void pop(Nodo *p); //Ya no necesitamos las variable del elemento porque no decidimos que elemento eliminar
//Siempre se borrara de primero el ultimo en ser ingresado

int main(){

crearPila(&pila); //Importante
push(&pila, 8); //Al mandar a llamar a la funcion push, envio la variable de tipo struct pila por rferencia y mando mi dato
push(&pila, 9);
push(&pila, 2);
pop(&pila);

    return 0;
}

void crearPila(Nodo *p){
    p->cima=-1; //Inicializo vacia la pila
}
int pilaVacia(Nodo *p){
    if(p->cima ==  -1){ //Comprobamos si la pila es igual a vacia "Un estilo NULL"
        return true;
    }else{
        return false;
    }
}
int pilaLlena(Nodo *p){
    if(p->cima == 4)
    {
          return true;
    }else{
        return false;
    }
}

void push(Nodo *p, int n){
    if(!pilaLlena(p)){ //Verificamos si la pila no esta llena
        p->cima++; //Como la pila no esta llena podemos aumentar en 1
        p->elemento[p->cima]=n; //Similar a la dinamica relleno el dato pero coloco la posicion 
        //En este caso en la cima de la pila, y lo igualo a mi dato;
        cout<<"Se ha ingresado el elemento: "<<p->elemento[p->cima]<<endl;
    }
}

void pop(Nodo *p){
    if(!pilaVacia(p))
    {//Comprobamos si esta vacia antes de intentar eliminar
    int aux = p->cima; //Creamos una variable temporal y le pasamos el valor del ultimo elemento
    p->cima--; //Decrementamos en uno los elementos de la fila para borrar
    cout<<"Elemento borrado: "<<aux<<endl; //Podemos llamar a aux que nos guarda el dato de manera temporal
    }else{
        cout<<"Pila esta vacia"<<endl;
    }
}