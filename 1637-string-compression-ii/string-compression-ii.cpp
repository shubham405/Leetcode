
class Solution {
public:

// int f(int i, char prev, int freq, int k, string &s)
// {
//     if(i==s.size())
//        return 0;
//     int ans = 1e9;
//     if(dp[i][prev-'a'][freq][k]!=-1)
//          return dp[i][prev-'a'][freq][k];
//     if(s[i] ==prev)
//     {
//         int newFreq = freq+1;
//         if(newFreq==2 || newFreq==10 || newFreq==100 )
//         {
//             ans = min(ans,1+f(i+1,s[i],newFreq,k,s));
//         }
//         else
//         {
//             ans = min(ans,f(i+1,s[i],newFreq,k,s));
//         }
//     }
//     else
//     ans = min(ans,1+f(i+1,s[i],1,k,s));
//     if(k)
//     ans = min(ans,f(i+1,prev,freq,k-1,s));

//     return dp[i][prev-'a'][freq][k]=ans;

    
// }
  int dp[101][10001];
  int f(int i, int k, string &s)
  {
      if(k<0)
         return 1e9;
      if(i>=s.size() || s.size()-i<=k)
         return 0;
      int ans  =1e9;
      if(dp[i][k]!=-1)
          return dp[i][k];
      ans  = min(ans,f(i+1,k-1,s));
      int freq =0;
    //   ans = min(ans,1+f(i+1,k,s));
        int deleted = 0, add=0;
      for(int x = i;x<s.size() and deleted<=k;x++)
      {
          if(s[x]==s[i])
          {
            freq++;
            if(freq==2 || freq==10 || freq==100)
            {
                add++;
            }
          }
        else 
        {
                deleted++;
        }
         string t = to_string(freq);
         ans = min(ans,1+add+f(x+1,k-deleted,s));

      }
    
      return dp[i][k]=ans;
  }
    int getLengthOfOptimalCompression(string s, int k) {

        int n =s.size();
        if(k>=n)
           return 0;
        memset(dp,-1,sizeof(dp));
       return f(0,k,s);
        
    }
};