#include <iostream>
#include "matrixdouble.h"

using namespace std;
int main()
{
    Matrix A(4,4),A_diag(4,5), B(4,1), X(4,1), C, Xtrans, Ctrans, E;
    E.ones(4);
    A.set(0,0,0.42);    A.set(1,0,0.26);    A.set(2,0,0.33);    A.set(3,0,-0.22);
    A.set(0,1,0.74);    A.set(1,1,-0.55);   A.set(2,1,0.28);    A.set(3,1,-0.65);
    A.set(0,2,0.88);    A.set(1,2,0.42);    A.set(2,2,-0.33);   A.set(3,2,0.75);
    A.set(0,3,0.92);    A.set(1,3,0.82);    A.set(2,3,-0.62);   A.set(3,3,0.75);

    B.set(0,0,1);       B.set(1,0,1);       B.set(2,0,1);       B.set(3,0,0);
    A_diag = A.GaussDown(B);
    X = A_diag.GaussUp();
    cout << "X:\n";
    X.Show();
    cout << "Check(A * X):\n";
    (A * X).Show();
    cout << "C = X * X(trans):\n";
    A = ~X;
    C = X * A;
    C.Show();
    cout << "C * Ctrans = \n";
    X = ~C;
    A_diag = C * X;
    A_diag.Show();
    cout << "Ctrans * C = \n";
    A_diag = X * C;
    A_diag.Show();
    if (A_diag == E)
        cout << "They are ortogonal!\n";
    else 
        cout << "They aren't ortogonal!\n";
    return 0;
}