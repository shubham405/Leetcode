class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int> mp;
        for(auto it:s)
        {
            mp[it]++;
        }
        int ans =0;
        bool rem = 0;
        for(auto it:mp)
        {
            ans+= it.second-it.second%2;
            rem|=it.second%2;
        }
        return ans+rem;
        
    }
};