#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include <string>

using namespace std;

class NodoListaDoble
{
    public:
        string Codigo;
        string NombreTarea;
        string Encargado;
        NodoListaDoble *Siguiente;
        NodoListaDoble *Anterior;

        NodoListaDoble(string codigo,string nombreTarea,string encargado);
        virtual ~NodoListaDoble();

    protected:

    private:
};

#endif // NODOLISTADOBLE_H
