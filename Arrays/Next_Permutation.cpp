class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==1)return;
        int i=nums.size()-1;
        // finding the first decreasing element from the back.
        while(i-1>=0 and nums[i-1]>=nums[i])i--;
        if(i==0){
            // if the array is in decreasing order return increasing order of the array.
            reverse(nums.begin(), nums.end());
            return;
        }
        // find the first element larger than nums[i-1] to the right side of the array and swap them.
        int j=nums.size()-1;
        while(j>=i and nums[j]<=nums[i-1]){
            j--;
        }
        swap(nums[i-1],nums[j]);
        // reverse the array from nums.begin()+i to nums.end().
        reverse(nums.begin()+i,nums.end());
    }
};

// Problem Link: https://leetcode.com/problems/next-permutation/
// Input: nums = [1,2,3]
// Output: [1,3,2]
