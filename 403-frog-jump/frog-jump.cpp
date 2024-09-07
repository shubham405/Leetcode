class Solution {

    bool canJump(int index, int step,vector<int> &stones, vector<vector<int>> &dp)
    {
        if(index==stones.size()-1)
            return 1;
        if(index>=stones.size())
        {
            return false;
        }
        bool jump = false;
        if(dp[index][step]!=-1)
            return dp[index][step];
        for(int i = index+1;i<stones.size();i++)
        {
            if(stones[i]-stones[index]>step+1)
            {
                break;
            }
            if(stones[i]-stones[index]==step-1)
            {
                jump = jump | canJump(i,step-1,stones,dp);
            }
            else if( stones[i]-stones[index]==step)
            {
                 jump = jump | canJump(i,step,stones,dp);
            }
             else if(stones[i]-stones[index]==step+1)
             {
                  jump = jump | canJump(i,step+1,stones,dp);
             }
        }

        return dp[index][step]=jump;
       
    }
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return canJump(0,0,stones,dp);
    }
};