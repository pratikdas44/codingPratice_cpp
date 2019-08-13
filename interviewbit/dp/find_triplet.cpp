//triplet with given sum nearest or equal to given number.
sort(A.begin(),A.end());
int i,j,k,n,flag=0,ans=INT_MAX;
n=A.size();
for(i=0;i<n-2;i++)
{
for(j=i+1,k=n-1;j<k;)
{
if(abs(A[i]+A[j]+A[k]-B)<ans)
{
ans=abs(A[i]+A[j]+A[k]-B);
flag=A[i]+A[j]+A[k];
}
else if(A[j]+A[k]>B-A[i])
k--;

        else
         j++;
    }
    
}
return flag;

