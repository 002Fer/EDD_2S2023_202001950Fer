#ifndef PROYECTO_H
#define PROYECTO_H
#include <string>

using namespace std;

class Proyecto
{
    public:
        string Nombre;
        string Prioridad;
        string Codigo;
        Proyecto(string nombre, string prioridad, string codigo);
        virtual ~Proyecto();

    protected:

    private:
};

#endif // PROYECTO_H
