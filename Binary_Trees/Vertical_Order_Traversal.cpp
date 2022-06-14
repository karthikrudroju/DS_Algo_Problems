class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)return {};
        // to map hd ==> {level,value of node}
        map<int,vector<pair<int,int>>> mp;
        // to store {TreeNode*, hd}
        queue<pair<TreeNode*,int>> q;
        int hd=0,level=0;
        q.push({root,hd});
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                pair<TreeNode*,int> p = q.front();
                q.pop();
                TreeNode* node = p.first;
                int hd = p.second;
                mp[hd].push_back({level,node->val});
                if(node->left)q.push({node->left,hd-1});
                if(node->right)q.push({node->right,hd+1});
            }
            level++;
        }
        vector<vector<int>> ans;
        for(auto &i : mp){
            // sort the elements on same level by value
            sort(i.second.begin(),i.second.end());
            vector<int> temp;
            for(auto &j : i.second){
                temp.push_back(j.second);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
// Input: root = [1,2,3,4,6,5,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
