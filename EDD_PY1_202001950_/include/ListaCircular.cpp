#include "ListaCircular.h"
#include <string>

using namespace std;
ListaCircular::ListaCircular()
{
    //ctor
    this->Primero=0;
    this->Tamanio=0;
}

ListaCircular::~ListaCircular()
{
    //dtor
}
void ListaCircular::Insertar(string nombre, string password)
{
    NodoCircular *nuevo = new NodoCircular(nombre, password);

    if(this->Primero == 0)
    {
        /*------------------*/
        nuevo->Anterior = nuevo;
        nuevo->Siguiente = nuevo;
        this->Primero = nuevo;
        this->Tamanio++;
    }else
    {
        NodoCircular *aux = this->Primero;
        int contador = 1;
        while(this->Tamanio > contador)
        {
            aux = aux->Siguiente;
            contador++;
        }
        nuevo->Anterior = aux;
        nuevo->Siguiente = this->Primero;
        aux->Siguiente = nuevo;
        this->Primero->Anterior = nuevo;
        this->Tamanio++;
    }
}

void ListaCircular::VerLista()
{
    NodoCircular *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        cout << aux->EmpleadoSistema->Nombre << endl;
        cout << aux->EmpleadoSistema->Password << endl;

        aux = aux->Siguiente;
        contador++;
    }
}
std::string ListaCircular::buscar(string nombre_buscado)
{
    NodoCircular *aux = this->Primero;
    int contador = 0;
    while(this->Tamanio > contador)
    {
        if (aux->EmpleadoSistema->Nombre==nombre_buscado){
            cout<<"Usuario encontrado";
            return aux->EmpleadoSistema->Nombre;
            break;
        }


        aux = aux->Siguiente;
        contador++;
    }

}
