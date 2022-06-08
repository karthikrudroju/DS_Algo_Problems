class Solution {
public:
    void solve(vector<vector<int>>& nums, int i, vector<int>& temp, vector<vector<int>>& ans){
        if(i>=nums.size()){
            ans.push_back(temp);
            return;
        }
        solve(nums,i+1,temp,ans);
        temp.push_back(nums[i][0]);
        nums[i][1]--;
        if(nums[i][1]>0)solve(nums,i,temp,ans);
        else solve(nums,i+1,temp,ans);
        nums[i][1]++;
        temp.pop_back();
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& num) {
        unordered_map<int,int> mp;
        for(auto &i : num)mp[i]++;
        // do recursion on frequency array to avoid duplicate sets.
        vector<vector<int>> nums;
        for(auto &i : mp)nums.push_back({i.first,i.second});
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,temp,ans);
        return ans;
    }
};

// Problem link: https://leetcode.com/problems/subsets-ii/
// Input: nums = [1,2,2]
// Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
