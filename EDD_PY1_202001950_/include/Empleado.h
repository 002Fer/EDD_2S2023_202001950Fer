#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>

using namespace std;
class Empleado
{
    public:

        string Nombre;
        string Password;

        Empleado(string nombre, string password);
        virtual ~Empleado();

    protected:

    private:
};

#endif // EMPLEADO_H
