#include <iostream>



using namespace std;
class Matrix
{
    private:
        long int **Matr;
        size_t m;
        size_t n;
 
        void Create()
        {
            Matr = new long int*[m];
            for (size_t z=0; z<m; z++)
                Matr[z] = new long int[n];
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
        long int get(size_t i, size_t j)
        {
            return Matr[i][j];
        }

        void set(size_t i, size_t j, long int x)
        {
            Matr[i][j] = x;
        }
 
        Matrix operator*(long int x)
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
                for(size_t j = 0; j < n; j++)
                {
                    cout.width(5);
                    cout << Matr[i][j];
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
        
        void ones(size_t n)
        {
            *this = Matrix(n);
            for (size_t i = 0; i < n; i++)
            {
                for (size_t j = 0; j < n; j++)
                {
                    if(i == j) Matr[i][j] = 1;
                    else Matr[i][j] = 0;
                }
                
            }
            
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
        void random(long int a, long int b)
        {
            srand((unsigned int)time(NULL));
            for(size_t i = 0; i < m; i++)
                for (size_t j = 0; j < n; j++) 
                    Matr[i][j] = (rand() % (2 * b + 1)) + a;
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
};