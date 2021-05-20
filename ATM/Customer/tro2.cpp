#include <iostream>
using namespace std;
void Nhap( int &m, int&n, char**p )
{
for( int i=0 ; i < m;i++)
		{
			for( int j=0; j< n ;j++)
				{
					cin >> *(*(p+i)+j);
				}
		}
		for( int i=0 ; i < m;i++)
		{
			for( int j=0; j< n ;j++)
				{
					cout <<  *(*(p+i)+j) <<" ";
				}
				cout << endl;
		}	
}
int main()
{
    int m,n;
    cin >> m >> n;
   
	Nhap(m,n,p);
    return 0;
}
