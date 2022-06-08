class Solution {
public:
    void solve(vector<int>& nums, int i, vector<int>& temp, vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,i+1,temp,ans);
        temp.push_back(nums[i]);
        solve(nums,i+1,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/subsets/
// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]