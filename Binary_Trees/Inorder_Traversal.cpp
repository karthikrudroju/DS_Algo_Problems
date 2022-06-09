class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)return {};
        stack<TreeNode*> stk;
        vector<int> ans;
        TreeNode* node = root;
        while(!stk.empty() || node!=NULL){
            if(node){
                stk.push(node);
                node=node->left;
            }
            else {
                node = stk.top();
                ans.push_back(node->val);
                stk.pop();
                node = node->right;
            }
        }
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Input: root = [1,null,2,3]
// Output: [1,3,2]
