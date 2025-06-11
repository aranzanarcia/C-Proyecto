//
//

#include <iostream>
#include <vector>
using namespace std;

class Vuelo {
private:
    string numeroVuelo;
    string aerolinea;
    string fecha;
    int asientosDisponibles;
    int precio;
    int duracionVuelo;
public:
    Vuelo(string nV, string al, string fe, int aD, int p, int dV){
        numeroVuelo = nV;
        aerolinea = al;
        fecha = fe;
        asientosDisponibles = aD;
        precio = p;
        duracionVuelo = dV;
    }

    void mostrarInfo(){
        cout << "El numero de vuelo es: " << numeroVuelo << endl;
        cout << "La aerolinea es: " << aerolinea << endl;
        cout << "La fecha del vuelo es " << fecha << endl;
        cout << "La cantidad de asientos disponibles es: " << asientosDisponibles << endl;
        cout << "El precio de un asiento es: " << precio << " pesos "<< endl;
        cout << "La duracion del vuelo es: " << duracionVuelo << " horas " << endl;
    }

    string determinarFecha(){
        string dia = fecha.substr(0, 2);
        string mes = fecha.substr(3, 2);
        string anio = fecha.substr(6, 4);

        cout << "Dia: " << dia << "\n";
        cout << "Mes: " << mes << "\n";
        cout << "Anio: " << anio << "\n";

        return fecha;
    }


    void asientosReservados(int numPasajeros){
        asientosDisponibles = asientosDisponibles - numPasajeros;
    }

    void asientosCancelados(int numPasajeros){
        asientosDisponibles = asientosDisponibles + numPasajeros;
    }

    string getAerolinea(){
        return aerolinea;
    }

    string getNvuelo(){
        return numeroVuelo;
    }

    int getAsientosDisponibles(){
        return asientosDisponibles;
    }

    string getDia(){
        string dia = fecha.substr(0, 2);
        return dia;
    }

    string getMes(){
        string mes = fecha.substr(3, 2);
        return mes;
    }

    string getAnio(){
        string anio = fecha.substr(6, 4);
        return anio;
    }

    string getNumVuelos(){
        return numeroVuelo;
    }

    string getFecha() {
        return fecha;
    }

    int getPrecio() {
        return precio;
    }
};
