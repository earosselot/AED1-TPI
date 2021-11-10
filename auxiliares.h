#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida(const eph_h &th, const eph_i &ti); // ok

bool esCasa(const hogar &h);  // OK

int ingresos(const hogar &h, const eph_i &ti);  // OK

float ProporcionHCDeCasasPorRegion(const eph_i &ti, const eph_h &th, int region); // OK

hogar buscarHogarPorCodusu(const eph_h &th, int codusu);  // OK

int cantidadMaximaDeHabitacionesEnRegion(const eph_h &th, int region); // OK

float distanciaEuclidiana(const hogar &h, pair<int, int> centro);  // OK

float proporcionTeleworking(const eph_h &th, const eph_i &ti);  // OK

bool tieneCasaChica(const hogar &h, const eph_i &ti);  // OK

void swap(vector<vector<int>> &th, int i, int j); // OK

#endif //SOLUCION_AUXILIARES_H
