class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
       vector<int> interval(n+1,0);
       int ans=  0, maxi = INT_MIN, ans1=0,mini=INT_MAX;
       for(int i = 0 ; i<ranges.size();i++)
       {
          //interval.push_back({max(0,i-ranges[i]),min(n,ranges[i]+i}));
          int start = max(0,i-ranges[i]);
          
          int end = min(n,ranges[i]+i);
          interval[start] = max(end,interval[start]);
       }
      int curEnd = 0, maxEnd = 0;
      for(int i  = 0;i<=n;i++)
      {
          
          //cout<<maxEnd<<endl;
          if(i>maxEnd)
            return -1;
        
          if(i>curEnd)
          {
            ans++;
            curEnd = maxEnd;
          }
            maxEnd = max(maxEnd,interval[i]);
      }
      return ans;
       
    }
    
    
};