class Solution {
public:
unordered_map<string,bool> mp;
   bool solve(string s1, string s2)
   {
    if(s1==s2)
      return 1;
      if(s1.size()!=s2.size())
         return 0;
    int n = s1.size();
    if(mp.find(s1+s2)!=mp.end())
       return mp[s1+s2];
      bool notSwap = 0, swap = 0;
      for(int i = 1;i<s1.size();i++)
      {
         notSwap|= solve(s1.substr(0,i),s2.substr(0,i)) and solve(s1.substr(i,n-i),s2.substr(i,n-i));
         swap|=  solve(s1.substr(i,n-i),s2.substr(0,n-i)) and solve(s1.substr(0,i),s2.substr(n-i,i));
         if(swap|notSwap)
           return mp[s1+s2]=1;
      }

      return mp[s1+s2]=swap|notSwap;

   }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};