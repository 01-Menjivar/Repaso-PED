#include<iostream>
#include<stdlib.h>
using namespace std;

struct Nodo{
    string name;
    int year;
    Nodo *next;
};

 Nodo *frente = NULL;
    Nodo *final = NULL;

void push (string, int);
void pop (string &, int &);

int main(){

    int year;
    string name;
    int opt;

    do{

    cout<<"\n1. Add items: "<<endl;
    cout<<"2. Print results: "<<endl;
    cout<<"3. Remove item: "<<endl;
    cout<<"4. Exit: "<<endl;
    cout<<"Select option: "<<endl;
    cin>>opt;

    switch (opt)
    {
    case 1: cout<<"\t**** It's movie time ****"<<endl;

    cout<<"Type the name of your movie: "<<endl;
    cin>>name;
    cout<<"Type the year of your movie: "<<endl;
    cin>>year;

    push(name,year);
    break;

    case 2: while (frente!=NULL)
{
    pop (name,year);
    cout<<"\**********************"<<endl;
    cout<<"Movie name: "<<name<<endl;
    cout<<"Year of the movie: "<<year<<endl;
    cout<<"\**********************"<<endl;
    cout<<"\n";
} break;
case 3: 
    pop(name,year);
    cout<<"Item removed"<<endl;
    }
    }while(opt!=4);
    return 0;
}

void push(string n, int y){
    Nodo *new_Nodo = new Nodo();
    new_Nodo->name=n;
    new_Nodo->next=NULL;
    new_Nodo->year=y;
    new_Nodo->next=NULL;

    if(frente == NULL){
        frente = new_Nodo;
    }else{
        final->next=new_Nodo;
    }

    final = new_Nodo;
}

void pop(string &n, int &y){
    n = frente->name;
    y = frente->year;
    Nodo *aux = frente;
    if(frente==final){
        frente = NULL;
        final = NULL;
    }else{
        frente = frente->next;
    }
    delete aux;
}