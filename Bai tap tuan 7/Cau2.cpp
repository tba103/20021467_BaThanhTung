#include <iostream>
using namespace std;

struct BigInteger
{
  int sign;
  string number;
};
string summation( string a, string b)
{	
	string res="";
	int k=0;
	char *p = &a[a.size()-1];
	cout << p << endl;
	char *q=  &b[b.size()-1];
	cout << q << endl;
	while( p >= a && q >= b)
	{
		if( (*p -'0' + *q -'0')>= 10)
		{
			char x = (*p-'0'+*q-'0' -10 +k) + '0';
			res = x + res;
			cerr << "Lan 1 :" << res << endl;
			k=1;
		}
		else 
		{
			char x = *p-'0'+*q-'0' +'0';
			x += k;
			res = x + res;
			cerr << "Lan 2 :" << res << endl;
			k=0;
		}
		*p--;
		*q--;
	}
	while( p>= a)
	{
		res  = (*p) + res;
		*p--;
		cerr << "lan 3 :" << res << endl;

	}
	while ( q>= b)
	{
		res = (*q ) + res;
		*q--; 
		cerr << "lan 4 :" << res << endl;
	}
	return res;
}
int main()
{
	string a,b;
	cin >> a >> b;
	cout << summation(a,b);
	return 0;
}
void subtraction()
{
	
}
BigInteger sum( BigInteger first, BigInteger second)
{
	
}



















/*
struct Person
{
	double height;
	double weight;
	Person( double _height, double _weight)
	{
		_height = height;
		_weight = weight;
	}
	Person()
	{
	}
	void GetInf()
	{
		cin >> height >> weight;
	}
};
struct Fraction
{
  int numerator, denominator;
};
Fraction reduceFrac ( Fraction frac)
{
    int n= ( frac.numerator > frac.denominator ? frac.numerator : frac.denominator);
    for( int i=2 ; i < n; i++)
        {
            while( frac.numerator %i ==0 && frac.denominator %i==0)
            {
                frac.numerator /= i;
                frac.denominator /= i;
            }
        }
    return frac;
}

double getBMI (Person person)
{
    double h= person.height * person.height;
    double w= person.weight;
    w /= h;
    return w;
}
*/

