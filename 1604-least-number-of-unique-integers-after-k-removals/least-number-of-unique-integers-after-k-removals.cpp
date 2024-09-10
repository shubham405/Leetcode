class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        set<pair<int,int>>st;
        for(auto it:mp)
        {
            st.insert({it.second,it.first});
        }
        for(auto it:st)
        {
            if(it.first>k)
            {
                return st.size();
            }
            else
            {
                k-=it.first;
                st.erase(it);
            }
        }

        return st.size();
    }
};