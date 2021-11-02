#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

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
