class Solution {
public:
int dp[205][205];
    int f(int i, int j, vector<vector<int>> &grid, int n, int m)
    {
        if(i>=n)
        {
            return 0;
        }
        if(dp[i][j+1]!=-1)
           return dp[i][j+1];
        int ans = INT_MAX;
        for(int x = 0;x<m;x++)
        {
            if(x!=j)
            {
                ans = min(ans, grid[i][x]+f(i+1,x,grid,n,m));
            }
        }

        return dp[i][j+1]=ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return f(0,-1,grid,n,m);
    }
};