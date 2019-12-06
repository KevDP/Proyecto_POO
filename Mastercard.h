/* Header Mastercard*/

#ifndef MASTERCARD_H_
#define MASTERCARD_H_
#include <iostream>
#include "Tarjeta.h"            // Header Tarjeta: clase padre

using namespace std;

class Mastercard : public Tarjeta{          // Definimos la clase hija Mastercard con la clase padre Tarjeta

    private:                    // Atributos encapsulados

        int NIP;                // NIP para realizar operacion Pagar

    public:             // Métodos

        Mastercard(string Num_Tarjeta_, float Estado_dCuenta_, int Datos_CVV,string Datos_F_exp,int NIP_);       // Formato de los objetos Mastercard


        void pedir_NIP();           // Funciones
        void crear_NIP();
        void pagar_Master();
};

    Mastercard::Mastercard(string Num_Tarjeta_, float Estado_dCuenta_, int Datos_CVV,string Datos_F_exp,int NIP_) : Tarjeta(Num_Tarjeta_,Estado_dCuenta_, Datos_CVV,Datos_F_exp){
    // Constructor del formato del objeto Mastercard junto con los atributos que ya se conocen previamente de la clase padre

        NIP = NIP_;     // Generar otro dato para lograr modificarse después

}

    void Mastercard::crear_NIP(){      // Acción crear NIP.
        cout<<"Cree un NIP de 4 digitos \n ";
        cin>>NIP;       // Ingresar la contraseña para ser encapsulada en el private.
        cout<<"NIP guardado con exito \n ";
}
    void Mastercard::pedir_NIP(){      // Acción pedir una contraseña.
        int Ingresa_NIP;
        cout<<"Ingrese su NIP \n ";
        cin>>Ingresa_NIP;
        if(NIP == Ingresa_NIP){     // Si la contraseña coincide, se aceptará la contraseña.
            cout<<"NIP aceptado \n ";
}
        else{
            while(Ingresa_NIP != NIP){      // Mientras la contraseña sea diferente, mandará error y la pedirá de nuevo.
                cout<<"\n El NIP no coincide, intenta de nuevo \n ";
                cin>>Ingresa_NIP;
}
}
}

    void Mastercard::pagar_Master(){      // Acción pagar servicios
        string Confirma;
        cout<<"\n \n Usted esta por pagar, Si cuenta con una contraseña de confirmacion ingrese segun sea el caso (si/no) ";
        cin>>Confirma;      // Confirmación para ingresar una contraseña de acceso a pagar un servicio
        if(Confirma == "si"){
            datos1.pedir_CVV();
            datos1.pedir_Fecha_exp();
            pedir_NIP();
}
        else{           // En caso de no tener una contraseña previa se pedirá crear una, deberá tener 4 caracteres.
            crear_NIP();
            pedir_NIP();    // Para terminar el proceso de crear una contraseña es necesario confirmar la contraseña, ingresar el CVV y la fecha de expiración.
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

#endif // MASTERCARD_H_
