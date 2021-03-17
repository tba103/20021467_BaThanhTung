#include <iostream>
using namespace std;
bool check( int a[], int b[], int n)
{
	for( int i=0; i< n;i++)
	{
		for( int j=i+1; j<n;j++)
		{
			if((a[i] == b[j]) && (b[i] == a[j])) return true;
			if((a[i]==a[j]) || (b[i] == b[j])) return true;
			if( (a[i]+b[j]== n-1) && ( a[j]+b[i]==n-1)) return true;
		}
	}
	return false;
}
int main()
{
	int n;
	cin >> n;
	int a[n],b[n];
	for( int i=0; i< n;i++)
		cin >> a[i] >> b[i];
	cout << boolalpha << check(a,b,n);
	return 0;
}
