#include <bits/stdc++.h>
using namespace std;

bool findPartiion(int arr[], int n)
{
    int sum = 0;
    int i, j;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    if (sum % 2 != 0)
        return false;

    bool t[n + 1][sum / 2 + 1];
    for (i = 0; i <= n; i++)
        t[i][0] = true;

    for (i = 1; i <= sum / 2; i++)
        t[0][i] = false;

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum / 2; j++)
        {
            if (arr[i - 1] <= j)
            {
                t[i][j] = t[i - 1][j] or t[i - 1][j - arr[i - 1]];
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }

    return t[n][sum / 2];
}

int main()
{
    int arr[] = {3, 1, 5, 9, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    if (findPartiion(arr, n) == true)
        cout << "Can be divided into two subsets "
                "of equal sum";
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";
    return 0;
}