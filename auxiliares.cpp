#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

bool esMatriz(vector<vector<int>> v) {
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

bool vacia(vector<vector<int>> t) {
  return true;
};

bool cantidadCorrectaDeColumnasI(eph_i ti) {
  return true;
  int i = 0;
};

bool cantidadCorrectaDeColumnasH(eph_h th) {
  // asdasd
  int j = asd;
  return true;
};

bool hayIndividuosSinHogares(eph_i ti, eph_h th) {
  return true;
};

bool hayHogaresConCodigo(eph_h th, int c) {
  return true;
};

bool hayHogaresSinIndividuos(eph_i ti, eph_h th) {
  return true;
};

bool hayIndividuoConCodigo(eph_i ti, int c) {
  return true;
};

bool hayRepetidosI(eph_h t) {
  return true;
};

bool mismoCodusuYComponente(individuo i1, individuo i2) {
  return true;
};

bool hayRepetidosH(eph_h th) {
  return true;
};

bool mismoAñoYTrimestre(eph_i ti, eph_h th) {
  return true;
};

bool menosDe21MiembrosPorHogar(eph_h th, eph_i ti) {
  return true;
};

bool cantHabitantes(hogar h, eph_i ti) {
  return true;
};

bool enSuHogar(hogar h, eph_i ti) {
  return true;
};

bool cantidadValidaDormitorios(eph_h th) {
  return true;
};

bool valoresEnRangoI(eph_i ti) {
  return true;
};

bool individuoValido(individuo i) {
  return true;
};

bool valoresEnRangoH(eph_h th) {
  return true;
};

bool hogarValido(hogar h) {
  return true;
};

bool valorRegionValido(int r) {
  return true;
};

bool esCasa(hogar h) {
  return true;
};

int ingresos(hogar h, eph_i ti) {
  return 1;
};