#ifndef DATOS_H_
#define DATOS_H_
#include <iostream>

using namespace std;

class Datos{        // Determinamos la clase padre

    private:

        int CVV;        // Codigo de seguridad de 3 digitos
        string Fecha_exp;   // Fecha de expiracion

    public:
        Datos(){};          // Constructor por default
        void modif(int CVV_, string Fecha_exp_){        // Determinar los datos de la tarjeta en cada objeto
            CVV = CVV_;
            Fecha_exp = Fecha_exp_;
        };

        int get_CVV(){         // Obtener los 3 digitos de seguridad
            return CVV;
        };

        string get_Fecha_exp(){
            return Fecha_exp;
            };     //Obtener la fecha de expiraci�n de la tarjeta

        void set_CVV(int CVV_){         //Determinar el CVV
            CVV = CVV_;
            };

        void set_Fecha_exp(string Fecha_exp_){
            Fecha_exp = Fecha_exp_;
            };           //Determinar la fecha de expiracion

        void pedir_Fecha_exp(){
            string Ingresa_Fecha_exp;
            cout<<"Ingrese la fecha de expiracion de su tarjeta \n ";
            cin>>Ingresa_Fecha_exp;
            if(Ingresa_Fecha_exp == get_Fecha_exp()){       // Coincidir la fecha de expiracion ingresada con la encapsulada.
                cout<<"Ingresado con exito \n ";
            }
            else{
                while(Ingresa_Fecha_exp != get_Fecha_exp()){        // Mientras no coincida mandar error y se podra ingresar de nuevo.
                    cout<<"La fecha de expiracion no coincide, intenta de nuevo \n ";
                    cin>>Ingresa_Fecha_exp;
                }
            }
        };
        void pedir_CVV(){
            int Ingresa_CVV;
            cout<<"Ingrese el CVV de su tarjeta \n ";
            cin>>Ingresa_CVV;
            if(Ingresa_CVV == get_CVV()){       // Coincidir el CVV ingresado con el encapsulado.
                cout<<"Ingresado con exito \n ";
            }
            else{
                while(Ingresa_CVV != get_CVV()){        // Mientras no coincida, mandar� error y se pedir� de nuevo.
                    cout<<"El CVV no coincide, intenta de nuevo \n ";
                    cin>>Ingresa_CVV;
                }
            }
        ;}

};

#endif // DATOS_H_
