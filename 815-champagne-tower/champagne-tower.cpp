class Solution {
public:
  double dp[101][101];
  double f(int i, int j,int poured)
  {
       if(i==0 and j==0)
       {
        return poured;
       }
       if(i<0 || j<0 || i<j)
          return 0;
        if(dp[i][j]!=-1.0)
            return dp[i][j];
       double left,right, ans;

       left = (f(i-1,j-1,poured)-1)/2.0;
       right = (f(i-1,j,poured)-1)/2.0;
       left = max(left,0.0);
       right = max(right,0.0);
       ans = (left+right);
      
       return dp[i][j]=ans;
  }
    double champagneTower(int poured, int query_row, int query_glass) {
         for(int i = 0 ;i<101;i++)
         {
            for(int j =0 ;j<101;j++)
            {
                dp[i][j]=-1.0;
            }
         }
        return min(f(query_row,query_glass,poured),1.0);
    }
};