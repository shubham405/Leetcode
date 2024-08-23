class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {

        int n = obstacles.size();
        vector<int> ans, temp;
        for(auto it:obstacles)
        {
            if(temp.empty() || temp.back()<=it)
            {
                temp.push_back(it);
                ans.push_back(temp.size());
            }
            else
            {
                int ind = upper_bound(temp.begin(),temp.end(),it)-temp.begin();
                temp[ind]= it;
                ans.push_back(ind+1);
            }
            
        }
       
        return ans;


        
    }
};