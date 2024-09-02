class Solution {

    int  findWinner(int index,vector<int>& stoneValue, int turn,  vector<vector<int>> &dp)
    {
       if(index>=stoneValue.size())
           return 0;
        int curScore = -1e9;

       int n =  stoneValue.size();
       if(dp[index][turn]!=-1)
            return dp[index][turn];
       if(turn)
       {
           curScore =  max(curScore,stoneValue[index]-findWinner(index+1,stoneValue,1,dp));
           if(index+1<n)
           {
               curScore =  max(curScore,stoneValue[index]+stoneValue[index+1]-findWinner(index+2,stoneValue,1,dp));
           }
           if(index+2<n)
           {
               curScore =  max(curScore,stoneValue[index]+stoneValue[index+1]+stoneValue[index+2]-findWinner(index+3,stoneValue,1,dp));
           }
       }
       
        return dp[index][turn]=curScore;
            
    }
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int total = 0;
        int n =  stoneValue.size();
        vector<vector<int>> dp(n,vector<int> (2,-1));
        for(auto it: stoneValue)
        {
            total+=it;
        }
        int score  =  findWinner(0,stoneValue,1,dp);
        cout<<score<<endl;
        
        
        if(score>0)
        {
            return "Alice";

        }
        else if(score==0)
        {
            return "Tie";
        }
        return "Bob";
    }
};