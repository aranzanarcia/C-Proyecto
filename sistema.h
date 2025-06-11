//

#ifndef SISTEMA_H
#define SISTEMA_H


#include <iostream>
#include <string>
#include "usuario1.h"
using namespace std;

class Sistema : public Usuario {
public:
    Sistema(string n, string i) : Usuario(n, i) {}

    void registrarUsuario(Usuario& usuario, string nombre, string ID) {
        usuario.setNombre(nombre);//set
        usuario.setID(ID);
        cout << "Usuario registrado en el sistema: " << nombreUsuario << endl;
    }
    void mostrarInfo(string nombre, string ID) {
        cout << "Nombre: " << nombre
             << ", ID / contraseña: " << ID
             << ", Estado: " << (disponible ? "Usuario Registrado" : "Usuario inexistente") << endl;
    }
    void ingresar(Usuario& usuario) {
        if (usuario.estaDisponible()) {
            cout << "Ha ingresado exitosamente: " << nombreUsuario << endl;
        } else {
            cout << "Usuario no disponible\n";
        }
    }
private:
};
#endif