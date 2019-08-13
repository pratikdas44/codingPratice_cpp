//to find largest area where swapping of column allowed.
//asked by directi
//dp counts when consecutive 1 is present upper than
// the element.
// C++ program to find the largest rectangle of 1's with swapping
// of columns allowed.
#include <bits/stdc++.h>
#define R 3
#define C 5

using namespace std;

// Returns area of the largest rectangle of 1's
int maxArea(vector<vector<int>> &A)
{
	// An auxiliary array to store count of consecutive 1's
	// in every column.
  int n, m, res = 0;
    n = A.size();
    m = A[0].size();
    cout << n << m;
    int dp[n+1][m+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if(A[j-1][i-1] == 0) {
                dp[j][i] = 0;
                 cout << dp[j][i] << " ";
            }
            else {
                dp[j][i] += dp[j-1][i] + 1;cout << dp[j][i] << " ";
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        int arr[n + 1], cnt = 0;
        memset(arr, 0, sizeof(arr));
        for (int j = 1; j <= m; ++j) {
            arr[dp[i][j]] ++;
            cout << arr[dp[i][j]] << " " ;
        }
        for (int j = n; j >= 0; --j) {
            cnt += arr[j];
            res = max(res, cnt * j);
        }
    }
    return res;
}

// Driver program
int main()
{
	vector<vector<int>> mat = { { 1,0,1 },
					{ 0,1,0 },
					{ 0, 0, 0} };
	cout << "Area of the largest rectangle is " << maxArea(mat);
	return 0;
}
