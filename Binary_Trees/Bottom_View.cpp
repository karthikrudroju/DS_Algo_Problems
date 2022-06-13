class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,vector<int>> mp;
        int hd = 0;
        q.push({root,hd});
        while(!q.empty()){
            pair<Node*,int> p = q.front();
            q.pop();
            Node* t = p.first;
            hd = p.second;
            mp[hd].push_back(t->data);
            if(t->left)q.push({t->left,hd-1});
            if(t->right)q.push({t->right,hd+1});
        }
        for(auto i : mp){
            ans.push_back(i.second[i.second.size()-1]);
        }
        return ans;
    }
};

// Input: [1,2,3,4,5,6,7]
// Output: [4,2,6,3,7]
