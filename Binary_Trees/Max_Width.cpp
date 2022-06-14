class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,1});
        unsigned long long ans = 1;
        while(!q.empty()){
            unsigned long long left=q.front().second, right=left;
            for(int i=0,sz = q.size();i<sz;i++){
                pair<TreeNode*,unsigned long long> p = q.front();q.pop();
                TreeNode* node = p.first;
                right = p.second;
                if(node->left)q.push({node->left,2*right-1});
                if(node->right)q.push({node->right,2*right});
            }
            ans = max(ans,right-left+1);
        }
        return (int)ans;
    }
};

// Problem Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
// Input: root = [1,3,2,5,null,null,9,6,null,7]
// Output: 7
