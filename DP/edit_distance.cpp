class Solution {
public:
     vector<vector<int>> dp;
    int minDistance(string word1, string word2) {
          dp = vector<vector<int>>(word1.size(), vector<int>(word2.size(),-1));
       return dp2(word1, word2, 0, 0);
    }
   int dp2(string& w1, string& w2, int p1, int p2){
       
        if(p1 >= w1.size()){
            return w2.size() - p2;
        }
        if(p2 >= w2.size()){
            return w1.size()-p1;
        }
        
        if(dp[p1][p2] != -1){
            return dp[p1][p2];
        }
        
        if(w1[p1] != w2[p2]){
            return dp[p1][p2] = 1 + min({
                dp2(w1,w2,p1+1,p2), //delete
                dp2(w1,w2,p1,p2+1), //insert
                dp2(w1,w2,p1+1,p2+1) // Replace
                });
        }
        return dp[p1][p2] = dp2(w1,w2,p1+1,p2+1);
    }
};