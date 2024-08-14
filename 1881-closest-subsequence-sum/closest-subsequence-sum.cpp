class Solution {
public:
    int minAbsDifference(vector<int>& nums, int goal) {

        int n1 = nums.size()/2;
        int n2 = nums.size()-n1;
        vector<int> st1,st2;
        for(int i  = 0;i<(1<<n1);i++)
        {
            int sz = 0, sum = 0;
            for(int j =  0;j<n1;j++)
            {
                if(i&(1<<j))
                {
                    
                    sum+=nums[j];
                }
            }
           st1.push_back(sum);
        }
        for(int i  = 0;i<(1<<n2);i++)
        {
            int sz = 0, sum = 0;
            for(int j =  0;j<n2;j++)
            {
                if(i&(1<<j))
                {
                    sz++;
                    sum+=nums[j+n1];
                }
            }
            st2.push_back(sum);
        }
        sort(st2.begin(),st2.end());
        int ans = abs(goal);
        for(auto it1: st1)
        {
            ans =min(ans,abs(goal-(it1)));
            int low = 0, high = st2.size()-1;
            while(low<=high)
            {
                int mid = low+(high-low)/2;
                int s = it1+st2[mid];
                ans =  min(ans,abs(goal-s));
                if(s<goal)
                {
                     low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }

        }
        for(auto it: nums)
        {
            ans =min(ans,abs(goal-(it)));
        }
        return ans;
       

        
    }
};