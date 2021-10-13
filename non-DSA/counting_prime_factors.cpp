#include <bits/stdc++.h>
using ll = long long;
#define mod 1000000007
using namespace std;

int main()
{

    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int even = 0, odd = 0;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                n /= i;
                (i % 2 == 0 ? even : odd)++;
            }
        }
        if (n > 1)
            (n % 2 == 0 ? even : odd)++;
        cout << even << " " << odd << endl;
    }
    return 0;
}