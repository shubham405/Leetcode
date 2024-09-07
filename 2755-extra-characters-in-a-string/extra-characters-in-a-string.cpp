class Solution {
public:
    unordered_map<string,bool> mp;
    int dp[51][51];
    int f(int i, int j, string&s)
    {
        if(i>j)
          return 0;
        string t;
        int ans = INT_MAX;
        if(dp[i][j]!=-1)
            return dp[i][j];
        for(int x =i;x<=j;x++)
        {
            t.push_back(s[x]);
            if(mp[t])
            {
                ans = min(ans,f(x+1,j,s));
            }
            else
            {
                ans = min(ans,(int)t.size()+f(x+1,j,s));
            }
        }
        return dp[i][j]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {

        for(auto it:dictionary)
        {
            mp[it]=1;
        }
        memset(dp,-1,sizeof(dp));
        return f(0,s.size()-1,s);
        
    }
};