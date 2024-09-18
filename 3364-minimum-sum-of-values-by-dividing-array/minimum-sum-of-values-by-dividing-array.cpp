class Solution {
public:
int n;
vector<vector<unordered_map<int,int>>> dp;
int f(int i, int j,int val,vector<int>& nums, vector<int>& andValues )
{
    if(j>=andValues.size())
    {
        if(i>=nums.size())
             return 0;
        return 1e9;
    }
    if(i>=nums.size())
    {
        return 1e9;
    }
    if(dp[i][j].find(val)!=dp[i][j].end())
    {
        return dp[i][j][val];
    }
    int prev = val;
    val&=nums[i];
    int ans = 1e9;
    int nv = i+1<n?nums[i+1]:1e9;
    if(val == andValues[j])
    {
        ans = min(ans,nums[i]+f(i+1,j+1,(1<<17)-1,nums,andValues));
        ans = min(ans,f(i+1,j,val,nums,andValues));
    }
    else
    {
        ans = min(ans,f(i+1,j,val,nums,andValues));
    }
    return dp[i][j][prev]=ans;
    
}
    int minimumValueSum(vector<int>& nums, vector<int>& andValues) {
        //memset(dp,-1,sizeof(dp));
        int n = nums.size();
        dp.resize(n+1,vector<unordered_map<int,int>>(11));
        int ans =  f(0,0,nums[0],nums,andValues);
        if(ans>=1e9)
        {
            return -1;
        }
        return ans;
    }
};