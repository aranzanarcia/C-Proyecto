//

//

#ifndef PAQUETEECONOMICO_H
#define PAQUETEECONOMICO_H
#include "paquete.h"
#include <iostream>
using namespace std;

class PaqueteEconomico : public Paquete {
public:
    void mostrarBeneficios() const override {
        cout << "Asiento estándar"<< endl;
        cout << "Sin cambios"<< endl;
        cout << "1 Equipaje de mano"<< endl;
        cout << "0 Equipaje documentado"<<endl;
    }

    int calcularPrecioFinal(int base) const override {
        return base;
    }
    int calcularPrecioFinal(int base, string cupon) const override {
        if (cupon == "COD10") {
            return base * 0.90;  // descuento
        } else {
            return calcularPrecioFinal(base);
        }
    }
};

#endif
