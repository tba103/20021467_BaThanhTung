//x1 + v1 t1 = x2 + v2 t1
#include <iostream>
using namespace std;
int main()
{
    char **p = new char*[3];
   	char *tro = *p;
	for( int i=0; i < 3; i++)
		 {
		 	tro = new char[3];
		 	*tro++;
		 }
	tro = *p;
    for( int i=0; i < 3; i++)
    	{
    		char *tro2 = *p;
    		for( int j=0; j < 3; j++)
    		{
    			cin >> *(tro+ *tro2);
    			*tro2++;	
			}
    	 *tro++;
		}
	tro = *p;
	for( int i=0; i < 3; i++)
    	{
    		char *tro2 = *p;
    		for( int j=0; j < 3  ; j++)
    		{
    		cout <<  *(tro+ *tro2) << " "; // *(*(p+i) +j)
    			*tro2++;	
			}
			cout << endl;
    		*tro++;
		}
    return 0;
}
