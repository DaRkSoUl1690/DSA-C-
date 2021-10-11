// https://www.youtube.com/watch?v=1qD1FLhKrIE&t=268s

#include <bits/stdc++.h>
        using namespace std;

int LongestIncreasingSubsequenceLength(int n,int *a)
{
    int dp[n + 1];
    for (int i = 1; i <= n ; i++)
   dp[i]=INT_MAX;
   dp[0]=INT_MIN;
   
   for (int i = 0; i < n; i++)
   {
       int idx = upper_bound(dp, dp + n + 1, a[i])-dp;
       cout << idx <<" ";
       if(a[i]>dp[idx-1] and a[i]<dp[idx])
       dp[idx] = a[i];
   }
   
   int ma = 0;

   for (int i = n; i >=0; i--)
   {
      
       if (dp[i] != INT_MAX)
       {
           ma = i;
           break;
      }
   }
   return ma;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++)
        cin >> a[i];
        cout << LongestIncreasingSubsequenceLength(n, a) << endl;
    return 0;
}
// vector<int> dp(n + 1, INT_MAX);
// dp[0] = INT_MIN;

// for (int i = 0; i < n; ++i)
// {
//     int idx = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
//     dp[idx] = min(dp[idx], a[i]);
// }

// int ans = 0;

// for (int i = n; i >= 0; --i)
// {
//     if (dp[i] != INT_MAX)
//     {
//         ans = i;
//         break;
//     }
// }

// return ans;