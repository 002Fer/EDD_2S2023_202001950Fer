#include "NodoListaDoble.h"

NodoListaDoble::NodoListaDoble(string codigo,string nombreTarea,string encargado)
{
    //ctor
    this->Codigo = codigo;
    this->NombreTarea = nombreTarea;
    this->Encargado = encargado;
    this->Anterior = 0;
    this->Siguiente = 0;
}

NodoListaDoble::~NodoListaDoble()
{
    //dtor
}
