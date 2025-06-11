//

//

#ifndef PAQUETEPREMIUM_H
#define PAQUETEPREMIUM_H
#include "paquete.h"
#include <iostream>
using namespace std;

class PaquetePremium : public Paquete {
public:
    void mostrarBeneficios() const override {
        cout << "Primera clase"<< endl;
        cout << "Comida gourmet"<< endl;
        cout << "Acceso a salon VIP en aeropuerto"<< endl;
        cout << "Con cambios"<< endl;
        cout << "2 equipajes de mano"<< endl;
        cout << "2 equipajes documentados"<< endl;
    }

    int calcularPrecioFinal(int base) const override {
        return base + 1000;
    }
    int calcularPrecioFinal(int base, string cupon) const override {
        if (cupon == "COD10") {
            return calcularPrecioFinal(base) * 0.90;  // descuento
        } else {
            return calcularPrecioFinal(base);
        }
    }
};

#endif //PAQUETEPREMIUM_H