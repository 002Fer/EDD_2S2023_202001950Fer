#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H
#include "NodoCircular.h"
#include <string>
#include <iostream>
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>

class ListaCircular
{
    public:
        NodoCircular *Primero;
        int Tamanio;
        string x;
        void Insertar(string nombre, string password);
        void VerLista();
        string buscar(string x);
       /** void LeerArchivo(std::string nombre_archivo);*/
        ListaCircular();
        virtual ~ListaCircular();

    protected:

    private:
};

#endif // LISTACIRCULAR_H
