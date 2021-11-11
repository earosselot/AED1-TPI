#include "../definiciones.h"

#ifndef TPI_AUXILIARESMUESTRAHOMOGENEA_H
#define TPI_AUXILIARESMUESTRAHOMOGENEA_H

vector<pair<int, int>> calcularIngresosPorHogar(const eph_h &th, const eph_i &ti);

void ordenarIngresos(vector<pair<int, int>> &ingresosHogar);

vector<pair<int, int>> calcularMuestraIngresosMasLarga(const vector<pair<int, int>> &ingresosHogar);

vector<hogar> extraerHogaresDeIngresos(const eph_h &th, const vector<pair<int, int>> &ingresosHogar);

#endif //TPI_AUXILIARESMUESTRAHOMOGENEA_H
