class Solution {
public:
int Xmoves[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int Ymoves[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
vector<vector<vector<double>>> dp;
double f(int i, int j, int k, int n)
{
    if(k==0)
      return 1;
    double ans =0;
    if(dp[i][j][k]!=-1.0)
        return dp[i][j][k];
    for(int x =0 ; x<8;x++)
    {
        int nr = Xmoves[x]+i;
        int nc = Ymoves[x]+j;
        
        if(nr>=0 and nr<n and nc>=0 and nc<n)
        {
            ans+=1.0/8*(f(nr,nc,k-1,n));
            //cout<<ans<<endl;
        }
       
    }
     return dp[i][j][k]=ans;
}
    double knightProbability(int n, int k, int row, int column) {
        if(k==0)
        {
            return 1.0;
        }
        dp.resize(25,vector<vector<double>>(25,vector<double>(101,-1.0)));
        return f(row,column,k,n);
    }
};