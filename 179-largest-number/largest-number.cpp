class Solution {
public:
  static bool cmp(int a, int b)
  {
    string t1 = to_string(a)+to_string(b);
    string t2 = to_string(b)+to_string (a);
    return t1>t2;

  }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(), cmp);
        string ans = "";
        for(auto it:nums)
        {
            ans+=to_string(it);
        }
        int i=0;
        while(i<ans.size()-1 and ans[i]=='0')
        {
            i++;
        }
        return ans.substr(i);

    }
};