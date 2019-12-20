#include <iostream>
#include "matrix.h"
#include <cmath>
#define count(a) ((int)log10(abs(a)) + 1)

bool isPrime(long int a)
{
    a = abs(a);
    if (a % 2 == 0 || a == 1) return false;
    if ( a == 2) return true;
    for(int i = 3; i < a / 2; i+= 2)
        if(a % i == 0) return false;
    return true;
} 

using namespace std;
int main()
{
    size_t n;
    cout << "Enter n = ";
    cin >> n;
    Matrix A(n,n);
    long double B[n];
    A.random(-100,100);
    long int max = INT64_MIN;
    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if ( (A.get(i,j) > max) && isPrime(A.get(i,j)) )max = A.get(i,j);
    
    

    for (size_t j = 0; j < n; j++)
    {
        long double prod = 1;
        for (size_t i = 0; i < n && A.get(i,j); i++) prod *= A.get(i,j);
        B[j] = pow(fabs(prod), 1./n);
    }
    
    max = count(max);
    for (size_t i = 0; i < n; i++)
    {
        size_t min = 0;
        for (size_t j = 1; j < n; j++) if(A.get(i,j) < A.get(i,min)) min = j;
        A.set(i,min,max);
    }
    
    cout << "A:\n";
    A.Show();
    cout << "\nB:\n";
    for (size_t i = 0; i < n; i++)
    {
        cout << B[i] << ' ';
    }
    cout << endl;
    return 0;
}