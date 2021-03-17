#include <iostream>
#include <vector>
using namespace std;
void SangNguyenTo(int &n)
{
	bool nt[n+1];
	nt[n+1] = true;
	nt[0] = false;
	nt[1] = false;
	for( int i=2; i<= n;i++)
		nt[i]= true;
	for( int i=2 ; i<= n;i++)
		for( int j= 2*i; j<= n;j += i)
			nt[j]= false;
	int l=0,i=2,k=0,len=0;
	while( i <= n)
	{
		while(nt[i] == false)   // 2 3 4 5 6 7 8  9 10
		{
			i++;
			l++;
		}
		if( l > len)
		{
			len =l;
			k=i-1;
		}
		while( nt[i] == true)
			i++;
		l=0;	
	}
	for( int i=k; i > k-len ; i--)
		cout << i <<" ";
	return;
}
int main()
{
	int n;
	cin >> n;
	SangNguyenTo(n);	
	return 0;
}
