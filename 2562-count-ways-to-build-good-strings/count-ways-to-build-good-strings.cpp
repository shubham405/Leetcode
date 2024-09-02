class Solution {
public:
  int dp[100005];
  int mod = 1e9+7;
  int f( int z, int o, int c)
  {
     if(c == 0 )
     {
        return 1;
     }
     if(dp[c]!=-1)
        return dp[c];
     int ans = 0 ; 
     if(c>=z)
     {
        ans += f(z,o,c-z)%mod;
     }
     if(c>=o)
     {
         ans += f(z,o,c-o)%mod;  
     }
     return dp[c]=ans%mod;
  }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        memset(dp,-1,sizeof(dp));
        for(int i  =low;i<=high;i++)
        {
            ans+=f(zero,one,i)%mod;
            ans%=mod;
        }
        return ans;
    }
};