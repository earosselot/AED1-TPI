#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"
#include "./auxiliares/auxiliaresOrdenar.h"

using namespace std;

// Implementacion Problema 1
bool esEncuestaValida(eph_h th, eph_i ti) {

    return esValida(th, ti);
}

// Implementacion Problema 2
vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    int i = 0;
    vector<int> histograma(cantidadMaximaDeHabitacionesEnRegion(th, region));

    while (i < th.size()) {
        if (esCasa(th[i]) && th[i][REGION] == region) {
            histograma[th[i][IV2] - 1]++;
            i++;
        } else
            i++;
    }
    return histograma;
}

// Implementacion Problema 3
vector<pair<int, float>> laCasaEstaQuedandoChica(eph_h th, eph_i ti) {
    vector<int> regiones = {1, 40, 41, 42, 43, 44};
    vector<pair<int, float>> res;
    pair<int, float> pair1;
    for (int i = 0; i < regiones.size(); i++) {
        pair1.first = regiones[i];
        pair1.second = ProporcionHCDeCasasPorRegion(ti, th, regiones[i]);
        res.push_back(pair1);
    }
    return res;
}

// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes(eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i) {
    bool resp = false;

    // TODO

    return resp;
}

// Implementacion Problema 5
int costoSubsidioMejora(eph_h th, eph_i ti, int monto) {
    int resp = -1;

    // TODO

    return resp;
}

// Implementacion Problema 6
// vector< pair<hogar, individuo> > join_hi
join_hi generarJoin(eph_h th, eph_i ti) {
    join_hi join;
    par_hi par;
    for (int i = 0; i < ti.size(); i++) {
        par.first = buscarHogarPorCodusu(th, ti[i][INDCODUSU]);
        par.second = ti[i];
        join.push_back(par);
    }
    return join;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU(eph_h &th, eph_i &ti) {

    ordenarTh(th);
    ordenarTi(ti, th);

}

// Implementacion Problema 8
vector<hogar> muestraHomogenea(eph_h &th, eph_i &ti) {
    hogar h = {};
    vector<hogar> resp = {h};

    // TODO

    return resp;
}

// Implementacion Problema 9
void corregirRegion(eph_h &th, eph_i ti) {

    int i = 0;

    while (i < th.size()) {
        if (th[i][REGION] == 1) {
            th[i][REGION] = 43;
        }
        i++;
    }
    return;
}

// Implementacion Problema 10
vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias) {
    int i = 0;
    vector<int> hogaresPorRegion(distancias.size());

    while (i < th.size()) {
        int j = 0;
        while (j < hogaresPorRegion.size()) {
            if (distanciaEuclidiana(th[i], centro) < distancias[j]) {
                hogaresPorRegion[j]++;
            }
            j++;
        }
        i++;
    }
    return hogaresPorRegion;
}

// Implementacion Problema 11
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    pair<eph_h, eph_i> resp = make_pair(rth, rti);

    // TODO

    return resp;
}
