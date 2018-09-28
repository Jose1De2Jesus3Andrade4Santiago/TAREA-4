#include<iostream>
using namespace std;

//definiciones
struct Nodo{
    int dato;
    Nodo* next;
    Nodo* previous;
};

//PROTOTIPOS
Nodo* crear();
int size(Nodo*);
int pedir_valor();
bool empty(Nodo*);
Nodo* Back(Nodo*);
Nodo* Front(Nodo*);
void imprimir(Nodo*);
void encolar(Nodo**, Nodo **);
Nodo* desencolar(Nodo**,Nodo**);

//FUNCION PRINCIPAL MAIN
int main(){
    Nodo* front=NULL;
    Nodo* back=NULL;
    return 0;
}

int pedir_valor(){
    int valor;
    cout<<"INGRESA UN VALOR: "<<endl;
    cin>>valor;
    return valor;
}

Nodo* crear(){
    Nodo* nodo=new Nodo();
    nodo->dato=pedir_valor();
    return nodo;
}

void encolar(Nodo** front, Nodo ** back){
    Nodo* nuevo_elemento=crear();
    nuevo_elemento->previous=NULL;
    if( *front==NULL || *back==NULL){//SI LA COLA ESTA VACIA
        nuevo_elemento->next=NULL;
        *back=nuevo_elemento;
        *front=nuevo_elemento;
    }else{//SI LA COLA TIENE UN UNICO ELEMENTO
        nuevo_elemento->next=*back;
        (*back)->previous=nuevo_elemento;
        *back=nuevo_elemento;
    }
}

bool empty(Nodo* front){
    if(front==NULL)
        return true;
    return false; 
}

Nodo* desencolar(Nodo** front,Nodo** back){
    /*PROFESOR EN MI ULTIMA TAREA ME DEJO UN COMENDARIO 
    DICIENDO QUE NO LIBERE LA MEMORIA, YA ME DI CUENTA DE MI ERROR 
    SIN EMBARGO AQUI YA NO LIBERE LA MEMORIA YA QUE NO ENCONTRE LA MANERA DE LIBERARLA
    SI HACIA UN DELET A BACK O  AUX PERDIA LOS DATOS EN AMBAS REFERENCIAS 
    LA UNICA SOLUCION QUE ENCONTRE FUE IGUALAR SOLAMENTE EL DATO  SIN LAS REFERENCIAS Y HACER DELET A BACK 
    PERO AUX YA NO TENDRIA LAS REFERENCIAS QUE TENIA BACK POR ESA RAZON TAMPOCO LA IMPLEMENTE :c 
    SI PUDIERA DECIRME DE QUE MANERA PUDE HABERLO HECHO SERIA DE MUCHA AYUDA :)*/
    if(empty(*front)==true){
        cout<<"LA COLA ESTA VACIA"<<endl;  
        return *front;	
	}
    else if(*front==*back){//LA COLA TIENE UN UNICO ELEMENTO
        Nodo* aux=*back;
        *back=NULL;
        *front=NULL;
        return aux;
    }
    else{//la cola tiene mas de un elemento
        Nodo* aux=*back;
        *back=(*back)->next;
        (*back)->previous=NULL;
        return aux;
    } 
}

Nodo* Front(Nodo* front){
 return front;
}

Nodo* Back(Nodo* back){
    return back;
}

int size(Nodo* front){
    int tamanio=0;
    Nodo* aux=front;

    if(aux==NULL)
        return tamanio;
    else{    
    	while(aux!=NULL){
            tamanio++;
            aux=aux->previous;
    	}	
	}
    return tamanio;
}

void imprimir(Nodo* front){
    Nodo* aux=front;
    if(aux==NULL)
        cout<<"cola vacia"<<endl;
    else{
    	cout<<"ELEMENTOS DE LA COLA"<<endl;    
    	while(aux!=NULL){
        	cout<<aux->dato<<endl;
        	aux=aux->previous;
    	}	
	}
}
