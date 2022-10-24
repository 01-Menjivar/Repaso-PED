#include <iostream>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    int frenteCola;
    int finalCola;
    int elemento[5];
} nodo;

void Crear(Nodo *);
bool Vacia(Nodo *);
bool Llena(Nodo *);
void Insertar(Nodo *, int);
void Eliminar(Nodo *);
int Dimension(Nodo *);

int main()
{

    Crear(&nodo);
   

    cout<<"Posicion "<<nodo.frenteCola<<" Inicio cola "<<nodo.elemento[nodo.frenteCola]<<endl;
    cout<<"Posicion "<<nodo.finalCola<<" Fin cola "<<nodo.elemento[nodo.finalCola]<<endl;
    Eliminar(&nodo);
    cout<<"Posicion "<<nodo.frenteCola<<" Inicio cola "<<nodo.elemento[nodo.frenteCola]<<endl;
    cout<<"Posicion "<<nodo.finalCola<<" Fin cola "<<nodo.elemento[nodo.finalCola]<<endl;
    return 0;
}

// Crear cola vacia
void Crear(Nodo *p)
{
    p->frenteCola = -1; // Igualamos a -1 para indicar que esta vacia, esta antes de la posicion 0
    p->finalCola = -1; // Igualamos a -1 para indicar que esta vacia
}

// Funcion para determinar si la cola esta vacia
bool Vacia(Nodo *p)
{
    if (p->finalCola == -1)
    { // Si el final esta vacio returna true
        return true;
    }
    else
    {
        return false;
    }
}

// Funcion dimension
int Dimension(Nodo *p)
{ // Sirve para contar los elementos en la cola
    // Evaluo si no hay elementos
    if (Vacia(p))
    {
        return 0; // Si esta vacia que retorne 0;
    }
    else //Si no esta vacia
    {
        if (p->frenteCola <= p->finalCola) //Evaluanos si la posicion del frente es menor o igual que la del final
        {
            return p->finalCola - p->frenteCola + 1; //Si es asi retorna la posicion del final - la posicion del frente aumentado en 1
                                                    //ej: 1 4 5 6  <-numeros       3-0 + 1 = 4 elementos
                                                    //    0 1 2 3 <- posiciones
        }
        else
        {
            return 5 - p->frenteCola + p->finalCola + 1; //Si la posicion del frente es mayor
        }
    }
}

// Llena
bool Llena(Nodo *p)
{
    if (Dimension(p) == 5)
    { // Si el tamano es igual al limite
        return true;
    }
    else
    {
        return false;
    }
}

// Insertar o push
void Insertar(Nodo *p, int n)
{
    if (!Llena(p)) //Tenemos que verificar si la cola esta llena
    //Si no esta llena se hace lo siguiente
    {

        //Si cola esta vacia
        if (Vacia(p))
        {
            p->frenteCola = 0; // Como esta vacia agregamos el elemento a la primera posicion
        }
        //Si tiene algunos elementos
        if (p->finalCola == 5 - 1) 
        { // Si el final de la cola esta llena
            p->finalCola = 0; //por circularidad mi final que estaba en la ultima, pasa a la primera
        }
        else
        {                   // Si aun hay espacio al final de la cola 
            p->finalCola++; // Aumentamos el indice del final de la cola, solo movemos.
        }
        p->elemento[p->finalCola] = n; //Agregamos el elemento siempre que la cola no este llena
    }

    //Si esta llena se hace esto
    else
    {
        cout << "La cola esta llena" << endl;
    }
}

//Desencolar
void Eliminar(Nodo *p)
{
if(!Vacia(p))
{//Si es diferente de vacia, si aun hay elementos
if(Dimension(p)==1)
    //Hay dos casos
{ //Si solamente tiene un elemento
Crear(p); //Inicializa un frente y final en NULO
}else{//Si habia mas de un elemento
    p->frenteCola++; //Aumenta el frente de nuestra cola
}
}else{ //Si esta vacia no hay nada que mostrar
cout<<"Esta cola esta vacia: "<<endl;
}
}