class Solution
{
    public:
    vector<int> topView(Node *root)
    {
        //Your code here
        if(root==NULL)return {};
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,vector<int>> mp;
        q.push({root,0});
        int hd=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                auto p = q.front();
                q.pop();
                Node* node = p.first;
                int hd = p.second;
                mp[hd].push_back(node->data);
                if(node->left)q.push({node->left,hd-1});
                if(node->right)q.push({node->right,hd+1});
            }
        }
        for(auto &i : mp){
            ans.push_back(i.second[0]);
        }
        return ans;
    }
};

// Input: [1,2,3,4,5,6,7]
// Output: [4,2,1,3,7]
