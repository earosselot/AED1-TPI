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

bool hayHogarConCodigo(eph_h th, int c);

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

bool esCasa(hogar h);

int ingresos(hogar h, eph_i ti);

float ProporcionHCDeCasasPorRegion(eph_i ti, eph_h th, int region);

hogar buscarHogarPorCodusu(eph_h th, int codusu);

int cantidadMaximaDeHabitacionesEnRegion(eph_h th, int region);

float distanciaEuclidiana(hogar h, pair<int, int> centro);

bool trabajaEnSuVivienda(individuo ind, eph_h th);

bool individuoEnHogarValido(individuo ind, eph_h th);

int cantIndividuosTrabajandoEnSuVivienda(eph_h th, eph_i ti);

int cantIndividuosQueTrabajan(eph_h th, eph_i ti);

float proporcionTeleworking(eph_h th, eph_i ti);

bool tieneCasaChica(hogar h, eph_i ti);

void swap(vector<vector<int>> &th, int i, int j);

int findMinPosHogar(const eph_h &th, int inicio, int fin, eph_i ti);

bool esMenorHogarIngresos(const hogar &h1, const hogar &h2, eph_i ti);

void ordenarTh(eph_h &th, eph_i ti);

vector<hogar> HogaresConMismDiferencia(eph_h th, eph_i ti);

int LaDiferenciaQueMasHogaresTienenEntreSi(vector<int> IngHog);

vector<int> DevolverIngresosHogares(eph_h th, eph_i ti);

void Ordenar(vector<int> IngHog);

int HogarMaximoIngreso(vector<int> IngHog);

int HogarMinIngreso(vector<int> IngHog);

bool AlMenos3ConIngresosConMismaDiferencia(eph_h th, eph_i ti);

bool esMuestraDeHogares(eph_h th, eph_i ti);

bool existeSolucionMuestraHomogeneaConAlMenos3(eph_h th, eph_i ti);

#endif //SOLUCION_AUXILIARES_H
