//second self made. Throw 0 for avoid division by zero and catch 0 and print infi. c = a/b, necessary to other cases where b!=0.
#include <iostream>
using namespace std;


int main() {
	int t,a,b;int c,x,y,z;
	cin >> t;
	while(t--)
	 {
	     cin >> a >> b;
         try
          {if(b==0)
              throw 0;

            x = max(a+b,a-b);
            c = a/b;
            y = max(a*b,c);
            z = max(x,y);
            cout << z << "\n";}

            catch(int q)
              { cout << "infi\n";}


	 }

	return 0;
}

