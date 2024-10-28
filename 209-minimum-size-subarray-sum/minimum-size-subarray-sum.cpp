class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int len = nums.size(), curSum = 0, index = -1, flag = 1;
        int n =  nums.size();
        for(int i  =0;i<n;i++)
        {
            curSum+=nums[i];
            if(curSum>=target)
            {
                while(curSum>=target)
                {
                    flag = 0;
                    len =  min(len,i-index);
                    curSum -= nums[++index];
                }
                
            }
        }
        if(flag)
           return 0;
        return len;
    }
};