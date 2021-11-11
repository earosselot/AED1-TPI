#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"
#include "./auxiliares/auxiliaresOrdenar.h"
#include "./auxiliares/auxiliaresQuitarIndividuos.h"
#include "./auxiliares/auxiliaresMuestraHomogenea.h"

using namespace std;

// Implementacion Problema 1
bool esEncuestaValida(eph_h th, eph_i ti) {

    return esValida(th, ti);
}

// Implementacion Problema 2
vector<int> histHabitacional(eph_h th, eph_i ti, int region) {
    int largoDeHistograma = cantidadMaximaDeHabitacionesEnRegion(th, region);
    vector<int> histograma;
    if (largoDeHistograma == -1 || largoDeHistograma == 0) {
        histograma = {};
    } else {

        int i = 0;
        histograma.resize(largoDeHistograma);
        while (i < th.size()) {
            if (esCasa(th[i]) && th[i][REGION] == region) {
                histograma[th[i][IV2] - 1]++;
                i++;
            } else
                i++;
        }
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
    if (proporcionTeleworking(t2h, t2i) > proporcionTeleworking(t1h, t1i)) {
        resp = true;
    }
    return resp;
}

// Implementacion Problema 5
int costoSubsidioMejora(eph_h th, eph_i ti, int monto) {
    int resp = 0;
    for (int i = 0; i < th.size(); i++) {
        if ((th[i][II7] == 1) && tieneCasaChica(th[i], ti)) {
            resp = resp + monto;
        }
    }
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

    vector<pair<int, int>> ingresosHogar = calcularIngresosPorHogar(th, ti); // (ingreso, indiceDelHogarEnTh)
    ordenarIngresos(ingresosHogar);

    vector<pair<int, int>> muestraIngresosMasLarga = calcularMuestraIngresosMasLarga(ingresosHogar);

    if (muestraIngresosMasLarga.size() >= 3) {
        vector<hogar> muestraHomogenea = extraerHogaresDeIngresos(th, muestraIngresosMasLarga);

        return muestraHomogenea;
    }
    return {};
}

// Implementacion Problema 9
void corregirRegion(eph_h &th, eph_i ti) {

    int i = 0;

    while (i < th.size()) {
        if (th[i][REGION] == GBA) {
            th[i][REGION] = PAMPEANA;
        }
        i++;
    }

}

// Implementacion Problema 10
vector<int> histogramaDeAnillosConcentricos(eph_h th, eph_i ti, pair<int, int> centro, vector<int> distancias) {
    int i = 0;
    vector<int> hogaresPorRegion(distancias.size());

    while (i < th.size()) {
        int j = 0;
        while (j < distancias.size()) {
            float distanciaAlCentro = distanciaEuclidiana(th[i], centro);
            if (distanciaAlCentro <= distancias[j] && distanciaAlCentro > 0) {
                hogaresPorRegion[j]++;
                j = distancias.size();
            } else
                j++;
        }
        i++;
    }
    return hogaresPorRegion;
}

// Implementacion Problema 11
pair<eph_h, eph_i> quitarIndividuos(eph_i &ti, eph_h &th, vector<pair<int, dato>> busqueda) {
    // los ind filtrados estan en ti o en result
    // los hogares pueden estar repetidos en th y en result
    pair<eph_h, eph_i> filtrados;
    eph_h thNuevo;
    eph_i tiNuevo;

    for (int i = 0; i < th.size(); i++) {
        vector<individuo> indEnHogar = individuosEnHogar(th[i][HOGCODUSU], ti);
        bool todosLosIndDelHogarCumplen = true;
        bool unIndDelHogarCumple = false;
        for (int j = 0; j < indEnHogar.size(); j++) {
            if (cumpleConBusqueda(indEnHogar[j], busqueda)) {
                filtrados.second.push_back(indEnHogar[j]);
                unIndDelHogarCumple = true;
            } else {
                tiNuevo.push_back(indEnHogar[j]);
                todosLosIndDelHogarCumplen = false;
            }
        }
        if (todosLosIndDelHogarCumplen) {
            filtrados.first.push_back(th[i]);
        } else if (unIndDelHogarCumple) {
            filtrados.first.push_back(th[i]);
            thNuevo.push_back(th[i]);
        } else {
            thNuevo.push_back(th[i]);
        }
    }

    th = thNuevo;
    ti = tiNuevo;

    return filtrados;
}
