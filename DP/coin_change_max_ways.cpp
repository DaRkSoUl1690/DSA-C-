
#include <bits/stdc++.h>
using namespace std;
int subset[4][5] = {0};

int coinchange(vector<int> arr, int sum)
{

    for (int i = 0; i <= arr.size(); i++)
        subset[i][0] = 1;

    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            if (j >= arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j] + subset[i][j - arr[i - 1]];
            }
            else if (j < arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j];
            }
        }
    }

    for (int i = 0; i <= arr.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            cout << subset[i][j] << " ";
        }
        cout << endl;
    }
    return subset[arr.size()][sum];
}

int main()
{
    int n, v;
    n = 3, v = 4;
    vector<int> a = {1, 2, 3};
    int res = coinchange(a, v);
    cout << res << endl;
    return 0;
}
