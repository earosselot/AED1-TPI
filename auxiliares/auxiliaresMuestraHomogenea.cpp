#include "../definiciones.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"

using namespace std;

vector<pair<int, int>> calcularIngresosPorHogar(const eph_h &th, const eph_i &ti) {
    vector<pair<int, int>> ingresosHogares(th.size());
    for (int i = 0; i < th.size(); i++) {
        ingresosHogares[i] = make_pair(ingresos(th[i], ti), i);
    }
    return ingresosHogares;
}

int findMinPosIngreso(vector<pair<int, int>> ingresosHogar, int inicio, int fin) {
    pair<int, int> ingresoMin = ingresosHogar[inicio];
    int minPos = inicio;
    for (int i = inicio; i < fin; i++) {
        if (ingresosHogar[i].first < ingresoMin.first) {
            ingresoMin = ingresosHogar[i];
            minPos = i;
        }
    }
    return minPos;
}

void swapPair(vector<pair<int, int>> &ingresosHogar, int i, int j) {
    pair<int, int> ing1 = ingresosHogar[i];
    pair<int, int> ing2 = ingresosHogar[j];
    ingresosHogar[i] = ing2;
    ingresosHogar[j] = ing1;
}

void ordenarIngresos(vector<pair<int, int>> &ingresosHogar) {
    int cantIngresos = (int) ingresosHogar.size();
    for (int i = 0; i < ingresosHogar.size(); i++) {
        int minPos = findMinPosIngreso(ingresosHogar, i, cantIngresos);
        swapPair(ingresosHogar, i, minPos);
    }
}

pair<int, int> buscarIngreso(const vector<pair<int, int>> &ingresosHogar, int ingreso) {

    pair<int, int> parIngreso = {-1, -1};
    int desde = 0;
    int hasta = (int) ingresosHogar.size();

    while (desde <= hasta) {
        int m = (desde + hasta) / 2;
        if (ingresosHogar[m].first == ingreso) {
            parIngreso = ingresosHogar[m];
        }
        if (ingreso < ingresosHogar[m].first) {
            hasta = m - 1;
        } else {
            desde = m + 1;
        }
    }
    return parIngreso;
}


bool estaElElemento(const vector<pair<int, int>> &ingresosHogar, int elem) {
    bool esta = false;
    int desde = 0;
    int hasta = (int) ingresosHogar.size();

    while (desde <= hasta) {
        int m = (desde + hasta) / 2;
        if (ingresosHogar[m].first == elem) {
            esta = true;
        }
        if (elem < ingresosHogar[m].first) {
            hasta = m - 1;
        } else {
            desde = m + 1;
        }
    }
    return esta;
}

vector<pair<int, int>> calcularMuestraIngresosMasLarga(const vector<pair<int, int>> &ingresosHogar) {
    vector<pair<int, int>> muestraMasLarga = {};
    for (int i = 0; i < ingresosHogar.size() - 1; i++) {
        for (int j = i + 1; j < ingresosHogar.size(); j++) {
            int dif = ingresosHogar[j].first - ingresosHogar[i].first;
            if (dif > 0) {
                vector<pair<int, int>> muestra = {ingresosHogar[i], ingresosHogar[j]};
                int k = 2;
                int siguiente = ingresosHogar[i].first + (dif * k);
                while (estaElElemento(ingresosHogar, siguiente)) {
                    muestra.push_back(buscarIngreso(ingresosHogar, siguiente));
                    k++;
                    siguiente = ingresosHogar[i].first + (dif * k);
                }
                if (muestra.size() > muestraMasLarga.size()) {
                    muestraMasLarga = muestra;
                }
            }
        }
    }
    return muestraMasLarga;
}

vector<hogar> extraerHogaresDeIngresos(const eph_h &th, const vector<pair<int, int>> &ingresosHogar) {
    vector<hogar> muestraHomogenea(ingresosHogar.size());
    for (int i = 0; i < ingresosHogar.size(); i++) {
        muestraHomogenea[i] = th[ingresosHogar[i].second];
    }
    return muestraHomogenea;
}

