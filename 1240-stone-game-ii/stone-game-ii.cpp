int dp[101][101][2];
class Solution {

    int find(int index, vector<int>& piles, int m, int turn)
    {
        if(index>=piles.size())
        {
            return 0;
        }
        int n = piles.size();
        if(dp[index][m][turn]!=-1)
            return dp[index][m][turn];
        int res = turn?-1: INT_MAX,stone=0;
        for(int x=1; x<=min(2*m,n-index);x++)
        {
            
                 stone+=piles[index+x-1];

            if(turn)
                {
                    res = max(res,stone+find(index+x,piles,max(m,x),1-turn));
                }
                else
                {
                     
                    res = min(res,find(index+x,piles,max(m,x),1-turn));
                }
              
        }
      


        return dp[index][m][turn]=res;
           
    }
public:
    int stoneGameII(vector<int>& piles) {


      memset(dp,-1,sizeof(dp));

            return find(0,piles,1,1);

        
    }
};