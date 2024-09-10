class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        
        long long ans = accumulate(nums.begin(),nums.end(),0ll);
        long long count =0, sum=0, mini=INT_MAX;
        for(auto it:nums)
        {
            if((it^k)>it)
            {
                count++;
                sum+=it^k;
                cout<<it<<" ";
            }
            else
            {
                sum+=it;
               
               // cout<<it<<" "<<(it^k)<<endl;
            }
             mini = min(mini,abs((long long)it-(it^k)));
        }
        cout<<endl;
        cout<<count<<" "<<mini<<endl;
        cout<<sum<<endl;
        if(count%2)
        {
            ans= max(ans,sum-mini);
        }
        else
        {
            ans = max(ans,sum);
        }
        return ans;
    }
};