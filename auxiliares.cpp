#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"


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
