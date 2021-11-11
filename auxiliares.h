#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"

bool esValida(const eph_h &th, const eph_i &ti);

bool esCasa(const hogar &h);

int ingresos(const hogar &h, const eph_i &ti);

float ProporcionHCDeCasasPorRegion(const eph_i &ti, const eph_h &th, int region);

hogar buscarHogarPorCodusu(const eph_h &th, int codusu);

int cantidadMaximaDeHabitacionesEnRegion(const eph_h &th, int region);

float distanciaEuclidiana(const hogar &h, pair<int, int> centro);

float proporcionTeleworking(const eph_h &th, const eph_i &ti);

bool tieneCasaChica(const hogar &h, const eph_i &ti);

void swap(vector<vector<int>> &th, int i, int j);

#endif //SOLUCION_AUXILIARES_H
