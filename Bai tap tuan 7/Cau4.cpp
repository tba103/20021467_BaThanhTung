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
      string s,y;
      getline(cin,s);
    int i=0;
    for( i; i < s.size(); i++)
        if( s[i] != ',') y = y+ s[i];
        else 
        {
            MSSV = y;
            
            i+=2;
            cout << y <<endl;
            y="";
            break;
            
        }
    for( i; i < s.size(); i++)
        if( s[i] != ',') y = y+ s[i];
        else 
        {
            Hoten = y;
            
            i+= 2;
             cout << y << endl;
             y="";
            break;
        }
    for(    i; i < s.size(); i++)
        if( s[i] != ',') y = y+ s[i];
        else 
        {
            GPA = y;       
            i+=2;
             cout << y << endl;
             y="";
            break;
        }
  }
};
int main()
{
    int n;
    Student s[100];
    cin >> n;
    for( int i=0 ; i < n; i++)
        s[i].GetInf();
    return 0;
}

