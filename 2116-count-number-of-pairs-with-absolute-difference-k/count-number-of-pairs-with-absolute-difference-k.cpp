class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
     
     unordered_map<int,int> mp;
     int ans =0;
    //  mp[0]=1;
    
    for(auto it:nums)
    {
        ans+=mp[it+k]+mp[it-k];
        mp[it]++;
    }
    return ans;
        
        
    }
};