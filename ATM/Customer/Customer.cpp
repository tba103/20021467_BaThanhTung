#include "Customer.h"
void InputHistory(string s)
{
    cerr << "this is Input History" << endl;
    ofstream outfile;
    outfile.open("DealHistory.txt", ofstream:: app);
    if( !outfile.is_open())
    {
        cerr << "Can't open file"<< endl;
    }
    else
    {
        cerr << "open file"<< endl;
        outfile << s;
        outfile << endl;
        cout << s << endl;
    }
    outfile.close();
    cerr << "Input History completed" << endl;
}
int OutputHistory( char **his)
{
     cout<< "This is OutputHistory" << endl;
    ifstream infile("DealHistory.txt");
    int k=0;
    if( infile.is_open())
    {
        cerr << " File is opened" << endl;
        while ( !infile.eof())
        {
            string res="";
            infile >> res;
            for( int i=0 ; i< res.size(); i++)
            {
                 *(*(his+k)+i) = res[i];
                 //cout << *(*(s+k)+i);
            }
            k++;
            //cout << endl;
        }
    }
    else{
        cerr << "Can't open file DealHistory.txt" << endl;
    }
    cerr << "OutputHistory is completed" << endl;
    return k;
}
void  Customer::Nhap(string data) // ghi du lieu lay ra tu data.txt sang dang du lieu class Customer
    {
        cerr << "This is Nhap" << endl;
        string x="";
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
                ID = x;
                x ="";
                break;
            }
        }
        for( ++i ; i < data.size(); i++)
        {
            if ( data[i] != ',')
            {
                x = x  + data[i];
            }
            else
            {
                pass = x;
                x="";
                break;
            }
            }
        for( ++i ; i < data.size(); i++)
        {
            if ( data[i] != ',')
            {
                x = x  + data[i];
            }
            else break;
        }
        for( i=0 ; i < x.size(); i++)
        {
            char m = x[i];
            if( m <'0' || m >'9' ) break;
            int k= x[i]-'0';
            _money = _money*10 + k;
        }
            money = _money;
        cout << ID << " " << pass << " " << money << endl;
        cerr << "Nhap is completed" << endl;
        return;
    }
void Customer:: Xuat() // hien thi sau khi dang nhap thanh cong
    {
        cerr << "This is Xuat" << endl;
        cout << "ID cua ban la: " << ID << endl;
        cout << "Mat khau cua ban la: " << pass << endl;
        cout << "So tien cua ban la: " << money << endl;
        cerr << "Xuat is completed" << endl;
    }
bool checkATM( Customer &Cus, int atm[6], int money)
{
    return false;

}
void OutputATM( int atm[6])
{

    // lay du tieu so tien trong ATM
    cout<< "This is OutputATM" << endl;
    ifstream infile("MoneyATM.txt");
    if(!infile.is_open()) cerr << "Can't open file MoneyATM.txt" << endl;
    else
    {
        cerr << "Open file MoneyATM.txt" << endl;
        int i=0;
        while(!infile.eof())
        {
            infile >> atm[i];
            i++;
        }
    }
    cerr << "OutputATM is completed" << endl;
    return;
}
void InputData(string a, string b, string c) // dua thong tin vao file data.txt
{
    cerr << " this is Input data" << endl;
    string res = a + ',' + b +',' + c ;
    res[res.size()] = '/0';
    ofstream outfile;
    outfile.open("CustomerData.txt", ofstream:: app);
    if( !outfile.is_open())
    {
        cerr << "Can't open file"<< endl;
    }
    else
    {
        cerr << "open file"<< endl;
         outfile << endl;
         outfile << res;
         cout << res << endl;
    }

    outfile.close();
    cerr << "Input Data completed" << endl;
}

