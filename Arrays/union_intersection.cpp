// CPP program to find union and intersection
// using sets
#include <bits/stdc++.h>
using namespace std;

// Prints union of arr1[0..n1-1] and arr2[0..n2-1]
void printUnion(int arr1[], int arr2[], int n1, int n2)
{
	set<int> hs;

	// Insert the elements of arr1[] to set hs
	for (int i = 0; i < n1; i++)
		hs.insert(arr1[i]);

	// Insert the elements of arr2[] to set hs
	for (int i = 0; i < n2; i++)
		hs.insert(arr2[i]);

	// Print the content of set hs
	for (auto it = hs.begin(); it != hs.end(); it++)
		cout << *it << " ";
	cout << endl;
}

// Prints intersection of arr1[0..n1-1] and
// arr2[0..n2-1]
void printIntersection(int arr1[], int arr2[], int n1,
					int n2)
{
	set<int> hs;

	// Insert the elements of arr1[] to set S
	for (int i = 0; i < n1; i++)
		hs.insert(arr1[i]);

	for (int i = 0; i < n2; i++)

		// If element is present in set then
		// push it to vector V
		if (hs.find(arr2[i]) != hs.end())
			cout << arr2[i] << " ";
}

// Driver Program
int main()
{
	int arr1[] = { 7, 1, 5, 2, 3, 6 };
	int arr2[] = { 3, 8, 6, 20, 7 };
	int n1 = sizeof(arr1) / sizeof(arr1[0]);
	int n2 = sizeof(arr2) / sizeof(arr2[0]);

	// Function call
	printUnion(arr1, arr2, n1, n2);
	printIntersection(arr1, arr2, n1, n2);

	return 0;
}

// this method used for union intersection by mapping 
// // C++ program for the above approach
// #include <bits/stdc++.h>
// using namespace std;
// void printUnion(int a[], int n, int b[], int m)
// {
	
// 	// Defining map container mp
// 	map<int, int> mp;

// 	// Inserting array elements in mp
// 	for (int i = 0; i < n; i++)
// 		mp[a[i]]++;

// 	for (int i = 0; i < m; i++)
// 		mp[b[i]]++;
// 	cout << "The union set of both arrays is :" << endl;
// 	for (auto itr = mp.begin(); itr != mp.end(); itr++)
// 		cout << itr->first
// 			<< " "; // mp will contain only distinct
// 					// elements from array a and b
// }

// // Driver Code
// int main()
// {
// 	int a[7] = { 1, 2, 5, 10, 2, 3, 5 };
// 	int b[10] = { 2, 4, 5, 6, 8, 9, 4,7, 6, 5};

// 	printUnion(a, 7, b, 9);
// }
