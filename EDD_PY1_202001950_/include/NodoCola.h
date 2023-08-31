#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "Proyecto.h"

class NodoCola
{
    public:
        NodoCola *Siguiente;
        Proyecto *Proyecto_cola;
        NodoCola(string nombre, string prioridad, string codigo);
        virtual ~NodoCola();

    protected:

    private:
};

#endif // NODOCOLA_H
