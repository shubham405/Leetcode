class Solution {
  
    int f(int i,  vector<int> &nums, int k, vector<int> &ds)
    {
        if(i==nums.size())
        {
            int arr[1001]={0};
            for(auto it:ds)
            {
               
                if(it-k>=0 and arr[it-k])
                {
                    
                    return 0;
                }
                   
                arr[it]=1;
            }
            
            return 1;
        }
        int ans = 0;
        ds.push_back(nums[i]);
        ans+=f(i+1,nums,k,ds);
        ds.pop_back();
        ans+=f(i+1,nums,k,ds);
        return ans;
    }
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> ds;
        return f(0,nums,k,ds)-1;

    }
};