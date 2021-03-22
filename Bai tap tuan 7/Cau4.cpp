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
string Subtraction( string a, string b)
{
	int k=0;
	string s="", res = "";
	char * tro1 =  &a[a.size()-1];
	char * tro2 = &b[b.size()-1];
	while ( tro2 >=  &b[0])
	{
		//cout << *tro1 << "---" << *tro2 << endl;
		if ( k+ ((*tro1 -'0') - (*tro2-'0')) < 0) 
		{
			char x = ((*tro1-'0') - (*tro2-'0') +10 +k) +'0';
			s =  x+s;
			k=-1;
		}
		else 
		{
			char x = ((*tro1-'0') - (*tro2-'0') +k) +'0';
			s = x+s;
			k=0;
		}
		tro1--;
		tro2--;
	}
	while ( tro1 >= &a[0])
	{
		*tro1 += k;
		s = *tro1 + s;
		k=0;
		tro1--;
	}
	tro1 = &s[0];
	while ( tro1 <= &s[s.size()-1])
	{
		if ( *tro1 != '0') break;
		tro1++;
	}
	while ( tro1 <= &s[s.size()-1])
	{
		res += *tro1;
		tro1++;
	}
		if ( res.empty()) res = "0";
	//cout << "---" << res << "---" << endl;

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
