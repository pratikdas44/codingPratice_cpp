/* An efficient program to print subarray with sum as given sum 
1.here printf used instead of cout to output values with space given or cout can be used as cout << value << " ";
2.use of break is important.
3.if question want to print -1 for no output simply printf("-1")
4.use cout only once either in called or calling function.
5.use printf and scanf for faster input and output*/
#include<stdio.h>
#include<iostream>

using namespace std;/* Returns true if the there is a subarray of arr[] with sum equal to 'sum'
otherwise returns false. Also, prints the result */int subArraySum(int arr[], int n, int sum)
{
	/* Initialize curr_sum as value of first element
	and starting point as 0 */
	int curr_sum = arr[0], start = 0, i;

	/* Add elements one by one to curr_sum and if the curr_sum exceeds the
	sum, then remove starting element */
	for (i = 1; i <= n; i++)
	{
		// If curr_sum exceeds the sum, then remove the starting elements
		while (curr_sum > sum && start < i-1)
		{
			curr_sum = curr_sum - arr[start];
			start++;
		}

		// If curr_sum becomes equal to sum, then return true
		if (curr_sum == sum)
		{
			printf ("%d %d \n", start+1, i);
			break;
			
		}

		// Add this element to curr_sum
		if (i < n)
		curr_sum = curr_sum + arr[i];
		
		else 
		 printf("-1\n");
		
	}

 
}

// Driver program to test above function



int main() {
	int t,n,s;
	cin >> t;
	while(t--)
	{
	    cin >> n >> s;int a[n];
	    for(int i=0;i<n;i++)
	     {
	          cin >> a[i];
	     }
	     subArraySum(a,n,s);
	 }
	return 0;
}

