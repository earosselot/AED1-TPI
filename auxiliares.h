#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida(eph_h th, eph_i ti);

bool esMatriz(vector<vector<int>> t);

bool individuoEnTabla(individuo ind, eph_i ti);

bool hogarEnTabla(hogar h, eph_h th);

bool vacia(vector<vector<int>> t);

bool cantidadCorrectaDeColumnasI(eph_i ti);

bool cantidadCorrectaDeColumnasH(eph_h th);

bool hayIndividuosSinHogares(eph_i ti, eph_h th);

bool hayHogaresConCodigo(eph_h th, int c);

bool hayHogaresSinIndividuos(eph_i ti, eph_h th);

bool hayIndividuoConCodigo(eph_i ti, int c);

bool hayRepetidosI(eph_h t);

bool mismoCodusuYComponente(individuo i1, individuo i2);

bool hayRepetidosH(eph_h th);

bool mismoAñoYTrimestre(eph_i ti, eph_h th);

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti);

int cantHabitantes(hogar h, eph_i ti);

bool esSuHogar(hogar h, individuo i);

bool cantidadValidaDormitorios(eph_h th);

bool valoresEnRangoI(eph_i ti);

bool individuoValido(individuo i);

bool valoresEnRangoH(eph_h th);

bool hogarValido(hogar h);

bool valorRegionValido(int r);

bool esCasa(hogar h);

int ingresos(hogar h, eph_i ti);

#endif //SOLUCION_AUXILIARES_H
