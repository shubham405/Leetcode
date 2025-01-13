class Solution {
    int dp[501][501][3];
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        memset(dp,0,sizeof(dp));
        dp[0][0][0] = coins[0][0];
        dp[0][0][1] = max(0,coins[0][0]);
        dp[0][0][2] = max(0,coins[0][0]);
        for(int i =0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 and j ==0)
                {
                    continue;
                }
                for(int k = 0 ; k<3;k++)
                {
                    int ans = -1e9;
                        if(i>0)
                        {
                            ans = max(ans,dp[i-1][j][k]);
                        }
                        if(j>0)
                        {
                            ans = max(ans,dp[i][j-1][k]);
                        }
                    if(k==0 || coins[i][j]>=0)
                    {
                        dp[i][j][k] = ans+coins[i][j];
                    }
                    else
                    {
                        dp[i][j][k] = max({ans+coins[i][j], i>0?dp[i-1][j][k-1]:(int)-1e9, j>0? dp[i][j-1][k-1]:(int)-1e9});
                    }
                }

            }
        }
        return max({dp[n-1][m-1][0],dp[n-1][m-1][1],dp[n-1][m-1][2]});
        
    }
};