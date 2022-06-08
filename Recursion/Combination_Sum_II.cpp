class Solution {
public:
    void solve(vector<pair<int,int>>& nums, int i, vector<int>& temp, vector<vector<int>>& ans, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if(i>=nums.size()||target<0)return;
        temp.push_back(nums[i].first);
        target-=nums[i].first;
        nums[i].second--;
        // if the counter of current element becomes zero move next or else stay here.
        if(nums[i].second>0)
            solve(nums,i,temp,ans,target);
        else 
            solve(nums,i+1,temp,ans,target);
        nums[i].second++;
        target+=nums[i].first;
        temp.pop_back();
        solve(nums,i+1,temp,ans,target);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<candidates.size();i++)mp[candidates[i]]++;
        // perform recursion on frequency array to avoid duplicates.
        vector<pair<int,int>> nums;
        for(auto &i : mp)nums.push_back(i);
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,temp,ans,target);
        return ans;
    }
};

// Input: candidates = [2,5,2,1,2], target = 5
// Output: [[1,2,2],[5]]
