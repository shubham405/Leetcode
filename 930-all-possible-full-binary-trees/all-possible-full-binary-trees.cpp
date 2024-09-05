/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> f(int n)
    {
        if(n%2==0)
            return {};
        if(n==1)
        {
            return {new TreeNode()};
        }
         vector<TreeNode*> ans;
        for(int i = 1;i<n;i+=2)
        {
            vector<TreeNode*> left = f(i);
            vector<TreeNode*> right = f(n-i-1);
            for(auto it:left)
            {
                for(auto itr:right)
                {
                    TreeNode*root = new TreeNode();
                    root->left = it;
                    root->right = itr;
                    ans.push_back(root);
                }
            }
           
        }
         return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {

        return f(n);

        if(n%2==0)
        {
            return {};
        }
        
    }
};