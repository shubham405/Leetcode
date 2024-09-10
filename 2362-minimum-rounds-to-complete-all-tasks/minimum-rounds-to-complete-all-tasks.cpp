class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        int ans =0;
        for(auto it:tasks)
        {
            mp[it]++;
    
        }
        for(auto &[x,y]:mp)
        {
            if(y==1)
            {
                return -1;
            }
            ans+= (y+2)/3;
        }
        return ans;
    
        
    }
};