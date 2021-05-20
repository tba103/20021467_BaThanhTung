#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;
class Customer
{
    public:
    string ID,pass;
    int money;
    //Customer();
    void Nhap(string data);
    void Xuat();

};

void InputData(string a, string b, string c);
int OutputData( char **s);
void UpdateCustomerData( Customer *Cus, int &num);
bool checkSignIn( Customer *Cus, int &number, string ID, string pass, int &stt);
bool checkSignUp( Customer *Cus, int &number, string ID, int &stt);
void Appear( Customer *Cus, int &number, int atm[6]);
void OutputATM( int atm[6]);
void BestChoice(int atm[6]);
void UpdateATM(int atm[6]);
int OutputHistory( char **s);
void InputHistory(string s);
bool checkATM( Customer &Cus, int atm[6], int money);
#endif
