class Solution {
public:
    int dp[1001][1001];
    int solve(vector<int> &nums,int i, int d)
    {
        if(i<0)
          return 0;
        int ans =0;
        if(dp[i][d+500]!=-1)
            return dp[i][d+500];
        for(int k = i-1;k>=0;k--)
        {
            if(nums[i]-nums[k]==d)
            ans = max(ans,1+solve(nums,k,d));
        }
        return dp[i][d+500]=ans;
    }
    int longestArithSeqLength(vector<int>& nums) {

        int ans =0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i <nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                int d = nums[j]-nums[i];
                ans = max(ans,2+solve(nums,i,d));
            }
        }
        return ans;
        
    }
};