class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)return {{1}};
        vector<vector<int>> dp(numRows);
        dp[0] = {1};
        dp[1] = {1,1};
        for(int i=3;i<=numRows;i++){
            dp[i-1].push_back(1);
            for(int j=0;j<dp[i-2].size()-1;j++){
                dp[i-1].push_back(dp[i-2][j]+dp[i-2][j+1]);
            }
            dp[i-1].push_back(1);
        }
        return dp;
    }
};

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
