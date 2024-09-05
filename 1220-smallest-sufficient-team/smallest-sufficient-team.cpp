class Solution {
public:
unordered_map<string,int> dp;
void f(int i , int mask, int req, vector<int>&temp, vector<int>&res,vector<int> &people_skill)
{
    if(i>=people_skill.size())
    {
        if(mask == req)
        {
            if(res.size()==0 || res.size()>temp.size())
              {
                res = temp;

              }
        }
        return;
    }
    if(res.size() and res.size()<=temp.size())
         return ;
    string key= to_string(i)+"-"+to_string(mask);
    if(dp.find(key)!=dp.end())
    {
        if(dp[key]<=temp.size())
        {
            return;
        }
    }
    if((people_skill[i]|mask)!=mask)
    {
        temp.push_back(i);
        f(i+1,mask|people_skill[i],req,temp,res,people_skill);
        temp.pop_back();
    }
    
    f(i+1,mask,req,temp,res,people_skill);
    dp[key] = temp.size()==0 ? -1:temp.size();
    
}
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> mp;
      for(int i = 0 ; i<req_skills.size();i++)
      {
        mp[req_skills[i]]=i;
      }
        int req  = (1<<req_skills.size())-1;
    vector<int> people_skills, res, temp;
    for(auto skills:people)
    {
        int x =0;
        for(auto it:skills)
        {
            if(mp.find(it)!=mp.end())
            {
                x|=1<<mp[it];
            }
        }
        people_skills.push_back(x);
    }
    f(0,0,req,temp,res,people_skills);
    
    return res;

    }
};