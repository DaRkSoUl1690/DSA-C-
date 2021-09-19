#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int start, int end)
{
    if (start >= end)
        return;

    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recursive Function calling
    reverse(arr, start + 1, end - 1);
}

/* Utility function to print an array */
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";

    cout << endl;
}

/* Driver function to test above functions */
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Function calling
    reverse(arr, 0, n - 1);

    cout << "Reversed array is" << endl;

    // To print the Reversed array
    printArray(arr, n);

    return 0;
}