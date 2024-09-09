class Solution {
public:
    unordered_map<int, vector<int>> mp;
    int dp[10][5001];
    int mod = 1e9+7;
    int f(int i, int n)
    {
        if(n==1)
        {
            return 1;
        }
        int ans = 0;
        if(dp[i][n]!=-1)
           return dp[i][n];
        for(auto it:mp[i])
        {
            ans+=f(it,n-1);
            ans%=mod;
        }
        return dp[i][n]=ans%mod;
    }
    int knightDialer(int n) {
        if(n==1)
           return 10;
        mp[0] = {4,6};
        mp[1] = {8,6};
        mp[2] = {7,9};
        mp[3] = {4,8};
        mp[4]= {3,9,0};
         mp[6] = {7,1,0};
         mp[7]={6,2};
         mp[8]={1,3};
         mp[9] = {4,2};
         int ans = 0 ;
         memset(dp,-1,sizeof(dp));
         for(int i = 0;i<10;i++)
         {
            if(i!=5)
            {
                ans+=f(i,n);
                ans%=mod;
            }
         }
         return ans;
    }
};