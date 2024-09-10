class Solution {
public:
    static bool cmp(pair<int,int>&a1, pair<int,int>&a2)
    {
        if(a1.second==a2.second)
           return a1.first>a2.first;
        return a1.second>a2.second;
    }
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {

        vector<pair<int,int>> temp;
        for(int i=0;i<growTime.size();i++)
        {
            temp.push_back({plantTime[i],growTime[i]});
        }
        sort(temp.begin(),temp.end(),cmp);
        int prev = 0, ans=0;
        for(auto it:temp)
        {   
           // cout<<it.first<<" "<<it.second<<endl;
            ans = max(prev+it.first+it.second,ans);
            prev += it.first;
        }
        return ans;

        
        
    }
};