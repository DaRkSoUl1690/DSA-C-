// C++ program for the above approach
#include <bits/stdc++.h>
using namespace std;

// Find all subsequences
void printSubsequence(string input, string output)
{   // Base Case
    // if the input is empty print the output string
    cout << "the input and output:"<<"1."<<input << " 2." << output << endl;
    
    if (input.empty())
    {
        cout << endl;
        cout << output << endl;
        return;
    }
    /** output is passed with including
     the Ist character of
     Input string*/
    cout << "call-1" << endl;
    printSubsequence(input.substr(1), output + input[0]);
    // output is passed without
    // including the Ist character
    // of Input string
    cout << "call-2" << endl;
    printSubsequence(input.substr(1), output);
}

// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abcd";

    printSubsequence(input, output);

    return 0;
}
