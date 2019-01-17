//program to find minimum cost of roop.
#include <bits/stdc++.h>
using namespace std;

int findlen(int arr[],int n)
{

    priority_queue< int, vector<int>, greater<int> > pq(arr, arr+n); 
  
    // Initialize result 
    int res = 0; 
  
    // While size of priority queue is more than 1 
    while (pq.size() > 1) 
    { 
        // Extract shortest two ropes from pq 
        int first = pq.top(); 
        pq.pop(); 
        int second = pq.top(); 
        pq.pop(); 
  
        // Connect the ropes: update result and 
        // insert the new rope to pq 
        res += first + second; 
        pq.push(first + second); 
    } 
  
    return res; 
}

int main() {
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
	    cin >> n;
	    int a[n];
	    for(int i=0;i<n;i++)
	      scanf("%d",&a[i]);

	    printf("%d\n",findlen(a,n));
	}
	return 0;
}


//self made
#include <bits/stdc++.h>
using namespace std;


int findlen(vector<int> a,int n)
{

    int c=0;
    while(a.size()>1)
    {   sort(a.begin(),a.end(),greater<int>());
        int e = a.back();
        a.pop_back();
        int f = a.back();
        a.pop_back();

        c+= e+f;
        a.push_back(e+f);

    }
    return c;
}

int main() {
	int t,n;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    vector<int>a(n);
	    for(int i=0;i<n;i++)
	      scanf("%d",&a[i]);

	    printf("%d\n",findlen(a,n));
	}
	return 0;
}

