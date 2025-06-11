//

//

#ifndef PAQUETEEJECUTIVO_H
#define PAQUETEEJECUTIVO_H
#include "paquete.h"
#include <iostream>
using namespace std;

class PaqueteEjecutivo : public Paquete {
public:
    void mostrarBeneficios() const override {
        cout << "Asiento premium"<< endl;
        cout << "Con posibilidad de cambios"<< endl;
        cout << "1 Equipaje de mano"<< endl;
        cout << "1 Equipaje documentado"<< endl;

    }

    int calcularPrecioFinal(int base) const override {
        return base + 500;
    }
    int calcularPrecioFinal(int base, string cupon) const override {
        if (cupon == "COD10") {
            return calcularPrecioFinal(base) * 0.90;  // descuento
        } else {
            return calcularPrecioFinal(base);
        }
    }
};

#endif //PAQUETEEJECUTIVO_H
