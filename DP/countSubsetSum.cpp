#include <bits/stdc++.h>
using namespace std;
int subset[5][7] = {0};

int CountSubsetSum(vector<int> arr, int sum)
{

    for (int i = 0; i <= arr.size(); i++)
        subset[i][0] = 1;

    for (int i = 1; i <= arr.size(); i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            if (j >= arr[i - 1])
            {
                subset[i][j] = subset[i - 1][j] + subset[i - 1][j - arr[i - 1]];
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
    vector<int> arr = {3, 3, 3, 3};
    cout << CountSubsetSum(arr, 6);
}