int OutputData( char **s) // lay ra thong tin tu data.txt de check va so luong CustomerData
{
    cerr << "This is outputData" << endl;
    ifstream infile("CustomerData.txt");
    int k=0;
    if( infile.is_open())
    {
        cerr << " File is opened" << endl;
        while ( !infile.eof())
        {
            string res="";
            infile >> res;
         //   cout << res << "Outputdata---"<< res.size() << endl;
            for( int i=0 ; i< res.size(); i++)
            {
                 *(*(s+k)+i) = res[i];
                 //cout << *(*(s+k)+i);
            }
            k++;
            //cout << endl;
        }
    }
    else{
        cerr << "Can't open file" << endl;
    }
    cerr << "OutputData is completed" << endl;
    return k;

}
bool checkSignIn( Customer *Cus,int &number, string ID, string pass, int &stt) // kiem tra tai khoan va mat khau da dung voi du lieu chua?
{
    for( int i=0 ; i < number; i++)
    {
        if (Cus[i].ID == ID && Cus[i].pass == pass)
        {
            //cerr << "Da tim thay ID va pass" << endl;
            stt = i;
            cout << stt << endl;
            return true;
        }
    }
    return false;
}
bool checkSignUp( Customer *Cus,int &number, string ID, int &stt) // kiem tra tai khooan moi tao thanh co bi trung lap k?
{
    for( int i=0 ; i < number; i++)
    {
        if (Cus[i].ID == ID )
        {
            cerr << "ID bi lap" << endl;
            return false;
        }
    }
    stt = number;
    cout << stt << endl;
    return true;
}

