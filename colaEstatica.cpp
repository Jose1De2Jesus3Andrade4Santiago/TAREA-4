//LIBRERIAS A INCLUIR
#include<iostream>

//DEFINICIONES
using namespace std;

struct Nodo{
    int dato;
    int next;
    int previous;
};

//PROTOTIPOS
Nodo* crear();
int siguiente(int indice_actual,int tamanio);
void encolar(Nodo* cola[],int& back, int& front, int& tamanio);
int size(Nodo* cola[],int front, int back,int tamanio);
void imprimir(Nodo* cola[],int front,int size,int tamanio);

//FUNCION PRINCIPAL MAIN
int main(){
    int tamanio=3;
    int front=0,back=0;
    Nodo* cola[tamanio];
    return 0;
}

Nodo* crear(){
    Nodo* nuevo=new Nodo();
    cout<<"DIGITA UN DATO: "<<endl;
    cin>>nuevo->dato;
    return nuevo;
}

int siguiente(int indice_actual,int tamanio){
    if(indice_actual>=(tamanio-1))
        return 0;
    return indice_actual+1;
}


void encolar(Nodo* cola[],int& back, int& front, int& tamanio){
    if(back==front && tamanio==0)
        cout<<"COLA LLENA"<<endl;
    else{
        Nodo* nuevo_elemento=crear();
        cola[back]=nuevo_elemento;
        back=siguiente(back,tamanio);
        tamanio-=1;
    }
}

Nodo* Front(Nodo* cola[],int front,int tamanio){
    Nodo* aux=cola[siguiente(front,tamanio)];
    return aux;
}

int anterior(int indice_actual,int tamanio){
    if(indice_actual<=0)
        return (tamanio-1);
    return indice_actual-1;
}


Nodo* Back(Nodo* cola[], int back, int tamanio){
    Nodo*aux =cola[anterior(back,tamanio)];
    return aux;
}

int size(Nodo* cola[],int front, int back,int tamanio){
    int size=0;
    int aux=back;
    do{
        size++;
        aux=siguiente(aux,tamanio);
    }while(aux!=back);
    return size;
}

void imprimir(Nodo* cola[],int front,int size,int tamanio){
    int indice=front;
    cout<<indice<<endl;
    cout<<"ELEMENTOS DE LA COLA:"<<endl;
    for(int i=0;i<size;i++){
        cout<<cola[indice]->dato<<endl;
        indice=siguiente(indice,tamanio);
    }
}




