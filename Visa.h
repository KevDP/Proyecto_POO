/* Header Visa*/

#ifndef VISA_H_
#define VISA_H_
#include <iostream>
#include "Tarjeta.h"            // Header Tarjeta: clase padre

using namespace std;

class Visa : public Tarjeta{            // Definimos la clase hija Visa junto con la clase padre Tarjeta

    private:                                // Atributos encapsulados

        string Contrasenia;                     // Contraseña para realizar operacion Pagar

    public:                                 // Métodos

        Visa(string Num_Tarjeta_, float Estado_dCuenta_, int Datos_CVV,string Datos_F_exp,int Contrasenia_); // Formato de los objetos Visa

        void pedir_Contrasenia();           // Funciones
        void crear_Contrasenia();
        void pagar_Visa();
        };

    Visa::Visa(string Num_Tarjeta_, float Estado_dCuenta_,int Datos_CVV,string Datos_F_exp,int Contrasenia_) : Tarjeta(Num_Tarjeta_, Estado_dCuenta_, Datos_CVV, Datos_F_exp){
    // Constructor del objeto Visa junto con los atributos que ya se conocen previamente de la clase padre

        Contrasenia = Contrasenia_;

    }

    void Visa::crear_Contrasenia(){      // Acción crear contraseña.
        cout<<"Cree una contraseña de 4 caracteres, puede usar numeros y letras mayusculas y minusculas \n ";
        cin>>Contrasenia;       // Ingresar la contraseña para ser encapsulada en el private.
        cout<<"Contraseña guardada con exito \n ";
    }
    void Visa::pedir_Contrasenia(){      // Acción pedir una contraseña.
        string Ingresa_Contrasenia;
        cout<<"Ingrese su contraseña \n ";
        cin>>Ingresa_Contrasenia;
        if(Ingresa_Contrasenia == Contrasenia){     // Si la contraseña coincide, se aceptará la contraseña.
            cout<<"Contraseña aceptada \n ";
        }
        else{
            while(Ingresa_Contrasenia != Contrasenia){      // Mientras la contraseña sea diferente, mandará error y la pedirá de nuevo.
                cout<<"\n La contraseña no coincide, intenta de nuevo \n ";
                cin>>Ingresa_Contrasenia;
            }
        }
    }

    void Visa::pagar_Visa(){      // Acción pagar servicios
        string Confirma;
        cout<<"\n \n Usted esta por pagar, Si cuenta con una contraseña de confirmacion ingrese segun sea el caso (si/no) ";
        cin>>Confirma;      // Confirmación para ingresar una contraseña de acceso a pagar un servicio
        if(Confirma == "si"){
            datos1.pedir_CVV();
            datos1.pedir_Fecha_exp();
            pedir_Contrasenia();
        }
        else{           // En caso de no tener una contraseña previa se pedirá crear una, deberá tener 4 caracteres.
            crear_Contrasenia();
            pedir_Contrasenia();    // Para terminar el proceso de crear una contraseña es necesario confirmar la contraseña, ingresar el CVV y la fecha de expiración.
            datos1.pedir_CVV();
            datos1.pedir_Fecha_exp();
        }
        float P_cantidad;
        cout<<"Cantidad que desea pagar $";
        cin>>P_cantidad;
            while(P_cantidad>get_Estado_dCuenta()){       // Mientras la cantidad de dinero a pagar el servicio sea mayor que el estado de cuenta, mandará el error.
                cout<<"\n Error! Cantidad invalida, efectivo en tarjeta insuficiente, intenta de nuevo. $";
                cin>>P_cantidad;
            }
        Estado_dCuenta-=P_cantidad;    //Estado_dCuenta-= Estado_dCuenta - R_cantidad
            cout<<" \n - Pago realizado con exito - \n ";
        Fondo_tarjeta();    // Mostrar el fondo en la tarjeta.
    }

#endif // VISA_H_
