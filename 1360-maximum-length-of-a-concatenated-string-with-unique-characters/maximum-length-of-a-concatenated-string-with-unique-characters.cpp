class Solution {
public:
    bool check(string &s, vector<int> &mp)
    {
        bool ans = 1;
        for(auto it:s)
        {
            if(mp[it-'a'])
                 return 0;
            mp[it-'a']++;
        }
        return 1;
    }
    int dp[16][1<<16];
   int f(int i, int mask, vector<string>&arr)
   {
        if(i==arr.size())
           return 0;
        vector<int> mp(26,0);
        bool v = true;
        // put all the character in map;
        if(dp[i][mask]!=-1)
           return dp[i][mask];
        int ans = 0;
        for(int j =0;j<16;j++)
        {

            int x = 1<<j;
            if(x&mask)
            {
                string s =arr[j];
                for(auto it:s)
                {
                    if(mp[it-'a'])
                    {
                        v = 0;
                    }
                    else
                    {
                        mp[it-'a']++;
                    }
                }
            }
        }
       
      
            int x  = 1<<i;
            if(v and !(mask&x) and check(arr[i],mp))
            {
                ans = max(ans,(int)(arr[i].size()+f(i+1,mask|x,arr)));
            }
            ans = max(ans,f(i+1,mask,arr));
        return dp[i][mask]=ans;
        
   }
    int maxLength(vector<string>& arr) {
        memset(dp,-1,sizeof(dp));
        return f(0,0,arr);
    }
};