//n is number or hidden layers and minx and maxx gives number of input of number of neurons.
//if o/p is even it is not spam otherwise it is.
#include <iostream>
#include <vector>
#include <map>

using namespace std;
struct Nodes
        {
            int weight,bias;
        };
bool calculate(map<int,Nodes>,int,long long int);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {


        int n;
        long long int minx,maxx;

        cin>>n>>minx>>maxx;
        map<int,Nodes> neuralMap;
        for(int i=0;i<n;++i)
        {
            int w,b;
            cin>>w>>b;
            neuralMap[i]={w,b};
        }
        int countEven=0,countOdd=0;

        //cout<<sizeof(neuralMap);
        //cout<<neuralMap[0].weight;
        for(long long int i=minx;i<=maxx;++i)
        {



        if(calculate(neuralMap,n,i))
        {
            countEven++;
        }
        else
            countOdd++;

        }
        cout<<countEven<<" "<<countOdd<<endl;

    }
    return 0;
}

bool calculate(map<int,Nodes> neuralMap,int n,long long int firstInput)
{
    long long int f=firstInput;
    long long int y;
    for(int k=0;k<n;++k)
    {
        y = neuralMap[k].weight*f + neuralMap[k].bias;
        f=y;
    }
    if(f%2==0)
        return true;
    else
        return false;
}
