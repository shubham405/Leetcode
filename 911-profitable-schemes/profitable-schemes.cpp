class Solution {
public:
int mod = 1e9+7;
int dp[101][101][101];
  int f(int i, int n, int mini,vector<int>& profit, vector<int>& group )
  {
    if(i>=group.size())
    {
        return mini<=0;
    }
    int ans =0;
    if(dp[i][n][mini]!=-1)
       return dp[i][n][mini];
    if(group[i]<=n)
    {
        ans+=f(i+1,n-group[i],max(0,mini-profit[i]),profit,group);
    }
    ans+=f(i+1,n,mini,profit,group);
    return dp[i][n][mini]=ans%mod;
  }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        memset(dp,-1,sizeof(dp));
        return f(0,n,minProfit,profit,group);
    }
};