#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;
void pantalla() {
    system("cls");
}

void ingreso(string& nombre, string& cedula, string& celular, string& correo, string& direccion) {
    cout << "Ingrese el nombre del usuario: \n";
    getline(cin >> ws, nombre);
    cout << "Ingrese la cedula del usuario: \n";
    getline(cin >> ws, cedula);
    cout << "Ingrese el número celular: \n";
    getline(cin >> ws, celular);
    cout << "Ingrese el correo del usuario: \n";
    getline(cin >> ws, correo);
    cout << "Ingrese la dirección: \n";
    getline(cin >> ws, direccion);
}

void guardardatos(const string& usuario, const string& cedula, const string& celular, const string& correo, const string& direccion) {
    ofstream archivo("fil1.csv", ios::app);
    if (archivo.is_open()) {
        archivo << usuario << ";" << cedula << ";" << celular << ";" << correo << ";" << direccion << ";\n";
        archivo.close();
        cout << "Los datos han sido guardados\n\n";
    } else {
        cout << "Error al abrir el archivo\n";
    }
}

void carga_user() {
    string linea;
    ifstream archivo("fil1.csv");
    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            size_t pos = 0;
            string usuario, cedula, celular, correo, direccion;

            pos = linea.find(';');
            usuario = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            cedula = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            celular = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            correo = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            direccion = linea.substr(0, pos);

            cout << "Usuario: " << usuario << " | Cédula: " << cedula << " | Celular: " << celular 
                 << " | Correo: " << correo << " | Dirección: " << direccion << "\n";
        }
        archivo.close();
    } else {
        cout << "No se pueden cargar los datos del archivo correctamente.\n";
    }
}

void eliminarCampo(const string& usuario, const string& campo) {
    ifstream fs("fil1.csv");
    ofstream fstream("file1t.csv");
    bool bandera = false;

    if (!fs || !fstream) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    string linea;
    while (getline(fs, linea)) {
        size_t pos = linea.find(';');
        string usuario_actual = linea.substr(0, pos);

        if (usuario_actual == usuario) {
            bandera = true;

            // Extraer campos
            string cedula, celular, correo, direccion;

            linea.erase(0, pos + 1);
            pos = linea.find(';');
            cedula = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            celular = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            correo = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            direccion = linea.substr(0, pos);

            // Eliminar el campo deseado
            if (campo == "cedula") cedula = "";
            else if (campo == "celular") celular = "";
            else if (campo == "correo") correo = "";
            else if (campo == "direccion") direccion = "";

            // Guardar la línea modificada
            fstream << usuario_actual << ";" << cedula << ";" << celular << ";" << correo << ";" << direccion << ";\n";
        } else {
            fstream << linea << "\n";
        }
    }

    fs.close();
    fstream.close();
    remove("fil1.csv");
    rename("file1t.csv", "fil1.csv");

    if (bandera) {
        cout << "El campo ha sido eliminado correctamente.\n";
    } else {
        cout << "No se encontró el usuario.\n";
    }
}

void actualizarCampo(const string& usuario, const string& campo, const string& nuevo_valor) {
    ifstream fs("fil1.csv");
    ofstream fstream("file1t.csv");
    bool bandera = false;

    if (!fs || !fstream) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    string linea;
    while (getline(fs, linea)) {
        size_t pos = linea.find(';');
        string usuario_actual = linea.substr(0, pos);

        if (usuario_actual == usuario) {
            bandera = true;

            // Extraer campos
            string cedula, celular, correo, direccion;

            linea.erase(0, pos + 1);
            pos = linea.find(';');
            cedula = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            celular = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            correo = linea.substr(0, pos);
            linea.erase(0, pos + 1);

            pos = linea.find(';');
            direccion = linea.substr(0, pos);

            // Actualizar el campo deseado
            if (campo == "cedula") cedula = nuevo_valor;
            else if (campo == "celular") celular = nuevo_valor;
            else if (campo == "correo") correo = nuevo_valor;
            else if (campo == "direccion") direccion = nuevo_valor;

            // Guardar la línea modificada
            fstream << usuario_actual << ";" << cedula << ";" << celular << ";" << correo << ";" << direccion << ";\n";
        } else {
            fstream << linea << "\n";
        }
    }

    fs.close();
    fstream.close();
    remove("fil1.csv");
    rename("file1t.csv", "fil1.csv");

    if (bandera) {
        cout << "El campo ha sido actualizado correctamente.\n";
    } else {
        cout << "No se encontró el usuario.\n";
    }
}

void buscar(const string& usuario_buscar) {
    ifstream archivo("fil1.csv");
    string linea;
    bool encontrado = false;

    if (archivo.is_open()) {
        while (getline(archivo, linea)) {
            size_t pos = linea.find(';');
            string usuario = linea.substr(0, pos);

            if (usuario == usuario_buscar) {
                cout << "Usuario encontrado: " << linea << endl;
                encontrado = true;
                break;
            }
        }
        archivo.close();

        if (!encontrado) {
            cout << "Usuario no encontrado." << endl;
        }
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}



