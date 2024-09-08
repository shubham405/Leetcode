class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        vector<int> t = nums;
        int n = nums.size();
        int ans = t[0];
        priority_queue<pair<int,int>> pq;
        pq.push({t[0],0});
        for(int i = 1;i<n;i++)
        {
           
           while(!pq.empty() and i-pq.top().second>k)
           {
            pq.pop();
           }
           t[i] = max(t[i],nums[i]+pq.top().first);
           ans = max(ans,t[i]);
           pq.push({t[i],i});
           

        }
       for(auto it:t)
       {
        cout<<it<<" ";
       }
        return ans;
        
    }
};