#include "../definiciones.h"
#include "../auxiliares.h"
#include "gtest/gtest.h"


//void swap(vector<vector<int>> &th, int i, int j) {
//    hogar h1 = th[i];
//    hogar h2 = th[j];
//    th[i] = h2;
//    th[j] = h1;
//}

bool esMenorHogar(const hogar &h1, const hogar &h2) {
    // Devuelve true si el primero es menor
    if (h1[REGION] < h2[REGION]) {
        return true;
    } else if (h1[REGION] > h2[REGION]) {
        return false;
    } else {
        if (h1[HOGCODUSU] < h2[HOGCODUSU]) {
            return true;
        } else {
            return false;
        }
    }
}

int findMinPosHogar(const eph_h &th, int inicio, int fin) {
    hogar hogarMin = th[inicio];
    int minPos = inicio;
    for (int i = inicio; i < fin; i++) {
        if (esMenorHogar(th[i], hogarMin)) {
            hogarMin = th[i];
            minPos = i;
        }
    }
    return minPos;
}

void ordenarTh(eph_h &th) {
    if (th.size() > 0) {
        int cantHogares = th.size();
        for (int i = 0; i < th.size(); i++) {
            int minPos = findMinPosHogar(th, i, cantHogares);
            swap(th, i, minPos);
        }
    }
}

int buscarPosHogarEnTh(const eph_h &th, int codusu) {
    int i = 0;
    while (i < th.size() && th[i][HOGCODUSU] != codusu) {
        i++;
    }
    if (i == th.size())
        return -1;
    return i;
}

bool esMenorIndividuo(const eph_h &th, const individuo &ind1, const individuo &ind2) {
    // Devuelve true si el primer individuo es menor
    int posInd1enTh = buscarPosHogarEnTh(th, ind1[INDCODUSU]);
    int posInd2enTh = buscarPosHogarEnTh(th, ind2[INDCODUSU]);
    bool esMenor = true;
    if (posInd1enTh < posInd2enTh) {
        esMenor = true;
    } else if (posInd1enTh > posInd2enTh) {
        esMenor = false;
    } else {
        if (ind1[COMPONENTE] < ind2[COMPONENTE]) {
            esMenor = true;
        } else {
            esMenor = false;
        }
    }
    return esMenor;
}


int findMinPosIndividuo(const eph_i &ti, const eph_h &th, int inicio, int fin) {
    hogar individuoMin = ti[inicio];
    int minPos = inicio;
    for (int i = inicio; i < fin; i++) {
        if (esMenorIndividuo(th, ti[i], individuoMin)) {
            individuoMin = ti[i];
            minPos = i;
        }
    }
    return minPos;
}

void ordenarTi(eph_i &ti, const eph_h &th) {
    if (ti.size() > 0 && th.size() > 0) {
        int cantIndividuos = ti.size();
        for (int i = 0; i < ti.size(); i++) {
            int minPos = findMinPosIndividuo(ti, th, i, cantIndividuos);
            swap(ti, i, minPos);
        }
    }
}
