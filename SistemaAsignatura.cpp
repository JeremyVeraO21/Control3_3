#include "SistemaAsignatura.h"
#include <iostream>
using namespace std;

SistemaAsignaturas::SistemaAsignaturas() {
    capacidad = 10;
    cantidad = 0;
    asignaturas = new Asignatura[capacidad];
}

SistemaAsignaturas::~SistemaAsignaturas() {
    delete[] asignaturas;
}

void SistemaAsignaturas::redimensionar() {
    capacidad *= 2;
    Asignatura* nuevo = new Asignatura[capacidad];
    for (int i = 0; i < cantidad; i++) {
        nuevo[i] = asignaturas[i];
    }
    delete[] asignaturas;
    asignaturas = nuevo;
}

void SistemaAsignaturas::agregarAsignatura(const Asignatura& a) {
    if (cantidad == capacidad)
        redimensionar();
    asignaturas[cantidad] = a;
    cantidad++;
}

bool SistemaAsignaturas::eliminarAsignatura(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (asignaturas[i].codigo == codigo && asignaturas[i].inscritos == 0) {
            for (int j = i; j < cantidad - 1; j++) {
                asignaturas[j] = asignaturas[j + 1];
            }
            cantidad--;
            return true;
        }
    }
    return false;
}

Asignatura* SistemaAsignaturas::buscarAsignatura(int codigo) {
    for (int i = 0; i < cantidad; i++) {
        if (asignaturas[i].codigo == codigo)
            return &asignaturas[i];
    }
    return nullptr;
}

void SistemaAsignaturas::buscarPorSemestre(int semestre) {
    cout << "Asignaturas del semestre " << semestre << ":" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (asignaturas[i].codigo / 100 == semestre) {
            cout << "Codigo: " << asignaturas[i].codigo << ", Titulo: " << asignaturas[i].titulo << ", Instructor: " << asignaturas[i].instructor << ", Cupos: " << asignaturas[i].cupos << ", Inscritos: " << asignaturas[i].inscritos << ", Creditos: " << asignaturas[i].creditos << endl;
        }
    }
}

bool SistemaAsignaturas::inscribirEstudiante(int codigo, string rut) {
    Asignatura* a = buscarAsignatura(codigo);
    if (a && a->tieneCupos()) {
        a->inscribirEstudiante(rut);
        return true;
    }
    return false;
}

void SistemaAsignaturas::listarAsignaturasInscritas(string rut) {
    cout << "Asignaturas inscritas por " << rut << ":" << endl;
    for (int i = 0; i < cantidad; i++) {
        if (asignaturas[i].estaInscrito(rut)) {
            cout << "- " << asignaturas[i].titulo << endl;
        }
    }
}

int SistemaAsignaturas::consultarCreditos(string rut) {
    int total = 0;
    for (int i = 0; i < cantidad; i++) {
        if (asignaturas[i].estaInscrito(rut)) {
            total += asignaturas[i].creditos;
        }
    }
    return total;
}
