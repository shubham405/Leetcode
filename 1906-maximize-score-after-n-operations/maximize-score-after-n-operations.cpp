class Solution {
public:
    int dp[15][1<<15];
    int f(int mask, vector<int>&nums, int n, int i)
    {
        if(i==n+1)
            return 0;
        int ans = 0 ;
        if(dp[i][mask]!=-1)
           return dp[i][mask];
        for(int x = 0 ;  x<nums.size();x++)
        {
            int num = 1<<x;
            if((num&mask))
            {
                continue;
            }
            for(int y = 0;y<nums.size();y++)
            {
                int num2 = 1<<y;
                if(y!=x and !(num2&mask))
                {
                    int xx = (mask|num)|num2;
                    
                    ans = max(ans,i*__gcd(nums[y],nums[x])+f(xx,nums,n,i+1));
                }
            }
        }
        return dp[i][mask]=ans;
    }
    int maxScore(vector<int>& nums) {
        int n = nums.size()/2;
        memset(dp,-1,sizeof(dp));
        return f(0,nums,n,1);
        
    }   
};