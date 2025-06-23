#include <iostream>
#include "SistemaAsignatura.h"
using namespace std;

int main() {
    SistemaAsignaturas sistema;

    int opcion;

    do {
        cout << "\n=========== MENU ===========\n";
        cout << "1. Buscar asignaturas por semestre\n";
        cout << "2. Inscribir estudiante en asignatura\n";
        cout << "3. Listar asignaturas inscritas de un estudiante\n";
        cout << "4. Consultar total de creditos inscritos de un estudiante\n";
        cout << "5. Ingresar nueva asignatura\n";
        cout << "6. Eliminar asignatura\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            int semestre;
            cout << "Ingrese el semestre: ";
            cin >> semestre;
            sistema.buscarPorSemestre(semestre);
        } else if (opcion == 2) {
            int codigo;
            string rut;
            cout << "Ingrese el codigo de la asignatura: ";
            cin >> codigo;
            cout << "Ingrese el RUT del estudiante: ";
            cin >> rut;
            if (sistema.inscribirEstudiante(codigo, rut)) {
                cout << "Estudiante inscrito correctamente.\n";
            } else {
                cout << "No se pudo inscribir. Puede que no existan cupos o el codigo sea incorrecto.\n";
            }
        } else if (opcion == 3) {
            string rut;
            cout << "Ingrese el RUT del estudiante: ";
            cin >> rut;
            sistema.listarAsignaturasInscritas(rut);
        } else if (opcion == 4) {
            string rut;
            cout << "Ingrese el RUT del estudiante: ";
            cin >> rut;
            int total = sistema.consultarCreditos(rut);
            cout << "Total de creditos inscritos: " << total << endl;
        } else if (opcion == 5) {
            string titulo, instructor;
            int codigo, cupos, creditos;
            cout << "Ingrese el titulo de la asignatura: ";
            cin.ignore(); // Limpiar buffer
            getline(cin, titulo);
            cout << "Ingrese el codigo de la asignatura: ";
            cin >> codigo;
            cout << "Ingrese el nombre del instructor: ";
            cin.ignore();
            getline(cin, instructor);
            cout << "Ingrese la cantidad de cupos: ";
            cin >> cupos;
            cout << "Ingrese la cantidad de creditos: ";
            cin >> creditos;

            sistema.agregarAsignatura(Asignatura(titulo, codigo, instructor, cupos, creditos));
            cout << "Asignatura agregada correctamente.\n";
        } else if (opcion == 6) {
            int codigo;
            cout << "Ingrese el codigo de la asignatura a eliminar: ";
            cin >> codigo;

            if (sistema.eliminarAsignatura(codigo)) {
                cout << "Asignatura eliminada correctamente.\n";
            } else {
                cout << "No se pudo eliminar la asignatura. Puede que tenga estudiantes inscritos o no exista.\n";
            }
        } else if (opcion == 0) {
            cout << "Saliendo del sistema.\n";
        } else {
            cout << "Opcion invalida. Intente nuevamente.\n";
        }

    } while (opcion != 0);

    return 0;
}
