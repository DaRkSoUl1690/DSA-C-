// video tutorial https://www.youtube.com/watch?v=keVevSvaDKo

// C++ program to find maximum product subarray
#include <bits/stdc++.h>
using namespace std;

// Function to find maximum product subarray
int maxProduct(int *arr, int n)
{
    // Variables to store maximum and minimum
    // product till ith index.
    int minVal = arr[0];
    int maxVal = arr[0];

    int maxProduct = arr[0];
    int choice1, choice2;
    for (int i = 1; i < n; i++)
    {
        choice1 = minVal * arr[i];
        choice2 = maxVal * arr[i];

        maxVal = max(arr[i], max(choice1, choice2));
        minVal = min(arr[i], min(choice1, choice2));

        maxProduct = max(maxProduct, maxVal);
    }

    // Return maximum product found in array.
    return maxProduct;
}

// Driver Code
int main()
{
    int arr[] = {-1, -3, -10, 0, 60};

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum Subarray product is "
         << maxProduct(arr, n) << endl;

    return 0;
}
