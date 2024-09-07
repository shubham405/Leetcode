class Solution {
public:
int dp[202][101][101];
 bool f(int i, int j, int k, string s1, string s2, string s3)
 {
    if(s3.size()==i)
    {   if(j==s1.size() and k==s2.size())
            return 1;
        return 0;
    }
       
    if(j==s1.size() and k==s2.size())
        return 0;
    bool ans = 0;
    if(dp[i][j][k]!=-1)
       return dp[i][j][k];
    if(j<s1.size() and s1[j]==s3[i])
    {
        ans|=f(i+1,j+1,k,s1,s2,s3);
    }
    if(k<s2.size() and s2[k]==s3[i])
    {
        ans|=f(i+1,j,k+1,s1,s2,s3);
    }
  
    return dp[i][j][k]=ans;
 }
    bool isInterleave(string s1, string s2, string s3) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,0,s1,s2,s3);
        
    }
};