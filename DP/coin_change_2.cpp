#include <bits/stdc++.h>
using namespace std;
int t[5][12] = {0};

int minCoinChange(int coins[], int sum, int m)
{
    for (int i = 0; i <= sum; i++)
    {
        t[0][i] = INT_MAX - 1;
    }

    for (int i = 1; i <= sum; i++)
    {
        if (i % coins[0] == 0)
        {
            t[1][i] = i / coins[0];
        }
        else
            t[1][i] = INT_MAX - 1;
    }

    for (int i = 2; i <= m; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (coins[i - 1] <= j)
            {
                t[i][j] = min(1 + t[i][j - coins[i - 1]], t[i - 1][j]);
            }
            else if (coins[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    // for (int i = 0; i <= m; i++)
    // {
    //     for (int j = 0; j <= sum; j++)
    //     {
    //         cout << t[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return t[4][11];
}

int main()
{
    int coins[] = {9, 6, 5, 1};
    int m = sizeof(coins) / sizeof(coins[0]);
    int V = 11;
    cout << minCoinChange(coins, V, m) << endl;
}