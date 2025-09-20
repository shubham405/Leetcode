class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),greater<int>());
        unordered_set<int> st;
        int ans =0;
        vector<int> t;
        for(auto it:nums)
        {
            if(st.find(it)==st.end())
            {
                st.insert(it);
                t.push_back(it);
                k--;
            }
            if(k==0)
            break;
        }
        return t;
        
        
    }
};