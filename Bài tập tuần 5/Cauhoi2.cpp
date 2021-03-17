#include <iostream>
#include <cstring>
using namespace std;
void amazingDelete(char*s)
{
	char* first = s+1;
	char* second = s+3;
	while( second <=  s+strlen(s) -1)
	{
		*first = *second;
		*first++;
		*second++;
	}
	*first = NULL;
	*first++;
	*first == NULL;
}
int main()
{
	char *s;
s = new char[50];
cin >> s;
amazingDelete(s);
cout << s;
	return 0;
}
