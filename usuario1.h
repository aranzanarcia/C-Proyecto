//
//

#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
using namespace std;

class Usuario{
public:
    string nombreUsuario;
    string ID;
    bool disponible;

public:
    // Constructor
    Usuario(string n = "", string i = "") : nombreUsuario(n), ID(i), disponible(true) {}
    // MÃ©todos
    void setNombre(string n) { nombreUsuario = n; }
    void setID(string i) { ID = i; }
    void mostrarInfo() {
        cout << "Nombre: " << nombreUsuario
             << ", ID: " << ID
             << ", Estado: " << (disponible ? "Disponible" : "Acceso Concedido") << endl;
    }

    bool estaDisponible() { return disponible; }
    ~Usuario(){}
};
#endif