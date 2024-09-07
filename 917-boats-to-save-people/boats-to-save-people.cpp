class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        sort(people.begin(),people.end());
        int cur_wait=0, ans =0 ;
        int l=0, r=people.size()-1;
        while(l<=r)
        {
            ans++;
            if(l==r)
            {
                break;
            }
            if(people[l]+people[r]<=limit)
            {
                
                l++;
                r--;
            }
            else
            {
                r--;
            }
        }
        return ans;
        
    }
};