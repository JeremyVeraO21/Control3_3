#include "Asignatura.h"

Asignatura::Asignatura() {
    codigo = 0;
    cupos = 0;
    creditos = 0;
    inscritos = 0;
    estudiantes = nullptr;
}

Asignatura::Asignatura(string t, int c, string inst, int cp, int cr) {
    titulo = t;
    codigo = c;
    instructor = inst;
    cupos = cp;
    creditos = cr;
    inscritos = 0;
    estudiantes = new string[cupos];
}

Asignatura::~Asignatura() {
    delete[] estudiantes;
}

bool Asignatura::tieneCupos() const {
    return inscritos < cupos;
}

void Asignatura::inscribirEstudiante(string rut) {
    if (tieneCupos()) {
        estudiantes[inscritos] = rut;
        inscritos++;
    }
}

bool Asignatura::estaInscrito(string rut) const {
    for (int i = 0; i < inscritos; i++) {
        if (estudiantes[i] == rut)
            return true;
    }
    return false;
}
