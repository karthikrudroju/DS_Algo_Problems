class Solution {
public:
    TreeNode* rightMostChild(TreeNode* root){
        while(root->right){
            root=root->right;
        }
        return root;
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* node = root;
        while(node){
            if(node->left){
                // connecting rightMostChild of node->left to current node.
                TreeNode* temp = rightMostChild(node->left);
                temp->right=node;
                // breaking the left of current node as we have build a better connection in above step.
                TreeNode* temp2=node->left;
                node->left=NULL;
                node=temp2;
            }else{
                ans.push_back(node->val);
                node=node->right;
            }
        }
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
// Input: root = [1,null,2,3]
// Output: [1,3,2]
