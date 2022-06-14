class Solution {
  public:
    bool preorder(TreeNode* root, int target, vector<int>& ans){
        if(root){
            if(root->val==target){
                ans.push_back(target);
                return true;
            }
            ans.push_back(root->val);
            if(preorder(root->left,target,ans))return true;
            if(preorder(root->right,target,ans))return true;
            ans.pop_back();
        }
        return false;
    }

    vector<int> Solution::solve(TreeNode* A, int B) {
        vector<int> ans;
        preorder(A,B,ans);
        return ans;
    }
};

// Problem Link: https://www.interviewbit.com/problems/path-to-given-node/
// Input: A = [1,2,3,4,5,6,7], B = 5
// Output: [1,2,5]
