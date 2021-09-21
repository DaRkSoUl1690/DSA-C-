
// https://www.youtube.com/watch?v=-NTaXJ7BBXs 
// try one more time 
#include <bits/stdc++.h>
using namespace std;

int minCoins(int n, int a[], int dp[],int m)
{
    
    if (n == 0)
        return 0;
      int ans = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        if (n - a[i] >= 0)
        {
            int subAns = 0;
            if (dp[n - a[i]] != -1)

                subAns = dp[n - a[i]];

            else

                subAns = minCoins(n - a[i], a, dp ,m);

            if (subAns != INT_MAX and subAns + 1 < ans)

                ans = subAns + 1;
        }
    }

  
    return dp[n]= ans;
}

int main()
{
   int n,m;cin>>n>>m;int a[n];
  for (int i = 0; i < m; i++)
  {
      cin>>a[i];
  }
  
    int dp[n + 1];
    fill(dp, dp + n + 1, -1);
    dp[0] = 0;

    int ans = minCoins(n, a, dp,m);
    cout << ans << endl;

    for(auto x:dp)
    cout<<x<<" ";
    }