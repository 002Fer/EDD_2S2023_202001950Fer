#include "ListaDoble.h"

ListaDoble::ListaDoble()
{
    //ctor
    this->Primero=0;
    this->Tamanio=0;

}

ListaDoble::~ListaDoble()
{
    //dtor
}
void ListaDoble::Insertar(string codigo, string nombre_tarea, string codigo_encargado)
{

    NodoListaDoble *nuevo=new NodoListaDoble(codigo,nombre_tarea,codigo_encargado);
    if (this->Primero==0)
    {
        this->Primero=nuevo;
    this->Tamanio++;

    }
    else{
        NodoListaDoble *aux=this->Primero;
        while(aux->Siguiente)
        {
            aux=aux->Siguiente;
        }
        nuevo->Anterior=aux;
        aux->Siguiente= nuevo;
        this->Tamanio++;
    }
}



