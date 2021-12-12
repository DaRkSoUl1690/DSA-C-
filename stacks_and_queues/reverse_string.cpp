#include <bits/stdc++.h>
using namespace std;
void reverse(char *str)
{
    stack<char> s;

    for (int i = 0; i < strlen(str); ++i)
    {
        s.push(str[i]);
    }

    for (int i = 0; i < strlen(str); ++i)
    {
        str[i] = s.top();
        s.pop();
    }
}

int main()
{
    char str[] = "HELLO WORLD";

    reverse(str);
    cout << "Reversed string is " << str;

    return 0;
}