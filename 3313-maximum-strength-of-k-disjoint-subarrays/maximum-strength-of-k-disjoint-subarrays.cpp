class Solution {
public:

    int n;
    vector<vector<vector<long long>>> dp;
    long long dfs(vector<int>& nums,int indx,long long k,bool insubarr)
    {
        if(k==0) return 0;
        if(indx==n) return -1e16;
        if(dp[indx][insubarr][k]!=-1e16) return dp[indx][insubarr][k];
        long long ans=-1e16;

        if(insubarr)
        {
            ans=max(dfs(nums,1+indx,k,true),dfs(nums,1+indx,k-1,false));
            if(k%2==0) ans+=nums[indx]*(-1)*k;
            else ans+=nums[indx]*k;  
        }
        else
        {
            ans=max(dfs(nums,indx,k,true),dfs(nums,1+indx,k,false));
        }
        return dp[indx][insubarr][k]=ans;
    }

    long long maximumStrength(vector<int>& nums, int k) 
    {
        n=nums.size();
        dp=vector(n,vector(2,vector<long long>(k+1,-1e16)));
        return dfs(nums,0,k,false);
    }
};