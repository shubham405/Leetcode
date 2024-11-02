class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> mp;
        mp[0]=1;
        int ans= 0, sum=0;
        for(auto it:nums)
        {
            sum+=it%2;
            ans+=mp[sum-k];
            mp[sum]++;
        }
        return ans;


        
    }
};