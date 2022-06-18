#include <bits/stdc++.h>
using namespace std;
int t[4][101] = {0};

int knapSack(int wt[], int val[], int n, int w)
{

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (wt[i - 1] <= j)
            {
                t[i][j] = max(val[i - 1] + t[i][j - wt[i - 1]], t[i - 1][j]);
            }
            else if (wt[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][w];
}

int main()
{
    int W = 100;
    int val[] = {10, 30, 20};
    int wt[] = {5, 10, 15};
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(wt, val, n, W);

    return 0;
}