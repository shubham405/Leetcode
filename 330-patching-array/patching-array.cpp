class Solution {
public:
    int minPatches(vector<int>& nums, int n) {

      long long  int sum = 0, ans=0, coin=0;
        
        for(auto it:nums)
        {
           if(sum>n)
           {
               break;
           }
                while(sum+1<it)
                {
                     if(sum>n)
                        {
                            break;
                        }
                     ans++;
                    sum+=sum+1;
                }
            sum+=it;
               
            
        }
        if(sum<n)
        {
            while(sum<n)
            {
                sum+=sum+1;
                ans++;
            }
        }
       return ans;
        
    }
};