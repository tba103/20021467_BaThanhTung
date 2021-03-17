#include <iostream>
using namespace std;
void nFilter(char *s) {
    char *tro = s;
    while( tro <= s+ strlen(s)-1)
    {
        if( *tro >= '0' && *tro <= '9' && *tro %2 ==1)
            *tro = '_';
        tro ++;
    }
   
}
int main()
{
	char *s;
	cin >> s;
	nFilter(s);
	cout << s;
	return 0;
}
