class Solution {
public:
    int dp[101][101];
   int pal(string &s, int i, int j)
   {
    int count =0 ;
      while(i<j)
      {
        if(s[i]!=s[j])
        {
            count++;
        }
        i++;
        j--;
      }
      return count;
   }
    int find(string &s, int ind, int k)
    {
        if(k==1)
        {
            return pal(s, ind, s.size()-1);
        }
        if(dp[ind][k]!=-1)
            return dp[ind][k];
        int ans = 1e9;
        for(int x = ind;x<s.size()-1;x++)
        {
            ans = min(ans,pal(s,ind,x)+find(s,x+1,k-1));
        }
        
        return dp[ind][k]=ans;
    }
    int palindromePartition(string s, int k) {
        memset(dp,-1,sizeof(dp));
        return find(s,0,k);
        
    }
};