#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int temp = 0;
    cin >> n >> m;
    vector<vector<int>> vec;

    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < m; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        vec.push_back(row);
    }
    

    int top = 0, right = vec[0].size() - 1, bottom = vec.size() - 1, left = 0, dir = 0;
  
    vector<int> ans;

    while (top <= bottom and left <= right)
    {
        if (dir == 0)
        {
            for (int i = left; i <= right; i++)
            {
                ans.push_back(vec[top][i]);
                
            }
            top++;
        }

        else if (dir == 1)
        {
            for (int i = top ; i <= bottom; i++)
                ans.push_back(vec[i][right]);
            right--;
        }

        else if (dir == 2)
        {
            for (int i = right; i >= left; i--)
                ans.push_back(vec[bottom][i]);
            bottom--;
        }
        else if (dir == 3)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(vec[i][left]);
            left++;
        }

        dir = (dir + 1) % 4;
    }

    for (auto i : ans)
        cout << i << " ";

    cout << endl;
}