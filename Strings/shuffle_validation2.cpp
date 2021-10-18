#include <bits/stdc++.h>
using namespace std;
#include <string>
bool help(string s1, string s2, string s)
{
    int i = s1.length();
    int j = s2.length();
    int k = s.length();
    if (i + j != k)
        return false;
    i = 0;
    j = 0;
    k = 0;
    while (k < s.length())
    {
        int f = 0;
        if (i < s1.length() && s1[i] == s[k])
        {
            f = 1;
            i++;
            k++;
        }
        if (j < s2.length() && s2[j] == s[k])
        {
            f = 1;
            j++;
            k++;
        }
        if (f == 0)
            return false;
    }

    return true;
}
int main()
{
    string s, s1, s2;
    cin >> s1 >> s2 >> s;
    cout << help(s1, s2, s);
    return 0;
}