class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {

        unordered_map<int,int> mp;
        for(int i =0;i<nums.size();i++)
        {
            mp[nums[i]]=i;
        }
        int j=0, ans =1, mod=1e9+7;
        for(int i = 0 ; i <nums.size();i++)
        {
            if(i>j)
            {
                ans*=2;
                ans%=mod;
            }
            j=max(j,mp[nums[i]]);
            
        }
        return ans;
        
    }
};