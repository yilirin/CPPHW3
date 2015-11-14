////  main.cpp//  Matrix////  Created by 范志方 on 15/11/12.//  Copyright © 2015年 范志方. All rights reserved.//#include <assert.h>#include <iostream>#include "Vector.h"#include "Matrix.h"using namespace std;int main(){    double data1[] = {3.4, 4.4, 6.0};    Vector v(sizeof(data1) / sizeof(double), data1);        for (int idx = 0; idx < sizeof(data1) / sizeof(double); ++idx)    {        assert(v[idx] == data1[idx]);          }    assert(v == v);    assert(!(v != v));    assert(v + v == v * 2);        assert(v - v == v + (-v));    assert((v = 3) == Vector(sizeof(data1) / sizeof(double), 3));        assert(v + 3 == Vector(sizeof(data1) / sizeof(double), 6));    //for (int i = 0; i < v.size(); ++i) cout << v[i]<<' ';    assert(v - 3 == Vector(sizeof(data1) / sizeof(double), 0.0));        Vector v2(10, 5);    assert(v2.size() == 10);        for (int idx = 0; idx < v2.size(); ++idx)    {        assert(v2[idx] == 5);    }        assert(v + v2 == Vector::INVALID_VECTOR);            //////////////////////////////////////////////////    double data2[] = {1, 1, 1, 1, 1, 1};    Matrix m1(3, 2, data2);    Matrix m4 = m1*2;    assert(m4.rows() == 3);    assert(m4.cols() == 2);    for (int r = 0; r < 2; ++r)    {        for (int c = 0; c < 2; ++c)        {            assert(m4[r][c] == 2);        }    }//    m1.printMatrix();//    m4.printMatrix();    Matrix m2(6, 1, data2);    Matrix m3(3, 2, data2);//    m2.printMatrix();//    m3.printMatrix();    assert(m1 != m2);    assert(m1 == m3);        assert(m1 == Matrix(3, 2, 1));        assert(m1 + m1 == Matrix(3, 2, 2));    assert(m1 + m2 == Matrix::INVALID_MATRIX);        assert(m1 - m1 == m1 + (-m1));    assert(- m1 == Matrix(3, 2, -1));        assert(m1 * m1.trans() == Matrix(3, 3, 2));    assert(m1.trans() * m1 == Matrix(2, 2, 3));    assert(Matrix(v) * m1 == Matrix(1, 2, 9));    assert(m1.trans() * Matrix(v).trans() == Matrix(2, 1, 9));    system("PAUSE");    return 0;}