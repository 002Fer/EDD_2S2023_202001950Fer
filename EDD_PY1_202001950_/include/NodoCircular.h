#ifndef NODOCIRCULAR_H
#define NODOCIRCULAR_H

#include <string>
#include "Empleado.h"
using namespace std;

class NodoCircular
{
    public:
        Empleado *EmpleadoSistema;
        NodoCircular *Siguiente;
        NodoCircular *Anterior;
        NodoCircular(string nombre, string password);
        virtual ~NodoCircular();

    protected:

    private:
};

#endif // NODOCIRCULAR_H
