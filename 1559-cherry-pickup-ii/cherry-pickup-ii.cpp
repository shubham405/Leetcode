class Solution {
public:
     int dp[100][100][100];
    int f(int i, int j, int l, int n, int m ,vector<vector<int>>& grid)
    {
        if(i<0 || i>=n || j<0 || j>=m )
             return 0;
        if( l<0 || l>=m)
             return 0;
        if(dp[i][j][l]!=-1)
           return dp[i][j][l];
        int ans =0;
        if( j==l)
        {
            int v = grid[i][j];
            ans+=grid[i][j];
           // grid[i][j]=0;
            int mini  =0;
           for(int x =-1;x<=1;x++)
           {
               for(int y = -1;y<=1;y++)
               {
                   mini=max(mini,f(i+1,j+x,l+y,n,m,grid));
               }
           }
           ans+=mini;
           //grid[i][j]=v;
        }
        else
        {
            int v = grid[i][j], w = grid[i][l];
            // grid[i][j]=0;
            // grid[i][l]=0;
            ans+=v+w;
             int mini  =0;
           for(int x =-1;x<=1;x++)
           {
               for(int y = -1;y<=1;y++)
               {
                   mini=max(mini,f(i+1,j+x,l+y, n,m,grid));
               }
           }
           ans+=mini;
        //    grid[i][j]=v;
        //    grid[i][l]=w;

        }
        return dp[i][j][l]=ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n  =grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=  f(0,0,m-1,n,m,grid);

        return ans;

    
        
    }
};