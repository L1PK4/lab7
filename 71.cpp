#include <iostream>
#include "matrix.h"
#include <cmath>
#define raz(a) ((int)log10(abs(a)) + 1)

/*
В двумерном массиве A, состоящем из n×n целых чисел 
вычислить:
    •наименьшее абсолютное значение элементов;
    •произведение   ненулевых   элементов,   расположенного
    в   заштрихованнойчасти матрицы (рис. 6.25)
.Сформировать новую матрицу  B(n×n), каждый элемент которой 
равен разрядусоответствующего элемента матрицы  А(n×n). 
Для матриц  А(n×n)  найти значе-ние выраженияC=BT⋅A.
*/


using namespace std;
int main()
{
    size_t n;
    cout << "Enter n =";
    cin>> n;
    Matrix A(n,n),B(n,n),C(n,n);
    long int product = 1;
    // A.input();
    A.random(-10,10);
    long int min = A.get(0,0);
    for(size_t i = 0; i < n; i++)
        for(size_t j = 0;j < n; j++)
        {
            if(A.get(i,j) < min) min = A.get(i,j);
            if(i > j && (i + j <= n) && A.get(i,j)) product *= A.get(i,j);
            B.set(i,j, raz((A.get(i,j))?A.get(i,j):1));
        }    
    C = (~B) * A;
    cout << "Min = " << min << "\nProduct = " << product << endl;
    cout << "B:\n";
    B.Show();
    cout << "C:\n";
    C.Show();
    return 0;
}