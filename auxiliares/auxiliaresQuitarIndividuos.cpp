#include "../definiciones.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"
#include "../ejercicios.h"


vector<individuo> individuosEnHogar(int codusu, eph_i &ti) {
    vector<individuo> individuosEnHogar;
    for (auto &ind: ti) {
        if (ind[INDCODUSU] == codusu) {
            individuosEnHogar.push_back(ind);
        }
    }
    return individuosEnHogar;
}

bool cumpleConBusqueda(individuo ind, const vector<pair<int, dato>> &busqueda) {
    bool cumpleConBusqueda = true;
    int i = 0;
    while (i < busqueda.size() && cumpleConBusqueda) {
        cumpleConBusqueda &= (ind[busqueda[i].first] == busqueda[i].second);
        i++;
    }
    return cumpleConBusqueda;
}