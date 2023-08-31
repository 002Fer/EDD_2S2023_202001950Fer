#include <iostream>
#include <string>
#include <stdlib.h>
#include "ListaCircular.h"
#include "Prioridad_Proy.h"
#include "ListaDoble.h"
#include <fstream>
#include <string.h>
#include <cstring>
#include <sstream>
#include <stdlib.h>
#include <fstream>

using namespace std;
string inicio(string usuario, string password);
void menu();
void LeerArchivo(string nombre_archivo);
Prioridad_Proy *cola = new Prioridad_Proy();
int main()
{
    string user,pase;
    string op="";
    string opcion_empleados;
    string op_puesto,nombre_archivo, op_proyecto;
    string nombre_Tar;

    string nombre_proyecto,prioridad;

    int numero_codigo=1;
    int numero_codigo2=1;
    int numero_codigo3=1;

    int numero_proy=1;
    ListaCircular *lista=new ListaCircular();
    ListaDoble *nuevaTarea=new ListaDoble();


    cout<<"\n*********** EDD ProjectUp ************"<<endl;
    cout << "Ingrese el numero de usuario: "  ;cin>>user;
    cout << "\nIngrese el password: ";cin>>pase;

    string resultado=inicio(user,pase);
    if (resultado=="verdadero"){

        system("cls");

        while(op!="6"){

        cout<<"\n***********      EDD ProjectUp       ************"<<endl;
        cout<<"*********** Bienvenido PM-202001950  ************"<<endl;
        cout<<"1. Carga de empleados"<<endl;
        cout<<"2. Crear Proyecto"<<endl;
        cout<<"3. Crear Tareas"<<endl;
        cout<<"4. Asignar Tareas"<<endl;
        cout<<"5. Reportes"<<endl;
        cout<<"6. Salir"<<endl;
        cout<<"Ingrese una opcion: ";cin>>op;

        if (op=="1"){
            system("cls");

            cout<<"***********      EDD ProjectUp       ************"<<endl;
            cout<<"*********** Bienvenido PM-202001950  ************"<<endl;
            cout<<"***********  Menu Carga de Empleados ************"<<endl;
            cout<<"1. Carga Manual"<<endl;
            cout<<"2. Carga Masiva"<<endl;
            cout<<"Elija su opcion: "<<endl;
            cin>>opcion_empleados;
            string empleado,contrasena_empleado;
            string puesto_Empleado="";


            if (opcion_empleados=="1"){
                string mas_empleados="y";

                while(mas_empleados!="n"){
                cin.ignore();
                cout<<"Empleado: ";
                std::getline(std::cin,empleado);
                cout<<"\nPassword: ";
                std::getline(std::cin,contrasena_empleado);


                cout<<""<<endl;



                    //string codigo = (numero_codigo < 100 ? (numero_codigo < 10 ? "FDEV-00"+std::to_string(numero_codigo) : "FDEV-0"+std::to_string(numero_codigo)): "FDEV-"+std::to_string(numero_codigo));
                    //numero_codigo++;
                lista->Insertar(empleado,contrasena_empleado);
                cout<<"Agregado Exitosamente"<<endl;
                    //cout<<codigo<<endl;

                cout<<" ¿Desea agregar un nuevo empleado? y/n: ";
                cin>>mas_empleados;
                cout<<""<<endl;

            }

            }
            else if (opcion_empleados=="2"){
                cout<<"Ingrese el nombrel del archivo: ";
                cin>>nombre_archivo;
                try
                {
                    ifstream lectura;
                    lectura.open(nombre_archivo, ios::in);
                    bool encabezado = false;
                    for(string fila; getline(lectura,fila);)
                    {
                        stringstream lineas(fila);
                        string nombre;
                        string password;


                        if(encabezado)
                        {

                            getline(lineas, nombre, ',');
                            getline(lineas, password, ',');

                            lista->Insertar(nombre, password);
                        }
                        else{
                            encabezado = true;
                        }

                    }
                }
                catch(exception)
                {
                    cout << "No se pudo leer el archivo" << endl;
                }
                cout<<"Carga Exitosa..."<<endl;
                lista->VerLista();
            }
        }
        else if(op=="2"){
            system("cls");
            string mas_proy="y";


            cout<<"***********      EDD ProjectUp       ************"<<endl;
            cout<<"*********** Bienvenido PM-202001950  ************"<<endl;
            cout<<"***********      Menu Proyectos      ************"<<endl;
            while (mas_proy!="n"){
            cin.ignore();
            cout<<"Nombre del Proyecto: "<<endl;
            getline(cin,nombre_proyecto);
            cout<<"\nTipo de Prioridad"<<endl;

            getline(std::cin,prioridad);
            cout<<""<<endl;
            string codigo="100";
            codigo = (numero_proy < 999 ? (numero_proy < 10 ? "PY-10"+std::to_string(numero_proy) : "PY-0"+std::to_string(numero_proy)): "PY-"+std::to_string(numero_proy));
            numero_proy++;
            cola->Encolar(nombre_proyecto,prioridad,codigo);
            cout<<"Agregado Exitosamente, "<<endl;
            cout<<codigo<<endl;




            cout<<" \n¿Desea agregar un nuevo proyecto? y/n: ";
            cin>>mas_proy;
            cout<<""<<endl;

            }
            cola->Ordenar();
            cola->VerProyectos();


        }
        else if(op=="3"){
            system("cls");
            string mas_tareas="y";


            cout<<"***********      EDD ProjectUp       ************"<<endl;
            cout<<"*********** Bienvenido PM-202001950  ************"<<endl;
            cout<<"***********      Menu de Tareas      ************"<<endl;
            while (mas_tareas!="n"){
                cola->VerProyectos();
                cin.ignore();
                cout<<"Seleccione Proyecto: ";
                cin>>op_proyecto;
                cin.ignore();
                cout<<"\nNombre de tarea: ";
                getline(cin,nombre_Tar);
                cout<<"\nTarea Guardada!"<<endl;

                nuevaTarea->Insertar(op_proyecto,nombre_Tar,"");
                cout<<" \n¿Desea agregar un nueva tarea? y/n: ";
                cin>>mas_tareas;
                cout<<""<<endl;
            }
        }
        else if(op=="4"){
            system("cls");
            cin.ignore();
            string empleado1;
            string puesto,codigo;
            ListaDoble *Tarea=new ListaDoble();

            cout<<"***********      EDD ProjectUp       ************"<<endl;
            cout<<"*********** Bienvenido PM-202001950  ************"<<endl;
            cout<<"***********    Asignacion Proyectos  ************"<<endl;
            cout<<"\nEmpleados Registrados:"<<endl;
            lista->VerLista();
            cout<<"\nIngrese el Empleado: ";
            getline(cin,empleado1);
            string vista= lista->buscar(empleado1);
            cout<<"\n1. Frontend Developer  "<<endl;
            cout<<"2. Backend Developer  "<<endl;
            cout<<"3. Quality Assurance  "<<endl;
            cin>>puesto;
            if (puesto=="1"){
                codigo = (numero_codigo < 999 ? (numero_codigo < 10 ? "FDEV-00"+std::to_string(numero_codigo) : "FDEV-0"+std::to_string(numero_codigo)): "FDEV-"+std::to_string(numero_codigo));
                numero_codigo++;
                cout<<"Id generado:  "<<codigo;
            }
            else if (puesto=="2"){
                codigo = (numero_codigo < 999 ? (numero_codigo < 10 ? "BDEV-00"+std::to_string(numero_codigo) : "BDEV-0"+std::to_string(numero_codigo)): "BDEV-"+std::to_string(numero_codigo));
                numero_codigo++;
                cout<<"Id generado:  "<<codigo;
            }
            else if (puesto=="3"){
                codigo = (numero_codigo < 999 ? (numero_codigo < 10 ? "QA-00"+std::to_string(numero_codigo) : "QA-0"+std::to_string(numero_codigo)): "QA-"+std::to_string(numero_codigo));
                numero_codigo++;
                cout<<"Id generado:  "<<codigo;
            }
            cout<<"proyectos creados: "<<endl;

        }
        else if(op=="4"){
            system("cls");
            string reportes;
            cout<<"***********      EDD ProjectUp       ************"<<endl;
            cout<<"*********** Bienvenido PM-202001950  ************"<<endl;
            cout<<"***********    Reportes              ************"<<endl;
            cout<<"1. Reporte Cola prioridad"<<endl;
            cout<<"1. Reporte Matriz dispersa"<<endl;
            cout<<"1. Reporte Json"<<endl;
            cout<<"ingrese su opcion";
            cin>>reportes;
            if(reportes=="1"){
                cola->graficar();
                cout<<"se creo la imagen";
            }
            else if(reportes=="2"){

                cout<<"se creo la imagen";
            }
            else if(reportes=="3"){
            cout<<"se creo reporte";
            }

            }




    }



}
    cout << "Hello world!" << endl;
    system("pause");
    return 0;
}
string inicio(string usuario, string password){
    std::string Usuario="PM-202001950";
    std::string Password="202001950";
    std::string aceptado="falso";
    if ((usuario==Usuario)&&(password==Password)){
        aceptado="verdadero";
        return aceptado;
    }
    else{
        return aceptado;
    }
}




