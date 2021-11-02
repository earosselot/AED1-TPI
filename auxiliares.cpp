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

bool esMatriz(vector<vector<int>> v) {
    int i = 0;
    int j = 0;

    while (i < v.size() - 1) {
        if (v[i].size() != v[i + 1].size()) {
            j++;
            i++;
        } else
            i++;
    }
    if (j == 0) {
        return true;
    } else
        return false;
}

bool vectoresIguales(vector<int> vec1, vector<int> vec2) {
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
        aparece = vectoresIguales(ind, ti[i]);
        i++;
    }
    return aparece;
}

bool hogarEnTabla(hogar h, eph_h th) {
    int i = 0;
    bool aparece = false;
    while (i < th.size() && !aparece) {
        aparece = vectoresIguales(h, th[i]);
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

bool cantidadCorrectaDeColumnasI(eph_i ti) {
    return ti[0].size() == FILAS_INDIVIDUO;
};

bool cantidadCorrectaDeColumnasH(eph_h th) {
    return th[0].size() == FILAS_HOGAR;
};

bool hayHogarConCodigo(eph_h th, int c) {
    int i = 0;
    bool aparece = false;
    while (i < th.size() && !aparece) {
        aparece = (th[i][HOGCODUSU] == c);
        i++;
    }
    return aparece;
};

bool hayIndividuosSinHogares(eph_i ti, eph_h th) {
    bool hayIndSinHogar = false;
    int i = 0;
    while (i < ti.size() && !hayIndSinHogar) {
        hayIndSinHogar = !hayHogarConCodigo(th, ti[i][INDCODUSU]);
        i++;
    }
    return hayIndSinHogar;
};

bool hayIndividuoConCodigo(eph_i ti, int c) {
    int i = 0;
    bool aparece = false;
    while (i < ti.size() && !aparece) {
        aparece = (ti[i][INDCODUSU] == c);
        i++;
    }
    return aparece;
};

bool hayHogaresSinIndividuos(eph_i ti, eph_h th) {
    bool hayHogarSinInd = false;
    int i = 0;
    while (i < th.size() && !hayHogarSinInd) {
        hayHogarSinInd = !hayIndividuoConCodigo(ti, th[i][HOGCODUSU]);
        i++;
    }
    return hayHogarSinInd;
};


bool mismoAñoYTrimestre(eph_i ti, eph_h th) {
    int i = 0;
    int esDistinto = 0;
    while (i < ti.size() - 1) {
        if (ti[i][INDANIO] == ti[i + 1][INDANIO] && ti[i][INDTRIMESTRE] == ti[i + 1][INDTRIMESTRE]) {
            i++;
        } else {
            esDistinto++;
            i++;
        }
    }
    int j = 0;

    while (j < th.size() - 1) {
        if (th[j][HOGANIO] == th[j + 1][HOGANIO] && th[j][HOGTRIMESTRE] == th[j + 1][HOGTRIMESTRE]) {
            j++;
        } else {
            esDistinto++;
            j++;
        }
    }
    if (esDistinto == 0) {
        return true;
    } else
        return false;

};

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti) {
    int i = 0;
    int esMayorA21 = 0;

    while (i < th.size()) {
        if (cantHabitantes(th[i], ti) < 21) {
            i++;
        } else {
            esMayorA21++;
            i++;
        }
    }
    if (esMayorA21 == 0) {
        return true;
    } else
        return false;

};

int cantHabitantes(hogar h, eph_i ti) {
    int i = 0;
    int sonHabitantes = 0;

    while (i < ti.size()) {
        if (esSuHogar(h, ti[i])) {
            sonHabitantes++;
            i++;
        } else
            i++;
    }
    return sonHabitantes;
};

bool esSuHogar(hogar h, individuo i) {
    if (h[HOGCODUSU] == i[INDCODUSU]) {
        return true;
    } else
        return false;
};

bool cantidadValidaDormitorios(eph_h th) {
    int i = 0;
    int noSonValidos = 0;

    while (i < th.size()) {
        if (th[i][IV2] >= th[i][II2]) {
            i++;
        } else {
            noSonValidos++;
            i++;
        }
    }
    if (noSonValidos == 0) {
        return true;
    } else
        return false;
};


bool individuoValido(individuo i) {
    bool valido = true;
    valido &= 0 < i[INDCODUSU];
    valido &= 0 < i[COMPONENTE];
    valido &= 0 < i[INDTRIMESTRE] && i[INDTRIMESTRE] <= 4;
    valido &= 0 < i[CH4] && i[CH4] <= 2;
    valido &= 0 <= i[CH6];
    valido &= (i[NIVEL_ED] == 0 || i[NIVEL_ED] == 1);
    valido &= -1 <= i[ESTADO] && i[ESTADO] <= 1;
    valido &= 0 <= i[CAT_OCUP] && i[CAT_OCUP] <= 4;
    valido &= (0 <= i[p47T] || i[p47T] == -1);
    valido &= 0 <= i[PP04G] && i[PP04G] <= 10;
    return valido;
};

bool valoresEnRangoI(eph_i ti) {
    bool valoresEnRango = true;
    int i = 0;
    while (i < ti.size() && valoresEnRango) {
        valoresEnRango = individuoValido(ti[i]);
        i++;
    }
    return valoresEnRango;
};

bool hogarValido(hogar h) {
    bool valido = true;
    valido &= 0 <= h[HOGCODUSU];
    valido &= 0 < h[HOGTRIMESTRE] & h[HOGTRIMESTRE] <= 4;
    valido &= 0 < h[II7] && h[II7] <= 3;
    valido &= (h[REGION] == 1 || (40 <= h[REGION] && h[REGION] <= 44));
    valido &= (h[MAS_500] == 0 || h[MAS_500] == 1);
    valido &= 0 < h[IV1] && h[IV1] <= 5;
    valido &= 0 < h[IV2];
    valido &= 1 <= h[II2];
    valido &= (h[II3] == 1 || h[II3] == 2);
    return valido;
};

bool valoresEnRangoH(eph_h th) {
    bool valoresEnRango = true;
    int i = 0;
    while (i < th.size() && valoresEnRango) {
        valoresEnRango = hogarValido(th[i]);
        i++;
    }
    return valoresEnRango;
};

bool esCasa(hogar h) {
    return h[IV1] == 1;
};

int ingresos(hogar h, eph_i ti) {
    int i = 0;
    int sumaIngresos = 0;

    while (i < ti.size()) {
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > -1) {
            sumaIngresos = sumaIngresos + ti[i][p47T];
            i++;
        } else
            i++;
    }
    return sumaIngresos;
};

