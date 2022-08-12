 int mod=1e9+7;
    long long int f(int n, vector<long long int> &dp){
        if(n<=2) return n;
        if(dp[n]!=-1) return dp[n];
        int single=f(n-1,dp);
        int pairedup=((n-1)%mod*f(n-2,dp)%mod)%mod;
        return dp[n]=((single)%mod+(pairedup)%mod)%mod;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long int> dp(n+1,-1);
        return f(n,dp);
        
    }