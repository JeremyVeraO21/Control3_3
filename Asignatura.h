#ifndef ASIGNATURA_H
#define ASIGNATURA_H

#include <string>
using namespace std;

struct Asignatura {
    string titulo;
    int codigo;
    string instructor;
    int cupos;
    int creditos;
    int inscritos;
    string* estudiantes;

    Asignatura();
    Asignatura(string t, int c, string inst, int cp, int cr);
    ~Asignatura();
    bool tieneCupos() const;
    void inscribirEstudiante(string rut);
    bool estaInscrito(string rut) const;
};

#endif
