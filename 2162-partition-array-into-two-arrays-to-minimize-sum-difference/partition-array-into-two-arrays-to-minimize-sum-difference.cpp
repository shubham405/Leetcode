
class Solution {
public:
  
    int minimumDifference(vector<int>& arr) {

        int n  = arr.size()/2;
       vector<vector<int>> left(n+1), right(n+1);
       int sum = accumulate(arr.begin(),arr.end(),0);
        for(int mask = 0 ;  mask<(1<<n); mask++)
        {
            int sz = 0, l = 0, r = 0 ;
            for(int i=0;i<n;i++)
            {
                if(mask &(1<<i))
                {
                    sz++;
                    l+=arr[i];
                    r+=arr[i+n];
                }
                left[sz].push_back(l);
                right[sz].push_back(r);
            }
        }
        for(int i =  0;i<=n;i++)
        {
            sort(right[i].begin(),right[i].end());
        }
        int  ans = min(abs(sum-2*left[n][0]), abs(sum-2*right[n][0]));
        for(int sz =1;sz<n; sz++)
        {
            for(auto it: left[sz])
            {
                int b = (sum-2*it)/2;
                auto ind = lower_bound(right[n-sz].begin(), right[n-sz].end(),b);   
                if(ind!=right[n-sz].end())
                {
                    ans = min(ans,abs(sum-2*(it+(*ind))));
                }
            }
        }

        return ans;
    }
};