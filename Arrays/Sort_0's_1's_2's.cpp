class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i=0,j=nums.size()-1,k=0;
        while(k<=j){
            if(nums[k]==0){
                swap(nums[k++],nums[i++]);
            }
            else if(nums[k]==2){
                swap(nums[k],nums[j--]);
                
            }
            else{
                k++;
            }
        }
    }
};

// Problem Link: https://leetcode.com/problems/sort-colors/
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]