bool esValida(eph_h th, eph_i ti) {
    bool valido = true;

    valido &= esMatriz(th);
    valido &= esMatriz(ti);
    valido &= !vacia(th);
    valido &= !vacia(ti);
    valido &= cantidadCorrectaDeColumnasH(th);
    valido &= cantidadCorrectaDeColumnasI(ti);
    valido &= !hayIndividuosSinHogares(th, ti);
    valido &= !hayHogaresSinIndividuos(th, ti);
    valido &= hayRepetidosH(th);
    valido &= hayRepetidosI(ti);
    valido &= mismoAñoYTrimestre(th, ti);
    valido &= menosDe21MiembrosPorHogar(th, ti);
    valido &= cantidadValidaDormitorios(th);
    valido &= valoresEnRangoH(th);
    valido &= valoresEnRangoI(ti);

    return valido;
};

int cantidadMaximaDeHabitacionesEnRegion(eph_h th, int region) {
    int maxCantHabitaciones = -1;
    for (int i = 1; i < th.size(); i++) {
        if (th[i][IV2] > maxCantHabitaciones && esCasa(th[i]) && th[i][REGION] == region) {
            maxCantHabitaciones = th[i][IV2];
        }
    }
    return maxCantHabitaciones;
};

hogar buscarHogarPorCodusu(eph_h th, int codusu) {
    int i = 0;
    hogar resultado;
    while (i < th.size()) {
        if (th[i][HOGCODUSU] == codusu)
            resultado = th[i];
        i++;
    }
    return resultado;
}