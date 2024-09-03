class Solution {
public:
    int mod = 1e9+7;
    int dp[100][100][201];
   int f(vector<int>& locations, int start, int finish, int fuel)
   {
     if(fuel<0)
     {
        return 0;
     }
     if(dp[start][finish][fuel]!=-1)
         return dp[start][finish][fuel];
     int ans =0 ;
     for(int i =0;i<locations.size();i++)
     {
        if(start!=i and abs(locations[i]-locations[start])<=fuel)
        {
            ans+= (i==finish)+f(locations,i,finish,fuel-abs(locations[i]-locations[start]))%mod;
            ans%=mod;
        }
       
     }
      return dp[start][finish][fuel]=ans;
   }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {          
        memset(dp,-1,sizeof(dp));
        return f(locations,start,finish,fuel)+(start==finish);
        
    }
};