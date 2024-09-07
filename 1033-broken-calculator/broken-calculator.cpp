class Solution {
public:
    int brokenCalc(int startValue, int target) {

        int ans=0;
        while(target!=startValue)
        {
            //cout<<ans<<" "<<target<<endl;
            ans++;
            if(target%2 || target<startValue)
            {
                target++;
            }
            else
            {
                target/=2;
            }
        }

        return ans;
        
    }
};