#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool mismoAñoYTrimestre(eph_i ti, eph_h th);

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti);

bool cantHabitantes(hogar h, eph_i ti);

bool enSuHogar(hogar h, eph_i ti);

bool cantidadValidaDormitorios(eph_h th);

bool valoresEnRangoI(eph_i ti);

bool individuoValido(individuo i);

bool valoresEnRangoH(eph_h th);

bool hogarValido(hogar h);

bool valorRegionValido(int r);

bool esCasa(hogar h);

int ingresos(hogar h, eph_i ti);

#endif //SOLUCION_AUXILIARES_H
