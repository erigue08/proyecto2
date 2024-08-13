#include <iostream>
#include <stdlib.h>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <fstream>
#include "proyecto.c"
using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");
	int num1, num2, num3;
    string usuario, cont, usuario_buscar, celular, correo, direccion, campo, nuevo_valor;

    while (true) {
        cout << " --------------------------- \n";
        cout << "|   Bienvenido al Sistema   |\n";
        cout << "|         de tu Banco       |\n";
        cout << "| 1.-Usuarios               |\n";
        cout << "| 2.-Actualizar o eliminar  |\n";
        cout << "|    usuario                |\n";
        cout << "| 3.-Buscar usuario         |\n";
        cout << "| 4.-Salir                  |\n";
        cout << " --------------------------- \n";
        cin >> num1;
        pantalla();

        switch (num1) {
            case 1:
                do {
                    cout << " --------------------------- \n";
                    cout << "|   Bienvenido al Sistema    |\n";
                    cout << "|         de tu Banco        |\n";
                    cout << "| 1.-Nuevo usuario           |\n";
                    cout << "| 2.-Ver registro de usuarios|\n";
                    cout << "| 3.-Regresar menú principal |\n";
                    cout << " --------------------------- \n";
                    cin >> num2;
                    pantalla();

                    switch (num2) {
                        case 1:
                            ingreso(usuario, cont, celular, correo, direccion);
                            guardardatos(usuario, cont, celular, correo, direccion);
                            cout << "Presione una tecla para continuar...";
                            _getch();
                            pantalla();
                            break;
                        case 2:
                            carga_user();
                            cout << "Presione una tecla para continuar...";
                            _getch();
                            pantalla();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Opción incorrecta" << endl;
                    }
                } while (num2 != 3);
                break;
            case 2:
                do {
                    cout << " ----------------------- \n";
                    cout << "| 1.-Actualizar Campo   |\n";
                    cout << "| 2.-Eliminar Campo     |\n";
                    cout << "| 3.-Regresar al menú   |\n";
                    cout << "|    principal          |\n";
                    cout << " ----------------------- \n";
                    cin >> num3;
                    pantalla();

                    switch (num3) {
                        case 1:
                            cout << "Ingrese el nombre del usuario a actualizar: \n";
                            cin >> usuario;
                            cout << "Ingrese el campo a actualizar (cedula/celular/correo/direccion): \n";
                            cin >> campo;
                            cout << "Ingrese el nuevo valor para el campo: \n";
                            cin >> nuevo_valor;
                            actualizarCampo(usuario, campo, nuevo_valor);
                            cout << "Presione una tecla para continuar...";
                            _getch();
                            pantalla();
                            break;
                        case 2:
                            cout << "Ingrese el nombre del usuario: \n";
                            cin >> usuario;
                            cout << "Ingrese el campo a eliminar (cedula/celular/correo/direccion): \n";
                            cin >> campo;
                            eliminarCampo(usuario, campo);
                            cout << "Presione una tecla para continuar...";
                            _getch();
                            pantalla();
                            break;
                        case 3:
                            break;
                        default:
                            cout << "Opción incorrecta" << endl;
                    }
                } while (num3 != 3);
                break;
            case 3:
                cout << "Ingrese el nombre de usuario a buscar: \n";
                cin >> usuario_buscar;
                buscar(usuario_buscar);
                cout << "Presione una tecla para continuar...";
                _getch();
                pantalla();
                break;
            case 4:
                cout << "Saliendo del sistema..." << endl;
                return 0;
            default:
                cout << "Opción incorrecta" << endl;
        }
    }

    return 0;
}
