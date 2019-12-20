#include <iostream>
#include <iomanip>
#include <cmath>
#define EPS 0.000001


using namespace std;
class Matrix
{
    private:
        double **Matr;
        size_t m;
        size_t n;
 
        void Create()
        {
            Matr = new double*[m];
            for (size_t z=0; z<m; z++)
                Matr[z] = new double[n];
        }
 
    public:
        Matrix(): m(5), n(5) { Create(); }
        Matrix(size_t i): m(i), n(i) { Create(); }
        Matrix(size_t i, size_t j): m(i), n(j) { Create(); }
        // ~Matrix()
        // {
        //     for(size_t i = 0; i < n; i++)
        //         delete Matr[i];
        //     delete[] Matr;
        // }
        double get(size_t i, size_t j)
        {
            return Matr[i][j];
        }

        void set(size_t i, size_t j, double x)
        {
            Matr[i][j] = x;
        }
 
        Matrix operator*(double x)
        {
            Matrix ans(m,n);
            for(size_t i=0; i<m; i++)
                for(size_t j=0; j<n; j++)
                    ans.Matr[i][j] = Matr[i][j] * x;
            return ans;
        }
 
        void Show()
        {
            for(size_t i = 0; i < m; i++)
            {
                for(size_t j=0; j < n; j++)
                {
                    cout.width(12);
                    if(fabs(Matr[i][j]) > EPS)  cout << Matr[i][j];
                        else cout << 0;
                }
                cout << endl;
            }
        }
        Matrix operator*(Matrix &rv)
        {
            if(n != rv.m) return *this;
            Matrix ans(m,rv.n);
            size_t i,j,k;
            for (i = 0; i < m; i++)
                for (j = 0; j < rv.n; j++)
                    for(ans.Matr[i][j] = k = 0; k < n; k++)
                        ans.Matr[i][j] += Matr[i][k] * rv.Matr[k][j];
            return ans;
        }

        Matrix operator~()
        {
            Matrix ans(n,m);
            for (size_t i = 0; i < m; i++)
                for (size_t j = 0; j < n; j++) 
                {
                    ans.Matr[j][i] = Matr[i][j];
                }
            return ans;
        }

        Matrix operator+(Matrix &rv)
        {
            if(m != rv.m || n != rv.n) return *this;
            Matrix ans(m, n);
            for (size_t i = 0; i < m; i++)
                for (size_t j = 0; j < n; j++) ans.Matr[i][j] = Matr[i][j] + rv.Matr[i][j];
            return ans;
        }
        Matrix operator-(Matrix &rv)
        {
            if(m != rv.m || n != rv.n) return *this;
            Matrix ans(m, n);
            for (size_t i = 0; i < m; i++)
                for (size_t j = 0; j < n; j++) ans.Matr[i][j] = Matr[i][j] - rv.Matr[i][j];
            return ans;
        }
        Matrix operator-()
        {
            return (*this) * (-1);
        }
        // Matrix& operator+=(Matrix &rv)
        // {
        //     Matrix ans = *this + rv;
        //     return ans;
        // }
        // Matrix& operator-=(Matrix &rv)
        // {
        //     Matrix ans = *this - rv;
        //     return ans;
        // }
        void random(double a, double b)
        {
            srand((unsigned int)time(NULL));
            for(size_t i = 0; i < m; i++)
                for (size_t j = 0; j < n; j++) 
                    Matr[i][j] = (rand() % (int)(2. * b + 1)) + a;
            cout << "Random:\n";
            (*this).Show();
        }
        void input()
        {
            Matrix ans(m,n);
            cout << "Enter ( " << m << "; " << n <<" ) matrix:\n";
            for (size_t i = 0; i < m; i++)
            {
                cout << '|';
                for (size_t j = 0; j < n; j++) cin >> ans.Matr[i][j];
                cout << endl;
            }
            cout << "Result:\n";
            ans.Show();
            (*this) = ans;
        }
        // Matrix GaussDown(Matrix B)
        // {
        //     if (B.n != 1) B = ~B;
        //     Matrix A(n,n + 1);
        //     for(size_t i = 0; i < n; i++)
        //     {
        //         A.Matr[i][n] = B.Matr[i][0];
        //         for(size_t j = 0; j < n; j++)
        //             A.Matr[i][j] = Matr[i][j];
        //     }
        //     for (size_t i = 0; i < n; i++)
        //     {
        //         double temp = A.Matr[i][i];
        //         for (size_t j = n; j >= i; j--)
        //             A.Matr[i][j] /= temp;
        //         for (size_t j = i + 1; j < n; j++)
        //         {
        //             temp = A.Matr[i][j];
        //             for (size_t k = n; k >= i; k--)
        //                 A.Matr[j][k] -= temp * A.Matr[i][k];
        //         }
        //     }
            
        //     return A;
        // }
        Matrix GaussDown(Matrix B)
        {
            if (B.n != 1) B = ~B;
            Matrix A(n,n + 1);
            for(size_t i = 0; i < n; i++)
            {
                A.Matr[i][n] = B.Matr[i][0];
                for(size_t j = 0; j < n; j++)
                    A.Matr[i][j] = Matr[i][j];
            }
            
            size_t i, j, k, r;
            double max, c, M;
            for(k = 0; k < n; k++)
            {
                max = fabs(A.Matr[k][k]);
                r = k;
                for(i = k + 1; i < n; i++)
                    if (fabs(A.Matr[i][k]) > max)
                        {
                        max = fabs(A.Matr[i][k]);
                        r=i;        
                        }
                for(j = 0; j <= n; j++)
                    {
                        c = A.Matr[k][j];
                        A.Matr[k][j] = A.Matr[r][j];
                        A.Matr[r][j] = c;
                    }
                for(i = k + 1; i < n; i++)
                    {
                    for(M = A.Matr[i][k] / A.Matr[k][k], j = k; j < n; j++)
                        A.Matr[i][j] -= M * A.Matr[k][j];
                    A.Matr[i][n] -= M * A.Matr[k][n];
                    }
                }
            return A;
        }
        Matrix GaussUp()
        {
            Matrix X(m, 1);
            size_t i, j;
            double s;
            for(i = m - 1; i >= 0; i--)
            {
                for(s = 0, j = i + 1; j < m; j++)
                    s += Matr[i][j] * X.Matr[j][0];
                X.Matr[i][0] = (Matr[i][m] - s) / Matr[i][i];
                if(i == 0) break;
            }
            return X;
        }
        bool operator==(Matrix rv)
        {
            if(m != rv.m || n != rv.n) return false;
            for (size_t i = 0; i < m; i++)
            {
                cout << "ping\n";
                for (size_t j = 0; j < n; j++)
                {
                    if(Matr[i][j] != rv.Matr[i][j]) return false;
                }
            }
            return true;
        }
        void ones(size_t n)
        {
            *this = Matrix(n,n);
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if(i == j) Matr[i][j] = 1;
                    else Matr[i][j] = 0;
                }
                
            }
            
        }
};