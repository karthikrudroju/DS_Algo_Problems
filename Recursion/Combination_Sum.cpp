class Solution {
public:
    void solve(vector<int>& candidates, int i, vector<int>& temp, vector<vector<int>>& ans, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(target<0||i>=candidates.size())return;
        solve(candidates,i+1,temp,ans,target);
        temp.push_back(candidates[i]);
        solve(candidates,i,temp,ans,target-candidates[i]);
        temp.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(candidates,0,temp,ans,target);
        return ans;
    }
};

// Input: candidates = [2,3,5], target = 8
// Output: [[2,2,2,2],[2,3,3],[3,5]]
