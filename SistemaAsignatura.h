#ifndef SISTEMAASIGNATURAS_H
#define SISTEMAASIGNATURAS_H

#include "Asignatura.h"

class SistemaAsignaturas {
private:
    Asignatura* asignaturas;
    int cantidad;
    int capacidad;

    void redimensionar();

public:
    SistemaAsignaturas();
    ~SistemaAsignaturas();

    void agregarAsignatura(const Asignatura& a);
    bool eliminarAsignatura(int codigo);
    Asignatura* buscarAsignatura(int codigo);
    void buscarPorSemestre(int semestre);
    bool inscribirEstudiante(int codigo, string rut);
    void listarAsignaturasInscritas(string rut);
    int consultarCreditos(string rut);
};

#endif
