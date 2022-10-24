#include<iostream>
using namespace std;

struct Nodo{
    int dato;
    Nodo *siguiente;
};

Nodo *lista = NULL;
void push(int);
void pop();

int dato,cantidad;


int main(){

    cout<<"Digite la cantidad de elementos"<<endl;
    cin>>cantidad;
    for(int i = 0; i<cantidad; i++){
        cout<<"Digite el dato: ";
        cin>>dato;
        push(dato);
    }

    pop();

    return 0;
}

void push(int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato =n;
    //Creamos los aux que nos serviran luego
    Nodo *aux1 = lista; // Igualamos el aux1 a lista, en este momento NULL
    Nodo *aux2;

    //Vamos a tener 3 casos
    //1. Insertar al inicio
    //2. Insertar por medio
    //3. Insertar al final -> estos ultimos dos formaran parte de un solo caso

    while((aux1!=NULL)&&(aux1->dato<n)){ //Mientras la lista no este vacia y ademas
                                    //queremos ingresar un dato mayor al del frente, entonces no ira al inicio, se inserta a la derecha
                                 //Entra al criterio de ordenamiento y movemos nodos
        aux2 = aux1; //aux2 apunta a donde aux1
        aux1=aux1->siguiente; //aux1 se recorre al siguiente, para hacer espacio  
    }

    if(lista==aux1){//Si entra aca es porque no cumplio el while, ya sea porque la lista esta vacia o es un valor menor, que debe ir al inicio.
        lista = nuevo_nodo; //Directamente le igualamos a lista nuestro nuevo nodo
    }else{ //Si entra aqui es porque entro al while, es decir requiere criterio de ordenamiento
        aux2->siguiente = nuevo_nodo; //Como previamente aux2 tomo la pos de aux1, aux2 se encarga de guardarlo en su siguiente
    }

    nuevo_nodo->siguiente = aux1; //El aux1 se recorre porque siempre debe referenciar el final de la lista
                                  //SIEMPRE, por eso esta fuera del if y while, se cumple en ambos casos

}

void pop(){
    Nodo *actual = new Nodo(); //Creo un nuevo nodo para almacenar
    actual = lista;   //Queremos que el nodo actual apunte al inicio de la lista para comenzar el recorrido
    while (actual!=NULL) //Para ir recorriendo actual
    {
        cout<<actual->dato<<endl; //Imprimimos el dato que encontramos
        actual = actual->siguiente; //Pasamos al siguiente 
        //y asi sucesivamente
    }
    
}