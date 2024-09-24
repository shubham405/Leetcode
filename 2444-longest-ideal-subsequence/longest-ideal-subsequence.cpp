class Solution {
public:
    int longestIdealString(string s, int k) {
        
        int n = s.size(), ans  = 1;;
        vector<int> dp(n,0), temp(26,0);
        for(int i =0;i<n;i++)
        {
            int cur = s[i]-'a';
            int low = max(cur-k,0);
            int high = min(cur+k,25);
            int maxi = 0;
            for(int j = low;j<=high;j++)
            {
               maxi = max(maxi,temp[j]);
            }
            temp[cur] = max(temp[cur],maxi+1);
            ans = max(ans,temp[cur]);
        }
        // for(auto it:temp)
        // {
        //     cout<<it<<" ";
        // }
        return ans;
    }
};