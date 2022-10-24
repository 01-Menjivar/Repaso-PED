//Clasificacion de listas
//1.listas simplemente enlazadas
//2.Listas doblemente enlazadas
//3.Lista circular simplemente enlazada
//4.Lista circular doblemente enlazada

#include<iostream>
using namespace std;

struct Nodo{
    string nombre;
    int edad;
    int id;
    Nodo *siguiente;
};

//Insertar en una lista.
Nodo *lista = NULL;
int cantidad,edad,id;
string nombre;

void push(string, int, int);
void pop();
void menu();
void eliminar(string);
int main(){

    menu();

    return 0;
}
void push(string n, int e, int i){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->nombre = n;
    nuevo_nodo->edad = e;
    nuevo_nodo->id = i;
    Nodo *aux1 = lista;
    Nodo *aux2;
    //2 casos para insertar
    //1. Insertar 
    while (aux1!=NULL)
    {
        aux2 = aux1;
        aux1=aux1->siguiente;
    }
    //2. Insertar al inicio
if(lista == aux1){
    lista = nuevo_nodo;
}else{ //Ingreso al while porque el elemento a ingresar es mayor al elemento que ya tenemos
aux2->siguiente = nuevo_nodo;
}
nuevo_nodo->siguiente = aux1;

cout<<"\tElemento "<<n<<" insertado a lista correctamente\n"<<endl;

}
 
void pop(){
    Nodo *actual = new Nodo();
    actual = lista;
    while(actual!=NULL){
        cout<<"\tNombre: "<<actual->nombre<<endl;
        cout<<"Edad: "<<actual->edad<<endl;
        cout<<"ID: "<<actual->id<<endl;
        cout<<"\n";
        actual = actual->siguiente;
    }
}

void menu(){
    int opcion;
    do{
        cout<<"\nMENU\n"<<endl;
        cout<<"1.Insertar datos a la lista: "<<endl;
        cout<<"2. Mostrar todos los datos de la lista: "<<endl;
        cout<<"3. Eliminar un elemento de la lista"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Opcion: "<<endl;
        cin>>opcion;

        switch (opcion)
        {
        case 1:
        cout<<"Digite la cantidad de elementos: ";
    cin>>cantidad;

    for(int i = 0; i<cantidad; i++){
        cout<<"Digite su nombre: "<<endl;
        cin>>nombre;
        cout<<"Digite su edad: "<<endl;
        cin>>edad;
        cout<<"Digite su id: "<<endl;
        cin>>id;
        push(nombre,edad,id);
    }
        break;
        case 2:
        cout<<"\n***Mostrando datos***\n";
        pop();
        break;
        case 3:
            cout<<"Digite el nombre que desea eliminar: ";
            cin>>nombre;
            eliminar(nombre);
        break;
        case 4: 
        break;
        }

    }while(opcion!=4);


}
void eliminar(string n){
    if(lista!=NULL){
        Nodo *aux_borrar;
        Nodo *anterior = NULL;

        aux_borrar = lista;
        while ((aux_borrar!=NULL)&&(aux_borrar->nombre!= n))
        {
            anterior = aux_borrar;
            aux_borrar=aux_borrar->siguiente;
        }
        
        if(aux_borrar == NULL){
            cout<<"Ese elemento no existe";
        }else if(anterior == NULL){
            lista = lista->siguiente;
            delete aux_borrar;
        }
        else{
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
        }
    }
}