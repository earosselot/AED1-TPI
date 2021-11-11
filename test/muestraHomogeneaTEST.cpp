#include "../definiciones.h"
#include "../Funciones_TPI.h"
#include "../ejercicios.h"
#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(muestraHomogeneaTEST, unaSolucionDe4) {
    vector<hogar> res = {{2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 20
                         {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 25
                         {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 30
                         {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1}}; // 35

    eph_h th = {
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},  // 0
            {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},  // 35
            {1009, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 26
            {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 27
            {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 30
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 0
            {334,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 180
            {543,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 1
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 20
            {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},  // 25
    };

    eph_i ti = {{543,  2018, 1, 1, 1, 1, 36, 1, 3, 1,  1}, // 1
                {334,  2018, 1, 1, 1, 1, 36, 1, 3, 90, 1},
                {340,  2018, 1, 1, 1, 1, 36, 1, 3, 30, 1}, // 35
                {340,  2018, 3, 1, 1, 1, 36, 1, 3, 5,  1},
                {334,  2018, 2, 1, 1, 1, 31, 1, 3, 90, 1},
                {1009, 2018, 1, 1, 1, 2, 36, 1, 3, 26, 1}, // 26
                {210,  2018, 1, 1, 1, 1, 36, 1, 1, 25, 1}, // 27
                {210,  2018, 2, 1, 1, 1, 36, 1, 3, 2,  1},
                {1,    2018, 1, 1, 1, 2, 5,  1, 2, 25, 1},  // 25
                {4377, 2018, 1, 1, 1, 1, 36, 1, 3, 15, 1}, // 30
                {4377, 2018, 3, 1, 1, 1, 7,  1, 3, 15, 1},
                {2354, 2018, 1, 1, 1, 2, 36, 1, 3, 20, 1}, // 20
                {200,  2018, 2, 1, 1, 1, 36, 1, 3, 0,  1}, // 0
                {960,  2018, 3, 1, 1, 2, 51, 1, 4, 0,  1}, // 0
                {960,  2018, 2, 1, 1, 2, 51, 1, 4, 0,  1},
                {960,  2018, 1, 1, 1, 2, 51, 1, 4, 0,  1}
    };

    EXPECT_EQ(res, muestraHomogenea(th, ti));
}


TEST(muestraHomogeneaTEST, dosSolucionesDe3) {
    vector<hogar> res1 = {{1,   2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                          {210, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                          {340, 2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1}};

    vector<hogar> res2 = {{1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                          {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
                          {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1}};

    eph_h th = {
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {1009, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {334,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {543,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {800,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
    };

    eph_i ti = {{543,  2018, 1, 1, 1, 1, 36, 1, 3, 1,  1}, // 1
                {334,  2018, 1, 1, 1, 1, 36, 1, 3, 1,  1}, // 3
                {334,  2018, 2, 1, 1, 1, 36, 1, 3, 2,  1},
                {340,  2018, 1, 1, 1, 1, 36, 1, 3, 30, 1},  // 30
                {340,  2018, 3, 1, 1, 1, 36, 1, 3, 0,  1},
                {1009, 2018, 1, 1, 1, 1, 36, 1, 3, 26, 1}, // 26
                {210,  2018, 1, 1, 1, 1, 36, 1, 3, 25, 1}, // 27
                {210,  2018, 2, 1, 1, 1, 36, 1, 3, 2,  1},
                {1,    2018, 1, 1, 1, 1, 36, 1, 3, 24, 1}, // 24
                {4377, 2018, 1, 1, 1, 1, 36, 1, 3, 15, 1}, // 30
                {4377, 2018, 3, 1, 1, 1, 36, 1, 3, 15, 1},
                {2354, 2018, 1, 1, 1, 1, 36, 1, 3, 20, 1}, // 20
                {800,  2018, 2, 1, 1, 1, 36, 1, 3, 0,  1}, // 0
                {200,  2018, 2, 1, 1, 1, 36, 1, 3, 0,  1}, // 0
                {960,  2018, 3, 1, 1, 2, 51, 1, 4, 0,  1}, // 0
                {960,  2018, 2, 1, 1, 2, 51, 1, 4, 0,  1},
                {960,  2018, 1, 1, 1, 2, 51, 1, 4, 0,  1}
    };

    vector<hogar> propuesto = muestraHomogenea(th, ti);
    bool esperado = res1 == propuesto || res2 == propuesto;
    EXPECT_EQ(true, esperado);
}

TEST(muestraHomogeneaTEST, dosSolucionesDe3UnaDe4) {
    vector<hogar> res = {
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {800,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
    };

    eph_h th = {
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {1009, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {334,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {543,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {800,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
    };

    eph_i ti = {
            {543,  2018, 1, 1, 1, 1, 36, 1, 3, 1,   1}, // 1
            {334,  2018, 1, 1, 1, 1, 36, 1, 3, 1,   1}, // 3
            {334,  2018, 2, 1, 1, 1, 36, 1, 3, 2,   1},
            {340,  2018, 1, 1, 1, 1, 36, 1, 3, 30,  1}, // 30
            {340,  2018, 3, 1, 1, 1, 36, 1, 3, 0,   1},
            {1009, 2018, 1, 1, 1, 1, 36, 1, 3, 26,  1}, // 26
            {210,  2018, 1, 1, 1, 1, 36, 1, 3, 25,  1}, // 27
            {210,  2018, 2, 1, 1, 1, 36, 1, 3, 2,   1},
            {1,    2018, 1, 1, 1, 1, 36, 1, 3, 24,  1}, // 24
            {4377, 2018, 1, 1, 1, 1, 36, 1, 3, 15,  1}, // 30
            {4377, 2018, 3, 1, 1, 1, 36, 1, 3, 15,  1},
            {2354, 2018, 1, 1, 1, 1, 36, 1, 3, 115, 1}, // 115
            {800,  2018, 2, 1, 1, 1, 36, 1, 3, 110, 1}, // 110
            {200,  2018, 2, 1, 1, 1, 36, 1, 3, 105, 1}, // 105
            {960,  2018, 3, 1, 1, 2, 51, 1, 4, 100, 1}, // 120
            {960,  2018, 2, 1, 1, 2, 51, 1, 4, 15,  1},
            {960,  2018, 1, 1, 1, 2, 51, 1, 4, 5,   1},
    };

    EXPECT_EQ(res, muestraHomogenea(th, ti));
}

TEST(muestraHomogeneaTEST, muestraDe2) {
    vector<hogar> res = {};

    eph_h th = {
            {960,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {340,  2018, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1},
            {1009, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {210,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {4377, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {200,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {334,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {543,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {2354, 2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {1,    2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
            {800,  2018, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1},
    };

    eph_i ti = {
            {543,  2018, 1, 1, 1, 1, 36, 1, 3, 1,   1}, // 1
            {334,  2018, 1, 1, 1, 1, 36, 1, 3, 1,   1}, // 3
            {334,  2018, 2, 1, 1, 1, 36, 1, 3, 2,   1},
            {340,  2018, 1, 1, 1, 1, 36, 1, 3, 27,  1}, // 27
            {340,  2018, 3, 1, 1, 1, 36, 1, 3, 0,   1},
            {1009, 2018, 1, 1, 1, 1, 36, 1, 3, 26,  1}, // 26
            {210,  2018, 1, 1, 1, 1, 36, 1, 3, 25,  1}, // 27
            {210,  2018, 2, 1, 1, 1, 36, 1, 3, 2,   1},
            {1,    2018, 1, 1, 1, 1, 36, 1, 3, 24,  1}, // 24
            {4377, 2018, 1, 1, 1, 1, 36, 1, 3, 18,  1}, // 33
            {4377, 2018, 3, 1, 1, 1, 36, 1, 3, 15,  1},
            {2354, 2018, 1, 1, 1, 1, 36, 1, 3, 101, 1}, // 101
            {800,  2018, 2, 1, 1, 1, 36, 1, 3, 110, 1}, // 110
            {200,  2018, 2, 1, 1, 1, 36, 1, 3, 105, 1}, // 105
            {960,  2018, 3, 1, 1, 2, 51, 1, 4, 101, 1}, // 120
            {960,  2018, 2, 1, 1, 2, 51, 1, 4, 15,  1},
            {960,  2018, 1, 1, 1, 2, 51, 1, 4, 5,   1},
    };

    EXPECT_EQ(res, muestraHomogenea(th, ti));
}

//
//{
//0, 5, 8, 22, 10}
//
//0
//-5   0
//-8  -3   0
//-22 -17 -14   0
//-10  -5  -2 -12  0
//
//{
//5, 6, 3, 8, 1, 3, 7}
//
//0
//-1  0
//2  3  0
//-3 -2 -5  0
//4  5  2  7  0
//2  3  0  5 -2  0
//-2 -1 -4  1 -6 -4  0
//
//{
//5, 6, 3, 8, 1, 3, 7}
//{
//1, 3, 3, 5, 6, 7, 8}
//
//0
//2  0
//2  0  0
//4  2  2  0
//5  3  3  1  0
//6  4  4  2  1  0
//7  5  5  3  2  1  0
//
//{
//1, 3, 5, 6, 7, 8}
//
//
//0
//2  0
//4  2  0
//5  3  1  0
//6  4  2  1  0
//7  5  3  2  1  0
//
//
//{5, 6, 3, 8, 1, 3, 7}
//
//// caso 3 repetido resolver
//{{-1, {0, 1}}, {2, {0, 2}}, {-3, {0, 3}}, {4, {0, 4}}, {-2, {0, 6}}}
//{{3, {1, 2}}, {-2, {1, 3}}, {5, {1, 4}}, {-1, {1, 6}}}
//{{-5, {2, 3}}, {2, {2, 4}}, {-4, {2, 6}}}
//{{7, {3, 4}}, {1, {3, 6}}}
//{{-6, {4, 6}}}
//
//{2, {0, 2}}
//{2, {2, 4}}
//{-2, {0, 6}}


