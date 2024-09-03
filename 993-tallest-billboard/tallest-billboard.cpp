class Solution {
public:
    int dp[21][10003];
    int f(int i, int diff,vector<int>& rods)
    {
        if(i==rods.size())
        {
            if(diff==0)
              return 0;
            return -1e9;
        }
        
        if(dp[i][diff+5000]!=-1)
            return dp[i][diff+5000];
       int ans =-1e9;
       ans = max(ans,f(i+1,diff,rods));
       ans = max(ans,rods[i]+f(i+1,diff+rods[i],rods));
       ans = max(ans,rods[i]+f(i+1,diff-rods[i],rods));
       return  dp[i][diff+5000]=ans;
    }
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        return max(f(0,0,rods)/2,0);
        
    }
};