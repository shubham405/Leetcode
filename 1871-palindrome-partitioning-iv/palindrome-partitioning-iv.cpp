class Solution {
public:
bool pal(string &s, int i, int j)
{
    
    while(i<j)
    {
        if(s[i]!=s[j])
           return false;
        i++;j--;
    }
    return 1;
}
int dp[4][2001];
bool find(string &s, int ind, int k)
    {
        if(k==1)
        {
            return pal(s, ind, s.size()-1);
        }
        if(dp[k][ind]!=-1)
            return dp[ind][k];
        bool ans = 0;
        for(int x = ind;x<s.size()-1;x++)
        {
            ans |= pal(s,ind,x) and find(s,x+1,k-1);
           
        }
        
        return dp[k][ind]=ans;
    }
    bool checkPartitioning(string s) {
        memset(dp,-1,sizeof(dp));
        return find(s,0,3);
    }
};