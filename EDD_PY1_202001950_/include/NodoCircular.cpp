#include "NodoCircular.h"

NodoCircular::NodoCircular(string nombre, string password)
{
    //ctor
    this->Siguiente=0;
    this->Anterior=0;
    this->EmpleadoSistema=new Empleado(nombre,password);
}

NodoCircular::~NodoCircular()
{
    //dtor
}
