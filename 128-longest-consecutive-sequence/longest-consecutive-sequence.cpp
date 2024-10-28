class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        {
            mp[it]++;
        }
        int ans =0;
        for(auto it: nums)
        {
            if(mp[it-1]==0)
            {
                int count = 0;
                while(mp[it++])
                {
                    count++;
                }
                ans = max(ans,count);
            }
        }
        return ans;
    }
};