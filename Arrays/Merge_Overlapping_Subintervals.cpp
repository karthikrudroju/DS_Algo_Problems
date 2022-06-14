class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        int start=intervals[0][0], end=intervals[0][1];
        for(int i=0;i<intervals.size();i++){
            // if overlapping interval is found update end variable.
            if(intervals[i][0]<=end){
                end = max(intervals[i][1],end);
            }
            else{
                ans.push_back({start,end});
                start=intervals[i][0];
                end=intervals[i][1];
            }
        }
        ans.push_back({start,end});
        return ans;
    }
    
};

// Problem Link: https://leetcode.com/problems/merge-intervals/
// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
