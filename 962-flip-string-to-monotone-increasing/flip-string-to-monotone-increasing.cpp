class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1=0, flip=0;;
        for(auto it:s)
        {
            if(it=='1')
            {
                count1++;
            }
            else
            {
                flip = min(flip+1,count1);
            }
        }
        return flip;

    }
};