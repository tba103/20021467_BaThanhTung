fd#include <iostream>
using namespace std;
void  Nhap(string data)
    {
        // batung,123456,100000
        string x="",y="",z="",money;
        int _money=0;
        int i=0;
        for( ; i < data.size(); i++)
        {
            if ( data[i] != ',')
            {
                x = x  + data[i];
            }
            else
            {
                string ID = x;
                cout << ID << endl;
                //x ="";
                break;
            }
  		  }
        for( ++i ; i < data.size(); i++)
        {
            if ( data[i] != ',')
            {
                y = y  + data[i];
            }
            else
            {
                string pass = y;
                 cout <<"matkhau" << pass << endl;
               // x="";
                break;
            }
            }
        for( ++i ; i < data.size(); i++)
        {
            if ( data[i] != ',')
            {
                z = z  + data[i];
            }
            else break;
   		 }
             cout << "so tien " << z << " dong" <<endl;
        
        for( i=0 ; i < z.size(); i++)
        {
            char m = z[i];
            int k= z[i]-'0';
            cout << k << "--";
            _money = _money*10 + k;
        }
            money = _money;
            cout << money << endl;
        return;

    }
    int main()
    {
    string s;
    getline(cin,s);
    Nhap(s);
    return 0;
    }
