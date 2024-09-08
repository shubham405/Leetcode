class Solution {
public:

    bool increasingTriplet(vector<int>& its) {

        int mini1 = INT_MAX, mini2 = INT_MAX;
        for(auto it:its)
        {
            if (it <= mini1) {
                mini1 = it;
            } else if (it <= mini2) {
                mini2 = it;
            } else {
                return true;
            }
        }
        return false;
        
    }
};