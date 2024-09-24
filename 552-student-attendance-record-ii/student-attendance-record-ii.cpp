class Solution {
    int mod  = 1e9+7;
    int findReward( int n, int absent, int cntLate,vector<vector<vector<int>>> &dp)
    {
        if(absent>=2 || cntLate>=3)
             return 0;

       if(n==0)
          return 1;
        if(dp[n][absent][cntLate]!=-1)
             return dp[n][absent][cntLate]%mod;
        int ways=0;
        ways =  (ways%mod + findReward(n-1,absent,0,dp)%mod)%mod;
        ways = (ways%mod + findReward(n-1,absent+1,0,dp)%mod)%mod;
        ways  =  (ways%mod + findReward(n-1,absent,cntLate+1,dp)%mod)%mod;

        return dp[n][absent][cntLate]=ways%mod;
      
          
    }
public:
    int checkRecord(int n) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return findReward(n,0,0,dp);
    }
};