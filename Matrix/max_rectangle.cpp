#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int r = matrix.size();

        if (r == 0)
            return 0;
        int c = matrix[0].size();

        vector<vector<int>> mat(r + 1, vector<int>(c));
        for (int i = 1; i <= r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {

                mat[i][j] = matrix[i - 1][j] == '1' ? 1 : 0;
            }
        }
        vector<vector<int>> dp(r + 1, vector<int>(c));

        int mx = 0;
        for (int i = 1; i <= r; ++i)
        {
            int leftbound = -1;
            stack<int> st;
            vector<int> left(c);

            for (int j = 0; j < c; ++j)
            {
                if (mat[i][j] == 1)
                {
                    mat[i][j] = 1 + mat[i - 1][j];
                    while (!st.empty() and mat[i][st.top()] >= mat[i][j])
                        st.pop();

                    int val = leftbound;
                    if (!st.empty())
                        val = max(val, st.top());

                    left[j] = val;
                }
                else
                {
                    leftbound = j;
                    left[j] = 0;
                }
                st.push(j);
            }
            while (!st.empty())
                st.pop();

            int rightBound = c;
            for (int j = c - 1; j >= 0; --j)
            {
                if (mat[i][j] != 0)
                {
                    while (!st.empty() and mat[i][st.top()] >= mat[i][j])
                        st.pop();

                    int val = rightBound;
                    if (!st.empty())
                        val = min(val, st.top());

                    dp[i][j] = mat[i][j] * ((val - 1) - (left[j] + 1) + 1);
                    mx = max(mx, dp[i][j]);
                    st.push(j);
                }
                else
                {
                    dp[i][j] = 0;
                    rightBound = j;
                }
            }
        }

        return mx;
    }
};

int main()
{
    vector<vector<char>> vec = {
        {'0', '1', '1', '0'},
        {'1', '1', '1', '1'},
        {'1', '1', '1', '1'},
        {'1', '1', '0', '0'},
    };
    Solution obj;
    cout << obj.maximalRectangle(vec) << endl;
}