void Appear( Customer *Cus, int &number, int atm[6]) // man hinh hien thi
{
    cout << "Chao ban den voi ATM!!" << endl;
    cout << "Vui long an phim '1' de dang nhap" << endl;
    cout << "vui long an phim '2' de dang ki" << endl;
    int x;
    // gia tri x tuong duong voi yeu cau dang nhap va dang ki
    int stt=0;
    // bien luu vi tri cua du lieu hien hanh
    do
    {
        cin >> x;
    }
    while( x != 1 && x!=2);
    // neu x khac 1 va 2 yeu cau nhap lai
    int k=0,lap=0;
    string ID="";
    if ( 1 == x) // Thao tac dang nhap
    {
        string pass,money;
        int k=0; // bien dem ngoai le
        do
        {
        k++;
        if (k ==6) // dieu kien khoa the
        {
            cout << "Ban da nhap sai qua 5 lan!!!" << endl
                 << "Tai khoan cua ban da bi khoa!!!" << endl
                 << "Vui long den noi cap de mo khoe the!!!" << endl;
            return;
        }
        if(k>1)
                cout << "ID hoac mat khau khong dung vui long nhap lai!!" << endl;
        cout << "Vui long nhap ID va mat khau cua ban:" << endl;
        cout << "ID: ";
        cin >> ID ;
        cout << "Password: ";
        cin >> pass;
        }
        while( !checkSignIn(Cus,number,ID,pass,stt));
        ID= ID + " signed in.";
        InputHistory(ID);
        // vong lap den khi tai khoan va mat khau trung khop
    }
    else
    {   // Thao tac Dang ki
         string pass1,pass2,money;
        do{
        k++;
        if(k>1)
        {
            cerr << "Ban da nhap sai mat khau vui long nhap lai!!" << endl;
        }

        cout << "Vui long nhap ID va mat khau cua ban:" << endl;
        do
        {
            // kiem tra ID tao co trung voi ID da co khong?
            if( lap > 0) cerr << "ID cua ban bi trung, vui long nhap lai ID!!" << endl;
          cout << "ID: ";
            cin >> ID ;
            lap++;
        }
        while(!checkSignUp(Cus,number,ID,stt));
        cout << "Password: ";
        cin >> pass1;
        cout << "Nhap lai Password: ";
        cin >> pass2;
        }
        while ( pass1 != pass2 );
        InputData(ID,pass1,"000000");
        {
            // them du lieu va mang dong
            Cus[stt].ID = ID;
            Cus[stt].pass = pass1;
            Cus[stt].money =0;
        }
        number++;
        cout << "Number thay doi::" << number << endl;
        ID = ID + " signed up.";
        InputHistory(ID);
    }


    // Giao dien man hinh
    cout << "Dang nhap thanh cong!!" << endl;
    cout << "Chon yeu cau ban mong muon:" << endl;
    cout << "1. Nap tien " << endl;
    cout << "2. Rut tien" << endl;
    cout << "3. Van tin tai khoan" << endl;
    int request=0,repeat=0;
    do
    {
        if(repeat>0) cout <<"Vui long chon dung phim theo yeu cau!!" << endl;
        repeat++;
        cin >> request;
    }
    while(request !=1 && request != 2 && request != 3);
    if(1 == request ) // naptien
    {
        cout << "So tien ban muon nap la: "<< endl;
        cout << "Vui long ghi ro so to tien tuong ung menh gia" << endl;
        int Kofm[6]={0,0,0,0,0,0};
        cout << "So to menh gia 10000 dong la: ";
        cin >> Kofm[0];
        atm[0] +=Kofm[0];
        cout << endl;
        cout << "So to menh gia 20000 dong la: ";
        cin >> Kofm[1];
        atm[1] +=Kofm[1];
        cout << endl;
        cout << "So to menh gia 50000 dong la: ";
        cin >> Kofm[2];
        atm[2] +=Kofm[2];
        cout << endl;
        cout << "So to menh gia 100000 dong la: ";
        cin >> Kofm[3];
        atm[3] +=Kofm[3];
        cout << endl;
        cout << "So to menh gia 200000 dong la: ";
        cin >> Kofm[4];
        atm[4] +=Kofm[4];
        cout << endl;
        cout << "So to menh gia 500000 dong la: ";
        cin >> Kofm[5];
        atm[5] +=Kofm[5];
        cout << endl;
        Cus[stt].money += Kofm[0]*10000 + Kofm[1]*20000 + Kofm[2]*50000 + Kofm[3]*100000 + Kofm[4]*200000 + Kofm[5]*500000 ;
        string now = Cus[stt].ID + " recharge money to card.";
        InputHistory(now);
    }
    else if(2 == request)
    {
        int money=0,laprut=0;
        do
        {
            if (laprut >0) cout << "So tien khong thoa man, vui long nhap lai!!" << endl;
            cout << "So tien ban muon rut la:" << endl;
            cin >> money;
        }
        while(checkATM(Cus[stt],atm,money));
        Cus[stt].money -= money;
        string now = Cus[stt].ID + " took money.";
        InputHistory(now);
    }
    else
    {
        cout << "stt la" << stt << endl;
        Cus[stt].Xuat();
    }
    return;
}
void UpdateCustomerData( Customer *Cus, int &number)
{


    cerr << " this is Update data" << endl;
    string s ="";
    ofstream outfile;
    outfile.open("CustomerData.txt", ofstream:: trunc);
    if( !outfile.is_open())
    {
        cerr << "Can't open file"<< endl;
    }
    else
    {
        cerr << "open file"<< endl;
        for( int i=0 ; i< number; i++)
        {
            s = Cus[i].ID + ',' + Cus[i].pass +',' + to_string(Cus[i].money);
            s[s.size()] = '/0';
            outfile << s;
            cout << s << endl;
            if ( i!= number-1) outfile << endl;
        }
    }

    outfile.close();
    cerr << "Update Data completed" << endl;
}
void UpdateATM(int atm[6])
{
    cerr << " this is Update ATM" << endl;
    ofstream outfile;
    outfile.open("MoneyATM.txt", ofstream:: trunc);
    if( !outfile.is_open())
    {
        cerr << "Can't open file MoneyATM.text"<< endl;
    }
    else
    {
        cerr << "open file"<< endl;
        for( int i=0 ; i< 6; i++)
        {
            outfile << atm[i];
            outfile << endl;
        }
    }
    outfile.close();
    cerr << "Update ATM completed" << endl;
}

