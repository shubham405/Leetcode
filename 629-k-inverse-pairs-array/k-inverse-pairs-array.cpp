class Solution {
public:
int dp[1001][1001];
int mod = 1e9+7;
  int f(int n, int k)
  {
     if(k==0)
       return 1;
    // if(k>n)
    //   return 0;
    if(dp[n][k]!=-1)
        return dp[n][k];
    int ans = 0;
    for(int inv =0;inv<= min(k,n-1);inv++)
    {
        ans+=f(n-1,k-inv);
        ans%=mod;
    }
    return dp[n][k]=ans%mod;
  }
    int kInversePairs(int n, int k) {
        memset(dp,-1,sizeof(dp));
        return f(n,k);
    }
};