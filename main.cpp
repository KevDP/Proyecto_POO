// Programaci�n Orientado a Objetos
// Alumno: Kevin Joan Delgado P�rez A01706328
/* Programa que simula 3 objetos de clase Tarjeta con atributos como
depositar, retirar efectivo o pagar un servicio, as� como el actual
Estado de Cuenta, el programa solicitar� el CVV para cada uno de las
acciones, sin embargo, para la funcion de pagar un servicio, se requerir�
crear una contrase�a si no se tiene alguna previamente. */

#include <iostream>

using namespace std;
void limp_pant(){                   // Esta función limpiara la pantalla
    for (int i = 0; i < 100; i++)
    {
        cout<<endl;
    }

};


#include "Datos_tarjeta.h"
#include "Tarjeta.h"
#include "Visa.h"
#include "Mastercard.h"

int main(){
    cout<<"¡Bienvenido!"<<endl;
    Visa visa1("4152 3134 1761 2654",1000.00,428,"01/23",1234);          // Objeto(numero de tarjeta, estado de cuenta,CVV,Fecha de expiraci�n)
    cout<<"\n El numero de la tarjeta ingresada es \n"<< visa1.get_Num_Tarjeta();
    cout<<"\n Su estado de cuenta actual es de: \n $"<< visa1.get_Estado_dCuenta();
    visa1.depositar();
    visa1.retirar();
    visa1.pagar_Visa();


    Mastercard mastercard1("5578 0900 3958 6400",2000.00,589,"15/24",1234);    // Objeto(numero de tarjeta, estado de cuenta,CVV,Fecha de expiraci�n)
    cout<<"\n \n El numero de la tarjeta ingresada es \n"<< mastercard1.get_Num_Tarjeta();
    cout<<"\n \n Su estado de cuenta actual es de: \n $"<< mastercard1.get_Estado_dCuenta();
    mastercard1.depositar();
    mastercard1.retirar();
    mastercard1.pagar_Master();


    Visa visa2("4152 4143 1671 3488",12000.00,526,"03/21",1234);        // Objeto(numero de tarjeta, estado de cuenta,CVV,Fecha de expiraci�n)
    cout<<"\n \n El numero de la tarjeta ingresada es \n"<< visa2.get_Num_Tarjeta();
    cout<<"\n \n Su estado de cuenta actual es de: \n $"<< visa2.get_Estado_dCuenta();
    visa2.depositar();
    visa2.retirar();
    visa2.pagar_Visa();

    return 0;
}
