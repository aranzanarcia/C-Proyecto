//María Guadalupe Méndez
//Fernando Pérez
//Aranza
#include <iostream>
#include <string>
#include <limits>
#include <vector>

#include "usuario1.h"
#include "sistema.h"
#include "Vuelo.h"
#include "paquete.h"
#include "paqueteEconomico.h"
#include "paqueteEjecutivo.h"
#include "paquetePremium.h"
using namespace std;


int main() {
	Vuelo vuelo1("1","AeroJet","11 de Septiembre 2001",40,2000,2);
	Vuelo vuelo2("2","VistaAir","30 de Febrero 2024",30,1500,6);
	Vuelo vuelo3("3", "SkyFly", "15 de Marzo 2024", 50, 1800, 3);
	Vuelo vuelo4("4", "BlueAir", "10 de Abril 2024", 40, 2200, 4);
	Vuelo vuelo5("5", "AeroJet", "25 de Mayo 2024", 35, 2500, 5);
	Vuelo vuelo6("6", "BlueAir", "1 de Junio 2024", 45, 2000, 2);
	Vuelo vuelo7("7", "VistaAir", "20 de Julio 2024", 60, 1900, 3);
	Vuelo vuelo8("8", "FlyFast", "30 de Agosto 2024", 55, 2100, 4);
	Vuelo vuelo9("9", "FlyFast", "5 de Septiembre 2024", 50, 2300, 5);
	Vuelo vuelo10("10", "FlyFast", "15 de Octubre 2024", 65, 2400, 6);
	vuelo1.asientosReservados(30);
	vuelo2.asientosReservados(20);
	vuelo1.asientosCancelados(5);
	vuelo2.asientosCancelados(3);
	int disponibles1=vuelo1.getAsientosDisponibles();
	int disponibles2=vuelo2.getAsientosDisponibles();

	vector<Vuelo> vuelos;
	vector<Vuelo> reservados;
	vuelos.push_back(vuelo1);
	vuelos.push_back(vuelo2);



	int opcion;


	//iniciar registro
	vector<Usuario> usuarios;
	string nombreUsuario, ID;
	cout << "Ingrese su nombre de Usuario: ";
	getline(cin, nombreUsuario);
	cout << "Ingrese su ID / contraseña: ";
	getline(cin, ID);
	Usuario nuevoUsuario(nombreUsuario,ID);
	Sistema sistema(nombreUsuario,ID);
	sistema.registrarUsuario(nuevoUsuario,nuevoUsuario.nombreUsuario, nuevoUsuario.ID);
	sistema.mostrarInfo(nuevoUsuario.nombreUsuario, nuevoUsuario.ID);
	usuarios.push_back(nuevoUsuario);

	if (usuarios.empty()) {
		cout << "No ha registrado ningun usuario registrado para inicio de sesion";
	} else {
		cout << "\nSeleccione una de sus cuentas\n";
		for (size_t i = 0; i < usuarios.size(); ++i) {
			cout << i + 1 << ". ";
			usuarios[i].mostrarInfo();
		}
		int seleccion;
		cout << "Ingrese el numero de cuenta: ";
		cin >> seleccion;
		if (seleccion > 0 && seleccion <= static_cast<int>(usuarios.size())) {
			string contra;
			bool acceso = false;
			while (!acceso) {
				cout << "Ingrese la contraseña / ID para esta cuenta: ";
				cin>>contra;
				if (contra == usuarios[seleccion - 1].ID) {
					sistema.ingresar(usuarios[seleccion - 1]);
					acceso = true;
				} else {
					cout << "Contraseña incorrecta " << endl;
				}
			}

		}else {
			cout << "Usuario no disponible." << endl;
		}
	}

	cout<<"|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|"<<endl;
	cout<<endl;
	cout<<"Bienvenido al sistema 'ViajandoAndo' el sistema de reservacion de vuelos mas confiable del mundo ;)"<<endl;
	cout<<endl;
	cout<<"A continuacion se le muestran las diferentes opciones con las que cuenta el sistema :D"<<endl;

	while(opcion!=7){

		cout<<"~~~~~~~~~~| Por favor seleccione una opcion |~~~~~~~~~~~~~~~"<<endl;
		cout<<"1) Hacer reservacion de vuelo"<<endl;
		cout<<"2) Mostrar vuelos disponibles"<<endl;
		cout<<"3) Reservar vuelo en base a fecha"<<endl;
		cout<<"4) Mostrar detalles de vuelo reservado"<<endl;
		cout<<"5) Cancelar reservacion"<<endl;
		cout<<"6) Registrar nuevo usuario"<<endl;
		cout<<"7) Salir"<<endl;

		cout<<"Opcion: ";

		while (!(cin >> opcion)) {
			cout << "Tipo de dato erroneo, favor de introducir numeros: ";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		switch(opcion){

			case 1:{

				int opcion1 = 0;
				int reserva;
				cout<<"A continuacion se mostraran sus datos"<<endl;
				nuevoUsuario.mostrarInfo();
				cout<<endl;
				cout<<endl;
				cout<<"Seleccione un numero de vuelo para obtener informacion de este"<<endl;

				while(opcion1 == 0){
					for (size_t i = 0; i <vuelos.size(); ++i) {
						cout <<"|~~~~~~~~~~~~~~~~~~|"<<endl;
						cout<<"Vuelo "<< i + 1 <<". "<<"Numero de vuelo: " << vuelos[i].getNvuelo() << endl;
					}
					cout<<"Numero de vuelo ";
					cin>>reserva;
					cout<<endl;

					if (reserva > 0 && reserva <= static_cast<int>(vuelos.size())) {
						cout<<"|~~~~~~~~~~~~~~~~~~~~|"<<endl;
						cout<<"Datos del vuelo seleccionado:"<<endl;
						vuelos[reserva-1].mostrarInfo();



						// POLIMORFISMO
						cout << "\n Seleccione el tipo de paquete:"<<endl;
						cout << "1) Económico"<<endl;
                        cout << "2) Ejecutivo"<<endl;
                        cout << "3) Premium"<<endl;
						int tipoPaquete;
						cin >> tipoPaquete;

						Paquete* paquete = nullptr;
						switch (tipoPaquete) {
							case 1:
								paquete = new PaqueteEconomico();
							break;
							case 2:
								paquete = new PaqueteEjecutivo();
							break;
							case 3:
								paquete = new PaquetePremium();
							break;
							default:
								cout << "Opcion no valida. Se usara el paquete económico."<< endl;
							paquete = new PaqueteEconomico();
							break;
						}

						cout << "Beneficios del paquete seleccionado:"<< endl;
						paquete->mostrarBeneficios();

						int precioBase = vuelos[reserva - 1].getPrecio();

						string cupon;
						cout <<"\n ¿Tiene algun cupon de descuento? (Ingrese el codigo o ingrese NA si no tiene): ";
						cin>>cupon;

						int precioFinal;
						if (cupon=="COD10") {
							precioFinal = paquete->calcularPrecioFinal(precioBase, cupon);
						} else {
							precioFinal = paquete->calcularPrecioFinal(precioBase);
						}

						cout << "Precio base del vuelo: $" << precioBase << endl;
						cout << "Precio total: $" << precioFinal << endl;

						delete paquete;

						// FIN POLIMORFISMO Y SOBRECARGA




						cout<<"Esta de acuerdo con su vuelo? '0' para rechazar, '1' para aceptar ";
						cin>>opcion1;

						if(opcion1==1){
							reservados.push_back(vuelos[reserva-1]);
							cout<<"Vuelo reservado correctamente"<<endl<<endl;
						}
					} else {
						cout <<"Numero de vuelo invalido.";
					}
				}
				break;
			}

			case 2:{

				cout<<"~~~~~~~~~~~~~~~||~~~~~~~~~~~~~~~~~~~||~~~~~~~~~~~~"<<endl;
				cout<<"A continuacion se muestran los vuelos disponibles"<<endl;
				for (size_t i = 0; i <vuelos.size(); ++i) {
					cout <<"|~~~~~~~~~~~~~~~~~~|"<<endl<<"Vuelo "<< i + 1 << ". "<<endl<<endl;
					vuelos[i].mostrarInfo();
				}

				cout<<endl<<endl;
				break;
			}

			case 3: {
				string fechaBuscada;
				cout << "Ingrese la fecha del vuelo en formato (dd mm aaaa): ";
				cin.ignore();
				getline(cin, fechaBuscada);

				vector<Vuelo> vuelosFechas;

				for (size_t i = 0; i < vuelos.size(); ++i) {
					if (vuelos[i].getFecha() == fechaBuscada) {
						if (vuelos[i].getFecha() == fechaBuscada) {
							vuelosFechas.push_back(vuelos[i]);
						}
					}
					if (!vuelosFechas.empty()) {
						cout << "\nVuelos disponibles para la fecha " << fechaBuscada << ":\n";
						for (size_t i = 0; i < vuelosFechas.size(); ++i) {
							cout << "Vuelo " << i + 1 << ": " << endl;
							vuelosFechas[i].mostrarInfo();
							cout << "|~~~~~~~~~~~~~~~~~~|" << endl;
						}
					} else {
						cout << "No se encontraron vuelos disponibles para la fecha " << fechaBuscada << "." << endl;
					}
					break;
				}
			}
				case 4:{
				if (reservados.empty()) {
					cout << "No tiene vuelos reservados" << endl;
				} else {
					cout << "Vuelos reservados: " << endl;
					for (size_t i = 0; i < reservados.size(); ++i) {
						cout << i + 1 << ". Número de vuelo: " << reservados[i].getNvuelo() << ", Aerolinea: " << reservados[i].getAerolinea() << endl;
					}

					int opcionReserva;
					cout << "\nSeleccione el número del vuelo para ver los detalles, 0 para regresar al menuº ";
					cin >> opcionReserva;

					if (opcionReserva > 0 && opcionReserva <= static_cast<int>(reservados.size())) {
						cout << "Detalles del vuelo" << endl;
						reservados[opcionReserva - 1].mostrarInfo();
					} else if (opcionReserva == 0) {} else {
						cout << "Valor incorrecto" << endl;
					}
				}
				break;
			}
			case 5:{
				if (reservados.empty()) {
					cout << "No tiene vuelos reservados" << endl;
				}
				int borrado;
				int desicion=0;
				while(true){
					cout<<"A continuacion se le muestra la lista de vuelos resevados:"<<endl;
					for (size_t i = 0; i <reservados.size(); ++i) {
						cout <<"|~~~~~~~~~~~~~~~~~~|"<<endl<<endl;
						cout<<"Reserva "<<i+1<<" ."<<endl<<endl;
						reservados[i].mostrarInfo();
					}
					cout<<"Por favor seleccione la reserva que desea cancelar";
					cin>>borrado;
					cout<<"¿Seguro que desea cancelar la reserva "<<borrado<<"? '0' para rechazar, '1' para aceptar " ;
					cin>>desicion;
					if(desicion==0){
						break;
					}
					if (desicion==1) {
						int final=borrado-1;
						reservados.erase(reservados.begin()+final);
						cout<<"Reservada cancelada correctamente"<<endl<<endl;
					} else {
						"Opción incorrecta";
					}
				}
				break;
			}
			case 6:{
				string nombreUsuario, ID;
				cout<<"|~~~~~~~~~~~~~~~~|"<<endl;
				cout<<"Registrar nuevo usuario, por favor introduzca sus datos: "<<endl<<endl;
				cout << "Ingrese su nombre de Usuario: ";
				cin.ignore();
				getline(cin, nombreUsuario);
				cout << "Ingrese su ID / contraseña: ";
				getline(cin, ID);
				Usuario nuevoUsuario(nombreUsuario,ID);
				Sistema sistema(nombreUsuario,ID);
				sistema.registrarUsuario(nuevoUsuario,nuevoUsuario.nombreUsuario, nuevoUsuario.ID);
				sistema.mostrarInfo(nuevoUsuario.nombreUsuario, nuevoUsuario.ID);
				usuarios.push_back(nuevoUsuario);
				cout<<endl;
				cout<<"nuevo usuario registrado"<<endl;
				cout<<endl;
				cout<<"Lista del registro de usuarios"<<endl;
				for (size_t i = 0; i < usuarios.size(); ++i) {
					cout << i + 1 << ". ";
					usuarios[i].mostrarInfo();
				}
			}
			case 7:{
				cout<<"Gracias por utilizar 'ViajandoAndo', ¡Vuelva pronto!";
				break;
			}

			default:
				cout<<"Opcion invalida";
		}
	}
	return 0;
}


