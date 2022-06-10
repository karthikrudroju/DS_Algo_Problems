class Solution {
public:
    void solve(vector<int>& nums, int start, vector<vector<int>>& ans){
        if(start>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){
            swap(nums[i],nums[start]);
            solve(nums,start+1,ans);
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/permutations/
// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
