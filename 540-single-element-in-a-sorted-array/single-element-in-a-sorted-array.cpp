class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {

        int low = 0, high = nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(mid%2)
            {
                if(nums[mid]==nums[mid-1])
                {
                    low = mid+1;
                }
                else if(mid+1 <nums.size() and nums[mid]==nums[mid+1])
                {
                    high = mid-1;
                }
                else
                {
                    return nums[mid];
                }
            }
            else
            {
                if(mid and nums[mid]==nums[mid-1])
                {
                   
                     high = mid-1;
                }
                else if(mid+1 <nums.size() and nums[mid]==nums[mid+1])
                {
                    low = mid+1;
                }
                else
                {
                    return nums[mid];
                }
            }
           
        }
        return -1;
        
    }
};