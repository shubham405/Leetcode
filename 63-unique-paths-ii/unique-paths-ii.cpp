class Solution {
public:
   int f(int n, int m, vector<vector<int>>& grid, vector<vector<int>> &dp)
    {
        if(n==0 && m==0)
        {
            if(grid[n][m])
               return 0;
            return 1;
        }
            
        if(n<0 || m<0)
        {
            return 0;
        }
        if(dp[n][m]!=-1)
           return dp[n][m];
        if(grid[n][m])
           return 0;
        int ways =0;
        ways+=f(n-1,m,grid,dp);
        ways+=f(n,m-1,grid,dp);
        return dp[n][m]=ways;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        int n = obstacleGrid.size(),m =obstacleGrid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return f(n-1,m-1,obstacleGrid,dp);
        
    }
};