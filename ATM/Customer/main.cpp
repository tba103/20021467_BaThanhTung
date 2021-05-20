#include "Customer.h"
using namespace std;
int main()
{
    int atm[6];
    OutputATM(atm);
//    for( int i=0; i < 6; i++)
//            cout << atm[i] <<" ";
//            cout << endl;
    char **s = new char*[100];
    for( int i=0 ; i< 100; i++)
    {
        *(s+i) = new char[50];
    }
    int n =OutputData(s);
    Customer Cus[100];
    for( int i=0; i < n; i++)
    {
         Cus[i].Nhap(s[i]);
    }
    Appear(Cus,n,atm);
    UpdateCustomerData(Cus,n);
    UpdateATM(atm);
    for( int i=0 ; i< 100; i++)
    {
        delete[]s[i];
    }
    delete[]s;
    return 0;
}
