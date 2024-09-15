class Solution {
    bool isPalindrome(string &s, int i, int j)
    {
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }
    int find(int indexi,int indexj ,string &s,vector<vector<int>> &dp)
    {
        
         //cout<<index<<endl;
         if(indexi>indexj)
         {
             return 0;
         }
         if(indexi==indexj)
         {
             return 1;
         }

         if(dp[indexi][indexj]!=-1)
            return dp[indexi][indexj];

         int ans= 0;
        if(isPalindrome(s,indexi,indexj))
        {
            ans = 1+find(indexi+1,indexj,s,dp)+find(indexi,indexj-1,s,dp)-find(indexi+1,indexj-1,s,dp);
        }
        else
        {
            ans = find(indexi+1,indexj,s,dp)+find(indexi,indexj-1,s,dp)-find(indexi+1,indexj-1,s,dp);
        }

        return dp[indexi][indexj]=ans;
    }
public:
    int countSubstrings(string s) {

        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int ans=0;
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n ; i++)
            {
                int j = i+L-1;
                if(i==j)
                {
                    dp[i][j]=1;
                }
                else if(i+1==j)
                {
                    dp[i][j] = s[i]==s[j];
                }
                else
                {
                    dp[i][j] = s[i]==s[j] and dp[i+1][j-1];
                }
                if(dp[i][j])
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};