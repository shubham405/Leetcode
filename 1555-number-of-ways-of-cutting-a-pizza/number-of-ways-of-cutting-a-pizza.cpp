class Solution {
public:
    int mod  = 1e9+7;
    int dp[11][50][50];
    int f(int i, int j, int k,vector<string>& pizza)
    {
         if(i>=pizza.size() || j>=pizza[0].size())
           return 0;
        if(k==1)
          {
            
            for(int x = i; x<pizza.size();x++)
            {
                for(int y = j;y<pizza[0].size();y++)
                {
                    if(pizza[x][y]=='A')
                       return 1;
                }
            }
            
            return 0;
          }

       if(dp[k][i][j]!=-1)
          return dp[k][i][j]%mod;
        int cr=0, cc =0;
        int ans =0;
        for(int x = i;x<pizza.size();x++)
        {
           
            for(int  y = j;y<pizza[0].size();y++)
            {
                if(pizza[x][y]=='A')
                {
                    cr++;
                }
            }
            if(cr)
            {
                ans+=f(x+1,j,k-1,pizza)%mod;
                ans%=mod;
               
            }
        }
        //  vertical cut
        for(int x = j;x<pizza[0].size();x++)
        {
            for(int  y = i;y<pizza.size();y++)
            {
                if(pizza[y][x]=='A')
                {
                    cc++;
                }
            }
            if(cc)
            {
                 ans+=f(i,x+1,k-1,pizza)%mod;
                 ans%=mod;
            }
        }
        return dp[k][i][j]=ans%mod;
    }
    int ways(vector<string>& pizza, int k) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,k,pizza);
        
    }
};