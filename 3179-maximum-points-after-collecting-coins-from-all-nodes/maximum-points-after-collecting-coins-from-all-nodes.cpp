class Solution {
public:
    int dp[100001][15];
    int f(int node, int t, int k,int par, vector<int> adj[],vector<int>& coins)
    {
        int ans = 0;
        if(t>=14)
        {
            return 0;
        }
        if(dp[node][t]!=-1)
             return dp[node][t];
       
            
            int ans1 = (coins[node])/pow(2,t)-k;
            int ans2 = coins[node]/pow(2,t+1);
            for(auto it:adj[node])
            {
                if(it!=par)
                {
                    ans1=ans1+f(it,t,k,node,adj,coins);
                    ans2  = ans2+f(it,t+1,k,node,adj,coins);
                }
                
            }
            ans = max(ans1,ans2);
        
        return dp[node][t] = ans;

    }
    int maximumPoints(vector<vector<int>>& edges, vector<int>& coins, int k) {
        
        int n  = coins.size();
        vector<int> adj[n], vis(n,0);
        for(auto it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        memset(dp,-1,sizeof(dp));
        return f(0,0,k,-1,adj,coins);
    }
};