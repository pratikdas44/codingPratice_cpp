//Program to print largest number possible formed from an array.
//Here using append function to check for numbers such as 98 and 980.
#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
using namespace std;

int myCompare(string X, string Y) 
{ 
    // first append Y at the end of X 
    string XY = X.append(Y); 
  
    // then append X at the end of Y 
    string YX = Y.append(X); 
  
    // Now see which of the two formed numbers is greater 
    return XY.compare(YX) > 0 ? 1: 0; 
} 

void printLargest(vector<string> arr) 
{ 
    // Sort the numbers using library sort funtion. The function uses 
    // our comparison function myCompare() to compare two strings. 
    // See http://www.cplusplus.com/reference/algorithm/sort/ for details 
    sort(arr.begin(), arr.end(), myCompare); 
  
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
 

int main() {
	int t,n;string x;
	scanf("%d",&t);
	while(t--)
	{
	    scanf("%d",&n);
        vector<string> a;
	    for(int i=0;i<n;i++)
	     {
	         cin >> x;
	         a.push_back(x);
	     }
   
    printLargest(a);cout << endl;
	}
	return 0;
}

//Another approach self made

#include<iostream>
#include<algorithm>
#include<list>
#include<string>
using namespace std;

bool compare (string i, string j) {
string xy = i.append(j);
string yx = j.append(i);
return (xy > yx);
}

void print(list<string> a)
{list<string> :: iterator it;
    for(it=a.begin();it!=a.end();it++)
         cout << *it ;
}
int main()
{
 list<string> a;string x;
 int t,n;
 cin >> t;
 while(t--)
  {  cin >> n;
      for(int i=0;i<n;i++)
   {
     cin >> x;
     a.push_back(x);}

    

    a.sort(compare);
     print(a);
      cout << endl;
      a.clear();
    
         
  }

  return 0; }
