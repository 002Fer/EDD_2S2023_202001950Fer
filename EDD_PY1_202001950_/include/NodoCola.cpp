#include "NodoCola.h"

NodoCola::NodoCola(string nombre, string prioridad, string codigo)
{
    //ctor
    this->Siguiente=0;
    this->Proyecto_cola=new Proyecto(nombre,prioridad,codigo);
}

NodoCola::~NodoCola()
{
    //dtor
}
