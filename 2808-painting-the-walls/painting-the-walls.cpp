class Solution {
public:
    int dp[501][501];
    int f(int i, int wall, vector<int>& cost, vector<int>& time)
    {
         if(wall<=0)
            return 0;
         if(i>=time.size())
            return 1e9;
        if(dp[i][wall]!=-1)
           return dp[i][wall];
        int p = cost[i]+f(i+1,wall-1-time[i],cost,time);
        int np = f(i+1,wall,cost,time);
        return dp[i][wall]=min(p,np);
        
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return f(0,time.size(),cost,time);
        
    }
};