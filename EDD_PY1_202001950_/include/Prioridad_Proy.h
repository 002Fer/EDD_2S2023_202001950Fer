#ifndef PRIORIDAD_PROY_H
#define PRIORIDAD_PROY_H
#include "NodoCola.h"
#include "Proyecto.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Prioridad_Proy
{
    public:
        NodoCola *Primero;
        int Tamanio;
        void Encolar(string nombre, string prioridad, string codigo);
        void Descolar();
        void Ordenar();
        void graficar();
        void VerProyectos();
        Prioridad_Proy();
        virtual ~Prioridad_Proy();

    protected:

    private:
        string textoGrafica();
};

#endif // PRIORIDAD_PROY_H
