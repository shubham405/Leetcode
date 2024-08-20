class Solution {
public:
    
    int minimumOneBitOperations(int n) {
        vector<int>dp(32,0);
        dp[0]=1;
        for(int i   =1;i<31;i++)
        {
            dp[i] = 2*dp[i-1]+1;
        }
        bool f = 1;
        int ans =0 ;
        int count =0;
        for(int i  = 30;i>=0;i--)
        {
            int x = 1<<i;
            if(n&x)
            {
                if(f)
                {
                    ans+=dp[i];
                    f=1-f;
                }
                else
                {
                    ans-=dp[i];
                    f = 1-f;
                }
                

            }
           

        }
        return ans;

    }
};