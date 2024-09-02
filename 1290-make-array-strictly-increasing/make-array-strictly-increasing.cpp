class Solution {
public:
    int dp[2][2001][2001];
    int f(int i, int j,bool prev, vector<int>& arr1, vector<int>& arr2)
    {
        //cout<<i<<" "<<j<<endl;
       if(i==arr1.size())
       {
        //cout<<i<<" "<<j<<endl;
             return 0;
       }
          
       int ans  = 1e9;
       if(dp[prev][i][j]!=-1)
       {
            return dp[prev][i][j];
       }
       if(i==0)
       {
           ans = min(ans,f(i+1,j,0,arr1,arr2));
           ans = min(ans,1+f(i+1,0,1,arr1,arr2));
       }
       else
       {
            if(prev)
            {
                // choosing from arr1
                if(arr1[i]>arr2[j])
                {
                    ans = min(ans,f(i+1,j,0,arr1,arr2));
                }
                // choosing from arr2
                 int ind = upper_bound(arr2.begin(),arr2.end(),arr2[j])-arr2.begin();
                // we have swaped with the previous index
                // choosing from arr2
                if(ind<arr2.size())
                {
                    //cout<<ind<<endl;
                    //cout<<arr1[i-1]<<" "<<arr1[i]<<" "<<arr2[ind]<<endl;
                    ans = min(ans,1+f(i+1,ind,1,arr1,arr2));
                }
            }
            else
            {
                // choosing from arr1
                if(arr1[i]>arr1[i-1])
                {
                   // cout<<arr1[i-1]<<" "<<arr1[i]<<endl;
                    ans = min(ans,f(i+1,j,0,arr1,arr2));
                }
                int ind = upper_bound(arr2.begin(),arr2.end(),arr1[i-1])-arr2.begin();
                

                // we have swaped with the previous index
                // choosing from arr2
                if(ind<arr2.size())
                {
                    //cout<<ind<<endl;
                    //cout<<arr1[i-1]<<" "<<arr1[i]<<" "<<arr2[ind]<<endl;
                    ans = min(ans,1+f(i+1,ind,1,arr1,arr2));
                }
            }
       }
      // cout<<ans<<endl;
       return dp[prev][i][j]=ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        sort(arr2.begin(), arr2.end());
        memset(dp,-1,sizeof(dp));
       int  ans = f(0,0,0,arr1,arr2);
        return ans==1e9?-1:ans;
    }
};