//
//

#ifndef PAQUETE_H
#define PAQUETE_H

#include <iostream>
using namespace std;

class Paquete {
public:
    virtual void mostrarBeneficios() const = 0;
    virtual int calcularPrecioFinal(int base) const = 0;
    virtual int calcularPrecioFinal(int base, string cupon) const = 0;

    virtual ~Paquete() {}
};

#endif