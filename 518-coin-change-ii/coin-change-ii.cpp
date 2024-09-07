class Solution {
public:
   int cc(vector<int>&coins, int amount,vector<vector<int>>&dp, int index)
    {
        if(index <0)
        {
            return amount==0;
        }
        if(dp[index][amount]!=-1)
            return dp[index][amount];
        int take = 0,notTake;
        notTake = cc(coins,amount,dp,index-1);
        if(coins[index]<=amount)
        {
            take = cc(coins,amount-coins[index],dp,index);
        }
        return dp[index][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {

        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return cc(coins,amount,dp,coins.size()-1);
        
    }
};