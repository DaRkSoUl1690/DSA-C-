// A O(n^2) time and O(1) space program to
// find the longest palindromic substring
#include <bits/stdc++.h>
using namespace std;

// A utility function to print
// a substring str[low..high]
// This function prints the
// longest palindrome substring (LPS)
// of str[]. It also returns the
// length of the longest palindrome
int longestPalSubstr(char *str)
{
    // The result (length of LPS)
    int maxLength = 1;

    int start = 0;
    int len = strlen(str);

    int low, high;

    // One by one consider every
    // character as center point of
    // even and length palindromes
    for (int i = 1; i < len; ++i)
    { //forgeeksskeegfor//aaabbaa
        // Find the longest even length palindrome
        // with center points as i-1 and i.
        low = i - 1;
        high = i;
        cout << low << " " << high << endl;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            --low;
            ++high;
        }
        cout << low << " " << high << endl;
        // Move back to the last possible valid palindrom substring
        // as that will anyway be the longest from above loop
        ++low;
        --high;
        cout << low << " " << high << endl;
        if (str[low] == str[high] && high - low + 1 > maxLength)
        {
            start = low;
            maxLength = high - low + 1;
        }
        cout << low << " " << high << endl;

        //---------------------------------------------------------------
        // Find the longest odd length
        // palindrome with center point as i
        low = i - 1;
        high = i + 1;
        cout << low << " " << high << endl;
        while (low >= 0 && high < len && str[low] == str[high])
        {
            --low;
            ++high;
        }
        cout << low << " " << high << endl;
        // Move back to the last possible valid palindrom substring
        // as that will anyway be the longest from above loop
        ++low;
        --high;
        cout << low << " " << high << endl;
        if (str[low] == str[high] && high - low + 1 > maxLength)
        {
            start = low;
            maxLength = high - low + 1;
        }
        cout << low << " " << high << endl
             << endl;
        
    }

    cout << "Longest palindrome substring is: ";
    int ans = maxLength;
    while (ans--)
        cout << str[start++];

    return maxLength;
}

// Driver program to test above functions
int main()
{
    char str[] = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str)
         << endl;
    return 0;
}

// This is code is contributed by rathbhupendra
