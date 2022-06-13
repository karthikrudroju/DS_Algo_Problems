class Solution {
  public:
    void helper(TreeNode* root, vector<int>& ans, int level){
        if(root){
            if(level>ans.size())ans.push_back(root->val);
            helper(root->left,ans,level+1);
            helper(root->right,ans,level+1);
        }
    }

    vector<int> leftView(TreeNode *root)
    {
       // Your code here
       vector<int> ans;
       helper(root,ans,1);
       return ans;
    }
};
