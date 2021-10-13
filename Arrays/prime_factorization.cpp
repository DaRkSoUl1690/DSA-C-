#include <bits/stdc++.h>
using ll = long long;
#define mod 1000000007
using namespace std;

int main()
{

        int n;
        cin >> n;
        int root = int(sqrt(n));
        for (int i = 2; i<=root; i++)
        {if(n%i==0){ 
            int cnt = 0;
            while (n % i == 0)
            {
                n /= i;
                cnt++;
            }
            cout << i << "^" << cnt << ' ';
        }
        
        }
       if(n>1)
           cout << n << "^" << 1;

    return 0;
}