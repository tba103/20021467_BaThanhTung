#include <iostream>
#include <cmath>
using namespace std;
void increase( int A[], int n)
{
    A[n-1]++;
    for( int i= n-1; i > 0 ; i--)
        {
            if( A[i] > 1)
            {
                A[i-1]++;
                A[i] -= 2;
            }
        }
}

void  Xuat( int A[], int m, int n)
{
    int k=0;
    for( int i=0 ; i < m+n; i++)
        k+= A[i];
    if ( n == k)
    for( int i=0 ; i< m+n; i ++)
        {
            cout << A[i];
            cout << endl;
        }
}
int main()
{
    int m,n;
    cin >> m >> n;
    int*A = new int[m+n];
    for( int i=0 ; i < m+n; i ++) A[i]=0;
    for( int i= 0 ; i< pow(2,(m+n)); i++)
        {
            Xuat(A,m,n);
            increase(A,m+n);
        }
    return 0;
}
