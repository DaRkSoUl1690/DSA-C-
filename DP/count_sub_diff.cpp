
#include <bits/stdc++.h>
using namespace std;

int subsetSum(int a[], int n, int sum)
{
    int dp[n + 1][sum + 1];
    dp[0][0] = 1;
    for (int i = 1; i <= sum; i++)
        dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (a[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - a[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main()
{
    int arr[] = {3, 1, 4, 2, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int dif = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    int reqSum = (dif + sum) / 2;

    cout << "The minimum difference between 2 sets is "
         << subsetSum(arr, n, reqSum);
    return 0;
}
