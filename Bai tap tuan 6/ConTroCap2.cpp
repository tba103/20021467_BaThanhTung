#include <iostream>
#include <stdlib.h>
using namespace std;
int main()
{
	int m,n;
	cin >> m >> n;
	int **p = new int*[m];
	for( int i=0 ; i< m; i++)
	{
		*(p+i) = new int[n];
	}
	for( int i=0; i < m; i++)
		for( int j=0; j <n; j++)
			p[i][j] = rand() % 100;
	cout << &p[2][3] << endl;
	cout << p[2] +3  << endl;
	cout << *(p+2) +3 << endl;
	cout << p[1][2] << endl;
	cout << *(p[1] +2) << endl;
	cout << *(*(p+1) +2) << endl;				 
	return 0;
}
