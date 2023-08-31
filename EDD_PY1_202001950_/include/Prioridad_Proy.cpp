#include "Prioridad_Proy.h"

Prioridad_Proy::Prioridad_Proy()
{
    //ctor
    this->Primero=0;
    this->Tamanio=0;
}

Prioridad_Proy::~Prioridad_Proy()
{
    //dtor
}
void Prioridad_Proy::Encolar(string nombre, string prioridad, string codigo)
{

    NodoCola *nuevoNodo = new NodoCola(nombre,prioridad,codigo);
    if(this->Primero == 0)
    {
        this->Primero = nuevoNodo;
        this->Tamanio++;
    }else{
        NodoCola *aux = this->Primero;
        while(aux->Siguiente)
        {
            aux = aux->Siguiente;
        }
        aux->Siguiente = nuevoNodo;
        this->Tamanio++;
    }
    /**
    1. Crear una funcion que tenga una cola temporal, una copia de la cola actual
    2. Cola temporal, le aplican un ordenamiento.
    3. this->Primero = colaTemp.Primero

    funcion Orderna
        *colatemp = this->primero
        ordenamientoBurbuja(colatemp)

    PY-100 | B - PY-101 | B - PY-102 | A
    PY-102 - PY-100 - PY-101
    */
}


void Prioridad_Proy::VerProyectos()
{
    NodoCola *aux = this->Primero;
    int contador = 0;
    while(aux)
    {
        cout << aux->Proyecto_cola->Codigo ;
        cout<<"     Nombre:  ";
        cout<< aux->Proyecto_cola->Nombre<<endl;
        aux = aux->Siguiente;
        contador++;
    }
}

void Prioridad_Proy::Descolar()
{
    if(this->Primero)
    {
        this->Primero = this->Primero->Siguiente;
    }
}
void Prioridad_Proy::Ordenar()
{
    if(this->Primero)
    {
        NodoCola *piv = this->Primero;
        NodoCola *actual;
        int contador = 0;
        while(contador != this->Tamanio)
        {
            actual = piv->Siguiente;
            while(actual)
            {
                if(piv->Proyecto_cola->Prioridad.compare(actual->Proyecto_cola->Prioridad) == 1)
                {
                    Proyecto *tempProyecto = piv->Proyecto_cola;
                    std::string tempPrioridad = piv->Proyecto_cola->Prioridad;
                    piv->Proyecto_cola = actual->Proyecto_cola;
                    piv->Proyecto_cola->Prioridad = actual->Proyecto_cola->Prioridad;
                    actual->Proyecto_cola = tempProyecto;
                    actual->Proyecto_cola->Prioridad = tempPrioridad;
                }
                actual = actual->Siguiente;
            }
            piv = piv->Siguiente;
            contador++;
        }
    }
}
string Prioridad_Proy::textoGrafica()
{
    std::string cuerpo = "";
    NodoCola *aux = this->Primero;
    for(int i = 0; i < this->Tamanio; i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="[label=\"";
        cuerpo+=aux->Proyecto_cola->Codigo;
        cuerpo+="\n";
        cuerpo+="PRIORIDAD: ";
        cuerpo+=aux->Proyecto_cola->Prioridad;
        cuerpo+="\"]; \n";
        aux = aux->Siguiente;
    }
    for(int i = 0; i < (this->Tamanio-1); i++)
    {
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+=" -> nodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+="\n";
    }
    return cuerpo;
}
void Prioridad_Proy::graficar()
{
    ofstream archivo;
    archivo.open("ListaSimple.dot",ios::out);
    if(archivo.fail())
    {
        cout << "Se produjo un error" << endl;
    }else{
        archivo << "digraph migrafica{\n rankdir=LR; \n node[shape=box]" << textoGrafica() << "\n }";
        archivo.close();
    }

    try{
        system("dot -Tjpg ListaSimple.dot -o ListaSimple.jpg");
    }catch(exception e){
        cout << "Error al generar imagen";
    }
}
