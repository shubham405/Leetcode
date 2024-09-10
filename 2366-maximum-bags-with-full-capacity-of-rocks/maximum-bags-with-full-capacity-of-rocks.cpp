class Solution {
public:
static bool cmp(pair<int,int>&a1,pair<int,int>&a2)
{
    return (a1.first-a1.second)<(a2.first-a2.second);
}
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int rc) {
        
        vector<pair<int, int>> temp;
        for(int i  =0 ;i <rocks.size();i++)
        {
            temp.push_back({capacity[i],rocks[i]});
        }
        int ans=0;
        sort(temp.begin(),temp.end(),cmp);
        for(auto it:temp)
        {
            if(it.first==it.second)
            {
                ans++;
            }
            else
            {
                int req = it.first-it.second;
                if(req<=rc)
                {
                    ans++;
                    rc-=req;
                }
            }
        }
        return ans;
    }
};