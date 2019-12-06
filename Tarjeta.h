#ifndef TARJETA_H_
#define TARJETA_H_
#include <iostream>
#include "Datos_tarjeta.h"

using namespace std;

class Tarjeta{

    private:    //Atributos encapsulados
        string Num_Tarjeta;         // N�mero de tarjeta

    protected:  // Atributos protegidos
        float Estado_dCuenta;       // Estado de cuenta

    public: //M�todos
        Datos datos1;             // Datos Tarjeta, objeto con los atributos datos de la tarjeta
        Tarjeta();          // Constructor default
        Tarjeta(string Num_Tarjeta_,float Estado_dCuenta_,int Datos_CVV,string Datos_F_exp); // Manera en que los datos son ingresados, los atributos de los objetos son ingresados


        string get_Num_Tarjeta();       //Getters nos permiten obtener datos que est�n encapsulados como el dinero en la cuenta
        float get_Estado_dCuenta();     //Obtener el estado de cuenta
        void set_Num_Tarjeta(string);   //Setters nos permiten determinar o modificar datos en atributos que est�n encapsulados.
        void set_Estado_dCuenta(float);    //Determinar estado de cuenta

        void depositar();           //Funcion para depositar efectivo a la tarjeta
        void retirar();             //Permitir retirar efectivo guardado en la tarjeta
        void Fondo_tarjeta();       //Mostrar los fondos que se tienen en la tarjeta

};
    Tarjeta::Tarjeta(string Num_Tarjeta_,float Estado_dCuenta_,int Datos_CVV,string Datos_F_exp){// Constructor basico
        datos1.modif(Datos_CVV,Datos_F_exp);        // Llamamos la funcion modificar datos del objeto datos de tarjeta
        Num_Tarjeta = Num_Tarjeta_;         // Se igualan los datos para lograr modificarse despues, segun lo ingresado en el constructor.
        Estado_dCuenta = Estado_dCuenta_;

    }

    string Tarjeta::get_Num_Tarjeta(){          // Obtener el numero de tarjeta encapsulado
        return Num_Tarjeta;                         // Regresar el dato del numero de tarjeta
    }
    float Tarjeta::get_Estado_dCuenta(){        // Obtener el estado de cuenta encapsulado
        return Estado_dCuenta;                      // Regresar el dato del estado de cuenta
    }

    void Tarjeta::set_Num_Tarjeta(string Num_Tarjeta_){         // Modificar o determinar el numero de tarjeta encapsulado
        Num_Tarjeta = Num_Tarjeta_;
    }
    void Tarjeta::set_Estado_dCuenta(float Estado_dCuenta_){    // Modificar o determinar el estado de cuenta encapsulado
        Estado_dCuenta = Estado_dCuenta_;
    }

    void Tarjeta::depositar(){                  // Accion depositar
        float D_cantidad;
        cout<<"\n Cantidad que desea depositar $";
        cin>>D_cantidad;
            while(D_cantidad<1){                        // Mientras la cantidad a depositar sea menor a 1, botar el error de cantidad invalida.
                cout<<"\n Error! Cantidad invalida.";
                cin>>D_cantidad;            // Cantidad a depositar
            }
        datos1.pedir_CVV();                // Para completar el dep�sito es necesario pedir el CVV
        Estado_dCuenta+=D_cantidad; // Estado_dCuenta+= Estado_dCuenta + D_cantidad
        Fondo_tarjeta();            // De esta manera, cada que se use un deposito de efectivo, se imprimir el Estado de cuenta actual.
    }

    void Tarjeta::retirar(){    // Accion retirar.
        float R_cantidad;
        cout<<"\n Cantidad que desea retirar: $";
        cin>>R_cantidad;        // Cantidad a retirar.
            while(R_cantidad>Estado_dCuenta){       //  Mientras la cantidad a retirar sea mayor que la cantidad de efectivo en la tarjeta mandar� error de fondos insufiientes.
                cout<<"\n Error! Cantidad invalida, efectivo en tarjeta insuficiente.";
                cin>>R_cantidad;
            }
        datos1.pedir_CVV();            // Para retirar efectivo es necesario ingresar el CVV.
        Estado_dCuenta-=R_cantidad; // Estado_dCuenta-= Estado_dCuenta - R_cantidad.
        Fondo_tarjeta();            // De esta manera, cada que se use un retiro de efectivo, se desplegara el Estado de cuenta actual.
    }

    void Tarjeta::Fondo_tarjeta(){  // Accion mostrar el Estado de cuenta
        limp_pant();        //limpiar pantalla
        cout<<"\n \n Usted cuenta con: \n $"<<get_Estado_dCuenta();
    }


#endif // TARJETA_H_
