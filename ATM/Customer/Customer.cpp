#include "Customer.h"
void InputHistory(string s, int money)
{
    //cerr << "This is Input History" << endl;
    ofstream outfile;
    outfile.open("DealHistory.txt", ofstream:: app);
    if( !outfile.is_open())
    {
        cerr << "Can't open file"<< endl;
    }
    else
    {
        // take the current time to infile >>
        time_t now = time(NULL);
        char * currentdate = ctime(&now);
        //cerr << "Open file"<< endl;
        outfile << s;
        if( money >= 0) outfile << ": +" << money;
        else outfile << ": -" << money;
        outfile  << "VND  " << currentdate;
        //outfile << endl;
        //cout <<  s << " " << currentdate << endl;
        delete[]currentdate;
    }
    outfile.close();
    //cerr << "Input History completed" << endl;
}
void OutputHistory()
{
     //cerr<< "This is OutputHistory" << endl;
    ifstream infile("DealHistory.txt");
    if( infile.is_open())
    {
        //cerr << " File is opened" << endl;
        do
        {
            string res;
            getline(infile,res);
            cout << res << endl;
        }
        while ( !infile.eof());
    }
    else{
        cerr << "Can't open file DealHistory.txt" << endl;
    }
    cerr << "OutputHistory is completed" << endl;
    return;
}
void  Customer::Nhap(string data) // ghi du lieu lay ra tu data.txt sang dang du lieu class Customer
    {
        //cerr << "This is Nhap" << endl;
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
       // cout << ID << " " << pass << " " << money << endl;
        //cerr << "Nhap is completed" << endl;
        return;
    }
void Customer:: Xuat() // hien thi sau khi dang nhap thanh cong
    {
        //cerr << "This is Xuat" << endl;
        cout << "ID cua ban la: " << ID << endl;
        cout << "Mat khau cua ban la: " << pass << endl;
        cout << "So tien cua ban la: " << money << endl;
        cerr << "Xuat is completed" << endl;
    }
bool checkATM( Customer &Cus, int atm[6], int money, int _atm[6])
{
    //cout << "This is check ATM" << endl;
    cout << "So tien ban co la " << Cus.money << endl;
    cout << "So tien ban muon rut la " << money << endl;
    //cout << "Cac menh gia hien co la ";
    //for( int i=0; i < 6 ; i++) cout << atm[i] << " ";
    cout << endl;
    int copyatm[6];
    // tao mang dong luu su thay doi so luong cac loai tien
    for( int i=0; i < 6 ; i++) copyatm[i] = atm[i];
    int value[]={10000,20000,50000,100000,200000,500000};
    // tao mang dong luu gia tri ung voi moi loai tien
    if ( money > Cus.money) return false;
    // gia tri rut vuot so tien co trong tai khoan
    int maxvalue=0;
    for( int i=5; i >=0 ; i--)
    {
        if( money >= value[i] )
        {
              // tim menh gia lon nhat co the rut
              maxvalue = i;
              break;
        }
    }
    while(money>0 && maxvalue>=0)
    {
        // lay dan tien menh gia tu lon den be
        if(money >= value[maxvalue] && copyatm[maxvalue] >0)
        {
            _atm[maxvalue]++;
            copyatm[maxvalue]--;
            money -= value[maxvalue];
        }
        else maxvalue--;
    }
    if( money >0) return false;
    else{
       //    cout << "Thoa man check ATM" << endl;
        for( int i=0; i < 6 ; i++)
            atm[i] = copyatm[i];
        return true;
    }

    return true;
}
void OutputATM( int atm[6])
{

    // lay du tieu so tien trong ATM
    //cerr<< "This is OutputATM" << endl;
    ifstream infile("MoneyATM.txt");
    if(!infile.is_open()) cerr << "Can't open file MoneyATM.txt" << endl;
    else
    {
        //cerr << "Open file MoneyATM.txt" << endl;
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
    //cerr << " this is Input data" << endl;
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
        //cerr << "open file"<< endl;
         outfile << endl;
         outfile << res;
         //cout << res << endl;
    }

    outfile.close();
    cerr << "Input Data completed" << endl;
}

