#include <iostream>
using namespace std;
struct BigInteger{
	int sign;
	string number;	
	BigInteger()
	{
	}
	void Nhap()
	{
		cin >> sign >> number;
	}
};
string Summation( string a, string b)
{
	int k=0;
	string s="";
	while ( a.size() != b.size())
	{
		if( a.size() < b.size())  a = '0' + a;
		else  b = '0' + b;
	}
	char * _a =  &a[a.size()-1];
	char * _b = &b[b.size()-1];
	while ( _a >=  &a[0])
	{
		if ( (*_a -'0' + *_b-'0' +k)  >= 10) 
		{
			char x = (*_a-'0' + *_b-'0' -10 +k) +'0';
			s =  x+s;
			k=1;
		}
		else 
		{
			char x = (*_a-'0' +*_b-'0' +k) +'0';
			s = x+s;
			k=0;
		}
		_a--;
		_b--;
	}
	if ( 1 == k) s = '1' + s;
	return s;
}
string Subtraction( string a, string b)
{
	int k=0;
	string s="", res = "";
	while ( a.size() != b.size())
	{
		if( a.size() < b.size())  a = '0' + a;
		else  b = '0' + b;
	}
	char * _a =  &a[a.size()-1];
	char * _b = &b[b.size()-1];
	while ( _b >=  &b[0])
	{
		if ( k+ ((*_a -'0') - (*_b-'0')) < 0) 
		{
			char x = ((*_a-'0') - (*_b-'0') +10 +k) +'0';
			s =  x+s;
			k=-1;
		}
		else 
		{
			char x = ((*_a-'0') - (*_b-'0') +k) +'0';
			s = x+s;
			k=0;
		}
		_a--;
		_b--;
	}
	char * _res = &s[0];
	while ( _res <= &s[s.size()-1])
	{
		if ( *_res != '0') break;
		_res++;
	}
	while ( _res <= &s[s.size()-1])
	{
		res += *_res;
		_res++;
	}
		if ( res.empty()) res = "0";
	return res;
}
BigInteger sum( BigInteger first, BigInteger second)
{
	BigInteger res;
	if( first.sign == second.sign) 
	{
			res.sign = first.sign;
			res.number = Summation( first.number, second.number);
			//cout <<"---" << res.sign <<"---"<< res.number << endl;
	}
	else if ( first.sign == 1) 
	{
		if( (first.number).size() > (second.number).size() || ((first.number).size() == (second.number).size() && first.number >= second.number ) )
		{
			res.sign = 1;
			res.number = Subtraction(first.number, second.number);
		 } 
		else if((first.number).size() < (second.number).size() || ((first.number).size() == (second.number).size() && first.number <= second.number ) )
		{
			res.sign = 0;
			res.number = Subtraction(second.number, first.number);
		}
		
	}
	else 
	{
		if( (first.number).size() > (second.number).size() || ((first.number).size() == (second.number).size() && first.number >= second.number ) )
		{
			res.sign = 0;
			res.number = Subtraction(first.number, second.number);
		 } 
		else if((first.number).size() < (second.number).size() || ((first.number).size() == (second.number).size() && first.number <= second.number ) )
		{
			res.sign = 1;
			res.number =  Subtraction(second.number, first.number);
		}
	}
	return res;
}
int main(){
	BigInteger first,second;
	first.Nhap();
	second.Nhap();
	BigInteger res = sum(first,second);
	if ( res.number == "0") cout << '0';
	else 
	{
	if ((res.sign ==0) ) cout << '-' ;
	cout << res.number << endl;
	}
	return 0;
}
