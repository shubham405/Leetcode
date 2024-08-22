class Solution {
public:
    int dp[1001][2001];
    int f(int i,vector<vector<int>>& piles, int k )
    {
        if(k==0 || i >=piles.size())
          return 0;
        int ans = 0 ,sum=0; 
        if(dp[i][k]!=-1)
           return dp[i][k];  
          for(int x = 0;x<piles[i].size();x++)
          {
            sum+=piles[i][x];
            if(x<k)
            {
                 ans = max(ans,sum+f(i+1,piles,k-(x+1)));
            }
             
          }
            
        
        ans = max(ans,f(i+1,piles,k));
        return dp[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
            memset(dp,-1,sizeof(dp));
            return f(0,piles,k);
    }
};