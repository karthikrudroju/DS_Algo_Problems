class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node = root;
        vector<int> ans;
        while(!stk.empty() || node!=NULL){
            if(node){
                ans.push_back(node->val);
                stk.push(node);
                node=node->left;
            }
            if(node==NULL and !stk.empty()){
                node = stk.top();
                if(node->right){
                    TreeNode* temp = node;
                    node=node->right;
                    temp->right=NULL;
                }
                else{
                    stk.pop();
                    node=NULL;
                }
            }
        }
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
// Input: root = [1,null,2,3]
// Output: [1,2,3]
