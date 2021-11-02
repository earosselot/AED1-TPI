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
