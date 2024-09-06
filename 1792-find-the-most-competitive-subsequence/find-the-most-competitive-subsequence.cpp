class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {

        int req = nums.size()-k;
        vector<int> ans;
        stack<int> st;
        for(int i =  0 ; i <nums.size();i++)
        {
            while(!st.empty() and st.top()>nums[i] and req)
            {
                req--;
                st.pop();
            }
            st.push(nums[i]);
        }
        while(req)
        {
            st.pop();
            req--;
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};