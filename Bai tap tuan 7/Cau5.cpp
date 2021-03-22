#include <iostream>
#include <string>
using namespace std;
struct Student
{
  string MSSV;
  string Hoten;
  string GPA;
  Student()
  {
  }
  void GetInf()
  {
      string s;
      string y = "";
      getline(cin,s);
    int i=0;
    for( i; i < s.size(); i++)
        if( s[i] != ',') y = y+ s[i];
        else 
        {
            MSSV = y;
            i+=2;
            y="";
            break;
            
        }
    for( i; i < s.size(); i++)
        if( s[i] != ',') y = y+ s[i];
        else 
        {
            Hoten = y;
            i+= 2;        
            y="";
            break;
        }
    for(    i; i < s.size(); i++)
        y = y+ s[i];
    GPA = y;

    
}
};
Student bigger( Student a, Student b)
{
//	cout << a.GPA << "___" << b.GPA << "___";
	if( (a.GPA) > (b.GPA)) return a;
	return b;	
}
Student best( Student *s, int n)
{
	Student *p = s;
	Student res =  s[0];
	while ( p <= &s[n])
	{
		res = bigger((*p), res);
	//	cout << res.GPA << endl;
		p++;
	}
	return res;
}
int main()
{
    int n;
    Student s[100];
    cin >> n;
    for( int i=0 ; i <= n; i++)
      s[i].GetInf();
    Student x = best(s,n);
    cout << x.Hoten << endl;
    return 0;
}

