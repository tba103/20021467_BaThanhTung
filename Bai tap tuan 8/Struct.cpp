#include <iostream>
using namespace std;
string Summation( string a, string b)
{
	int k=0;
	string s="";
	while ( a.size() != b.size())
	{
		if( a.size() < b.size())  a = '0' + a;
		else  b = '0' + b;
	}
	char * tro1 =  &a[a.size()-1];
	char * tro2 = &b[b.size()-1];
	while ( tro1 >=  &a[0])
	{
	//	cout << *tro1 << "---" << *tro2 << endl;
		if ( (*tro1 -'0' + *tro2-'0' +k)  >= 10) 
		{
			char x = (*tro1-'0' + *tro2-'0' -10 +k) +'0';
			s =  x+s;
			k=1;
		}
		else 
		{
			char x = (*tro1-'0' +*tro2-'0' +k) +'0';
			s = x+s;
			k=0;
		}
		tro1--;
		tro2--;
	}
	if ( 1 == k) s = '1' + s;
	return s;
}
struct BigInteger{
	string number;
	
	BigInteger():number("0") {};
	
	BigInteger( int num)
	{
		string _number="";
		while(num >0)
		{
			char x = (num%10) +'0';
			_number = x+ _number;
			num /= 10;
		}
		number = _number;
	}
	
	BigInteger (string num): number(num) {};
	
	void print() const {
		cout << "The big integer is: " << number << endl;
	}	
	int getValue() const{
		if ( number.size() <10 ) {
			int k=0;
			for( int i=0 ; i< number.size(); i++)
				k= (k + (number[i]-'0'))*10;
				k /= 10;
		return k;
		}
		else if ( number.size() == 10)
		{
			long long k = 0;
				for( int i=0 ; i< number.size(); i++)
				k= (k + (number[i]-'0'))*10;
				k /= 10;
			if ( k <= 2147483647 ) return (int)k;
			else return -1;
		}
		else return -1;
	}
	
	BigInteger add( const BigInteger& other)
	{
		number = Summation( number, other.number);
		return number;
	}

};

int main()
{
	int x;
	cin >> x;
	BigInteger res1;
	BigInteger res2(x);
	BigInteger res3("15263746877676354");
	res1.print();
	res3.add(res2);
	res3.print();
	return 0;
}
