class Solution {
  public:
    vector<int> leftView(TreeNode *root)
    {
       // Your code here
       if(root==NULL)return {};
       queue<TreeNode*> q;
       vector<int> ans;
       q.push(root);
       while(!q.empty()){
           int sz = q.size();
           for(int i=0;i<sz;i++){
               Node* fr = q.front();
               if(i==0)ans.push_back(fr->val);
               q.pop();
               if(fr->left)q.push(fr->left);
               if(fr->right)q.push(fr->right);
           }
       }
       return ans;
    }
};

// Input: [1,2,3,4,5,6,7]
// Output: [1,2,4]

