#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

bool vacia(vector<vector<int>> t) {
    bool res = false;
    if (t.size() == 0) {
        res = true;
    }
    return res;
}

bool esMatriz(vector<vector<int> > v) {
    int i = 0;
    int j = 0;

    while (i < v.size() - 1) {
        if (v[i].size() != v[i + 1].size()) {
            j = j + 1;
            i = i + 1;
        } else
            i = i + 1;
    }
    if (j == 0) {
        return true;
    } else
        return false;
}

==0){
res = true;
}
return
res;
}


}


bool vectoresiguales(vector<int> vec1, vector<int> vec2) {
    bool iguales = true;
    int i = 0;
    while (i < vec1.size() && iguales) {
        iguales = vec1[i] == vec2[i];
        i++;
    }
    return iguales;
}

bool individuoEnTabla(individuo ind, eph_i ti) {
    int i = 0;
    bool aparece = false;
    while (i < ti.size() && !aparece) {
        aparece = vectoresiguales(ind, ti[i]);
        i++;
    }
    return aparece;
}

bool hogarEnTabla(hogar h, eph_h th) {
    int i = 0;
    bool aparece = false;
    while (i < th.size() && !aparece) {
        aparece = vectoresiguales(h, th[i]);
        i++;
    }
    return aparece;
}

bool mismoCodusuYComponente(individuo i1, individuo i2) {
    bool res = false;
    if (i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE]) {
        res = true;
    }
    return res;
}

bool hayRepetidosI(eph_i ti) {
    int n1 = 0;
    int n2 = 0;
    bool res = false;
    for (int i = 0; i < ti.size(); i++) {
        if (n1 != n2 && mismoCodusuYComponente(ti[n1], ti[n2])) {
            res = true;
        }
    }
    return res;
}

bool hayRepetidosH(eph_h th) {

    int n1 = 0;
    int n2 = 0;
    bool res = false;
    for (int i = 0; i < th.size(); i++) {
        if (n1 != n2 && th[n1][HOGCODUSU] == th[n2][HOGCODUSU]) {
            res = true;
        }
    }
    return res;
}