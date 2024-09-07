class Solution {
public:
int dp[101][101];
   int f(int i, int j, string &s)
   {
      if(i==j)
         return 1;
      if(i>j)
         return 0;
      int x = i+1;
      if(dp[i][j]!=-1)
          return dp[i][j];
      while(x<=j and s[x]==s[i])
      {
        x++;
      }
      if(x==j+1)
        return 1;
      int ans = 1+f(x,j,s);
     
      for(int m = x;m<=j;m++)
      {
          if(s[m]==s[i])
          {
            ans = min(ans,f(x,m-1,s)+f(m,j,s));
          }
      }
      return dp[i][j] = ans;
   }
    int strangePrinter(string s) {
        memset(dp,-1,sizeof(dp));
        return f(0,s.size()-1,s);
    }
};