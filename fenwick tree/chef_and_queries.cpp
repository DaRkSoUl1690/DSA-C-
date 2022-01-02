#include <bits/stdc++.h>
using namespace std;
#define int long long

// Template taken from cp-algorithms
struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0ll);
    }

    void add(int idx, int val)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += val;
    }

    void range_add(int l, int r, int val)
    {
        add(l, val);
        add(r + 1, -val);
    }

    int get(int idx)
    { //
        int ret = 0;
        for (++idx; idx > 0ll; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

void solve()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    FenwickTree B1(n), B2(n), B3(n);

    while (q--)
    {
        int type;
        ;
        cin >> type;
        if (type == 1)
        {
            int l, r, x;
            cin >> l >> r >> x;
            int y = x - l;
            l--, r--;
            B1.range_add(l, r, y * y);
            B2.range_add(l, r, y * 2);
            B3.range_add(l, r, 1ll);
        }
        else
        {
            int i;
            cin >> i;
            int ans = a[i - 1] + B1.get(i - 1) + i * B2.get(i - 1) + i * i * B3.get(i - 1);
            cout << ans << '\n';
        }
    }
}

signed main()
{

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}