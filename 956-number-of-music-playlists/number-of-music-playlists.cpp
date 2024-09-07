class Solution {
  #define ll long long
  ll mod = 1e9+7;
  ll dp[105][105];
  ll f(ll us, ll sp, ll k, ll goal, ll n)
  {
    if(us>n)
        return 0;
    if(sp==goal)
    {
        if(us==n)
        return 1;
        return 0;
    }
    if(dp[sp][us]!=-1)
    return dp[sp][us];
           int play = 0, np=0;
     play+= ((n-us)*f(us+1,sp+1,k,goal,n)%mod)%mod;
     np+= (max(us-k,0ll)*f(us,sp+1,k,goal,n)%mod)%mod;

     return dp[sp][us]=(play%mod+np%mod)%mod;
  }

public:
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,k,goal,n);
    }
};