int OutputData( char **s) // lay ra thong tin tu data.txt de check va so luong CustomerData
{
    //cerr << "This is outputData" << endl;
    ifstream infile("CustomerData.txt");
    int k=0;
    if( infile.is_open())
    {
        //cerr << " File is opened" << endl;
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
bool checkStrongPassword(string password)
{
    if (password.length()<6)
        return false;
    bool kt1 =false;
    bool kt2 =false;
    bool kt3 =false;
    for (int i=0;i<password.length();i++){
    if (password[i]>=48 && password[i]<=57) kt1= true;
    if (password[i]>=97 && password[i]<=122) kt2=true;
    if (password[i]>=65 && password[i]<=90) kt3=true;
    }
    return kt1 && kt2 && kt3;
}
bool checkSignIn( Customer *Cus,int &number, string ID, string pass, int &stt, int &k) // kiem tra tai khoan va mat khau da dung voi du lieu chua?
{
    string _ID="//"+ID;
    for( int i=0 ; i < number; i++)
    {
        if (Cus[i].ID == ID && Cus[i].pass == pass)
        {
            //cerr << "Da tim thay ID va pass" << endl;
            stt = i;
            return true;
        }
        if (Cus[i].ID == _ID)
        {
            cout << "Tai khoan nay cua ban da bi khoa, khong the dang nhap" << endl;
            k=-1;
            return false;
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
            //cerr << "ID bi lap" << endl;
            return false;
        }
    }
    stt = number;
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
    int k=0,_k=0,lap=0;
    string ID="",_ID;
    if ( 1 == x) // Thao tac dang nhap
    {
        string pass,money;
        int k=0; // bien dem ngoai le
        do
        {
        if( 10 == _k)
        {
            cout << "Ban da nhap qua so lan cho phep cua ATM!!" << endl;
            cout << "Giao dich cua ban da duoc ghi lai va dieu tra!!" <<endl;
        }
        if (k ==5) // dieu kien khoa the
        {
            int i=0;
            while(Cus[i].ID != ID && i <= number) i++;
            Cus[i].ID = "//"+Cus[i].ID;
            cout << "Ban da nhap sai qua 5 lan!!!" << endl
                 << "Tai khoan cua ban da bi khoa!!!" << endl
                 << "Vui long den noi cap de mo khoe the!!!" << endl;
            return;
        }
        if(k>0 && -1 != k )  cout << "ID hoac mat khau khong dung vui long nhap lai!!" << endl;
        cout << "Vui long nhap ID va mat khau cua ban:" << endl;
        cout << "ID: ";
        cin >> ID ;
        if( ID == _ID || 0 == k)
        {
            k++;
        }
        else
        {
            _k += k;
            k=1;
        }
         _ID = ID;
        cout << "Password: ";
        cin >> pass;
        }
        while( !checkSignIn(Cus,number,ID,pass,stt,k));
        ID= ID + " signed in";
        InputHistory(ID,0);
        // vong lap den khi tai khoan va mat khau trung khop
    }
    else
    {   // Thao tac Dang ki
        cerr <<"Mat khau cua ban phai dam bao tinh bao mat" << endl;
        cerr <<"Mat khau co do dai toi thieu la 6, chua it nhat 1 ki tu in hoa, 1 ki tu thuong va 1 chu so" << endl;
        string pass1,pass2,money;
        do{
        lap=0;
        k++;
        if( 1!=k && !checkStrongPassword(pass1))
        {
            cout <<"Mat khau cua ban khong du do bao mat!"<< endl;
        }
        else if(k>1)
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
        while ( pass1 != pass2 || !checkStrongPassword(pass1));
        InputData(ID,pass1,"000000");
        {
            // them du lieu va mang dong
            Cus[stt].ID = ID;
            Cus[stt].pass = pass1;
            Cus[stt].money =0;
        }
        number++;
        ID = ID + " signed up";
        InputHistory(ID,0);
    }


    // Giao dien man hinh
    int access=0;
    do
    {
        if( 0 == access) cout << "Dang nhap thanh cong!!" << endl;
        cout << "Chon yeu cau ban mong muon:" << endl;
        cout << "1. Nap tien " << endl;
        cout << "2. Rut tien" << endl;
        cout << "3. Chuyen tien" << endl;
        cout << "4. Doi mat khau" << endl;
        cout << "5. Van tin tai khoan" << endl;
        cout << "6. Xem lich su giao dich" << endl;
        int request=0,repeat=0;
        do
        {
            if(repeat>0)
            cout <<"Vui long chon dung phim theo yeu cau!!" << endl;
            repeat++;
            cin >> request;
        }
        while(request !=1 && request != 2 && request != 3 && request != 4);
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
            int mn= Kofm[0]*10000 + Kofm[1]*20000 + Kofm[2]*50000 + Kofm[3]*100000 + Kofm[4]*200000 + Kofm[5]*500000 ;
            Cus[stt].money += mn;
            string now = Cus[stt].ID + " recharge money to card";
            cout << "Nap tien thanh cong!" << endl;
            cout << "So tien trong tai khoan cua ban la: " << Cus[stt].money << endl;
            cout << "Cam on quy khanh da su dung dich vu!!" << endl;
            InputHistory(now,mn);
        }
        else if(2 == request)
        {
            if(Cus[stt].money ==0)
            {
                cout << "Tai khoan cua quy khach con 0 VND" << endl;
                cout << "Vui long nap them tien de thuc hien giao dich!" << endl;

            }
            else
            {
                int money=0,laprut=0;
            int value[]={10000,20000,50000,100000,200000,500000};
            // tao mang luu gia tri ung voi moi menh gia tien
            int minmoney = value[0], mincount=0;
            // minmoney luu so tien toi thieu rut duoc
            // mincount luu vi tri cua menh gia do trong mang atm[6]
            int _atm[]={0,0,0,0,0,0};
            while(true)
            {
                if(atm[mincount] >0)
                {
                    // lay duoc gia tri toi thieu
                    minmoney = value[mincount];
                    break;
                }
                mincount++;
            }
            do
            {
                if (laprut == 0) cout << "So tien toi thieu ban co the rut la " << value[mincount] << " dong" << endl;
                if (laprut >0) cout << "So tien khong thoa man, vui long nhap lai!!" << endl;
                laprut++;
                cout << "So tien ban muon rut la:" << endl;
                cin >> money;
            }
            while(!checkATM(Cus[stt],atm,money,_atm)); // dieu kien de rut tien
            cout << "Rut tien thanh cong" << endl;
            minmoney =0;
            for( int i =0; i < 6 ; i++) minmoney += value[i]*_atm[i];
            cout << "So tien ban rut la " << minmoney << endl;
            cout << "Bao gom: "<<endl;
            for( int i=0; i < 6 ; i++)
            {
                if( 0 != _atm[i])
                {
                     cout << string(9,' ');
                     cout << _atm[i] << " to " << value[i] << " VND" << endl;
                }
            }
            cout << "Cam on quy khanh da su dung dich vu!!" << endl;
            Cus[stt].money -= money;
            string now = Cus[stt].ID + " took money";
            InputHistory(now,money);
            }
        }
        else if (3== request)
        {
            int _ID=0,k=0, money;
            string stk="";
            cout << "So tien hien co la: " << Cus[stt].money  <<"VND"<< endl;
            int i=0;
            while(Cus[i].ID != stk)
            {
                if( k>0) cout << "Tai khoan nay khong hop le!!" << endl;
                cout << "Nhap so tai khoan ban muon chuyen tien den: ";
                cin >> stk;
                for(i=0; i <= number ;i++)
                {
                    if(Cus[i].ID == stk)
                    {
                        _ID = i;
                        break;
                    }
                }
                k++;
            }
            cout << "Nhap so tien ban muon chuyen: " << endl;
            cin >> money;
            cout << "Chuyen tien thanh cong!" << endl;
             cout << "Cam on quy khanh da su dung dich vu!!" << endl;
            Cus[stt].money -= money;
            Cus[_ID].money += money;
            InputHistory(Cus[stt].ID + " transfered money to account " + Cus[_ID].ID,money);

        }
        else if (4 == request)
        {
             cerr <<"Mat khau cua ban phai dam bao tinh bao mat" << endl;
            cerr <<"Mat khau co do dai toi thieu la 6, chua it nhat 1 ki tu in hoa, 1 ki tu thuong va 1 chu so" << endl;
            string pass1,pass2;
            int k=0;
            do{
                k++;
                if( 1!=k && !checkStrongPassword(pass1))
                {
                    cout <<"Mat khau cua ban khong du do bao mat!"<< endl;
                }
                else if(k>1)
                {
                    cerr << "Ban da nhap sai mat khau vui long nhap lai!!" << endl;
                }

                cout << "Vui long mat khau cua ban:" << endl;
                cout << "Mat khau moi: ";
                cin >> pass1;
                cout << "Nhap lai mat khau moi: ";
                cin >> pass2;
        }
        while ( pass1 != pass2 || !checkStrongPassword(pass1));
            Cus[stt].pass = pass1;
            cout << "Doi mat khau thanh cong!!" << endl;
             cout << "Cam on quy khanh da su dung dich vu!!" << endl;
        }
        else if(5 == request)
        {
            Cus[stt].Xuat();
            cout << "Cam on quy khanh da su dung dich vu!!" << endl;
            string now = Cus[stt].ID + " inquired information account";
            InputHistory(now,0);
        }
        else
        {
            string s="";
            int k=0;
            do
            {
                if( 5==k)
                {
                    cout << "Ban da nhap sai 5 lan, chuc nang xem lich su giao dich tam thoi bi khoa" << endl;
                    cout << "Vui long thuc hien cac giao dich khac!!" << endl;
                    break;
                }
                if(k>0)
                {
                    cout << "Ban da nhap sai mat ma" << endl;
                    cout << "Ban con "<< 5-k << " lan nhap ma" << endl;
                }
                if( 0==k) cout << "De xem lich su giao dich can ma bao mat ATM" << endl;
                cout << "Vui long nhap ma bao mat" << endl;
                cin >> s;
                k++;
            }
            while( s!= "bathanhtung" );
            if( 5!= k)
            {
                OutputHistory();
                cout << "Cam on quy khanh da su dung dich vu!!" << endl;
                InputHistory("Administrator user access ATM History",0);
            }
        }
         Sleep(1000);
        cout << "Ban co muon thuc hien giao dich khac?" << endl;
        cout << "Vui long an phim 1 de thuc hien hoac an phim 0 de ket thuc!"<< endl;
        cin >> access;
    }
    while(1== access);
    }
void UpdateCustomerData( Customer *Cus, int &number)
{
    // cerr << " this is Update data" << endl;
    string s ="";
    ofstream outfile;
    outfile.open("CustomerData.txt", ofstream:: trunc);
    if( !outfile.is_open())
    {
        cerr << "Can't open file"<< endl;
    }
    else
    {
        //cerr << "open file"<< endl;
        for( int i=0 ; i< number; i++)
        {
            s = Cus[i].ID + ',' + Cus[i].pass +',' + to_string(Cus[i].money);
            s[s.size()] = '/0';
            outfile << s;
            //cout << s << endl;
            if ( i!= number-1) outfile << endl;
        }
    }

    outfile.close();
    cerr << "Update Data completed" << endl;
}
void UpdateATM(int atm[6])
{
    //cerr << " this is Update ATM" << endl;
    ofstream outfile;
    outfile.open("MoneyATM.txt", ofstream:: trunc);
    if( !outfile.is_open())
    {
        cerr << "Can't open file MoneyATM.text"<< endl;
    }
    else
    {
       // cerr << "open file"<< endl;
        for( int i=0 ; i< 6; i++)
        {
            outfile << atm[i];
            outfile << endl;
        }
    }
    outfile.close();
    cerr << "Update ATM completed" << endl;
}

