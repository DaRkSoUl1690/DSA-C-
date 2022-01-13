class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        vector<int> mpp(256, -1);
        int maxSize = 0, i = 0, j = 0, n = s.size();

        while (j < n)
        {

            if (mpp[s[j]] != -1)
                i = max(mpp[s[j]] + 1, i);
            // cout<<mpp[s[j]]<<" ";
            // cout<<i<<" ";

            mpp[s[j]] = j;
            // cout<<j<<" ";
            maxSize = max(maxSize, j - i + 1);

            j++;
        }
        return maxSize;
    }
};