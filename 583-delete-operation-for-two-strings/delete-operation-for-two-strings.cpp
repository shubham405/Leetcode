class Solution {
public:

    int lcs(string &s1,string &s2, int index1, int index2,vector<vector<int>> &dp)
    {
        if(index1<0 || index2<0)
            return 0;
        if(dp[index1][index2]!=-1)
            return dp[index1][index2];
        if(s1[index1]==s2[index2])
        {
             return (1+lcs(s1,s2,index1-1, index2-1,dp));
        }
          
        return  dp[index1][index2]=max(lcs(s1,s2,index1, index2-1,dp),lcs(s1,s2,index1-1, index2,dp));
    }
    int minDistance(string word1, string word2) {
        
        int  n = word1.size() , m = word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int lc = lcs(word1,word2,n-1,m-1,dp);
        return n-lc+m-lc;
    }
};