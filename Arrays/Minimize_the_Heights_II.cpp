#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int mini, maxi;
    int result = arr[n - 1] - arr[0];

    for (int i = 1; i <=n-1; i++)
    {
        // arr[i]=y
        // arr[i-1]=x
        if (arr[i] >= k)// height can't be negative 
        {
            maxi = max(arr[i - 1] + k, arr[n - 1] - k);
            mini = min(arr[0] + k, arr[i] - k);

            result = min(result, maxi - mini);
        }
    }
    cout << result << endl;
}