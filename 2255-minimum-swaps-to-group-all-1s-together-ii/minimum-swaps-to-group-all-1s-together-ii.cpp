class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count = 0, ans = INT_MAX;
        
      for(auto it: nums)
      {
        if(it)
        {
            count++;
        }
      }
      if(count==0 || count == nums.size())
          return 0;
      int c0=0, c1 =0 ;
      int n  = nums.size();
      for(int i = 0 ,j =0;i<nums.size()+count-1;i++)
      {
        if(nums[i%n])
        {
            c1++;
        }
        else
        {
            c0++;
        }
          if(i-j+1==count)
          {
            ans = min(ans, count-c1);
          }
          if(i-j+1>count)
          {
              if(nums[j%n])
              {
                c1--;
              }
              else
              {
                c0--;
              }
              j++;
              ans = min(ans, count-c1);
            
          }
      }
      return ans;
        
    }
};