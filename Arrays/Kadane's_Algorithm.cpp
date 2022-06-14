class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, mx = INT_MIN;
        for(auto &i : nums){
            sum += i;
            if(sum<i)sum=i;
            mx=max(mx,sum);
        }
        return mx;
    }
};

// Problem Link: https://leetcode.com/problems/maximum-subarray/
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
