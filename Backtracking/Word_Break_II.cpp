class Solution {
public:
    void solve(string &s, int start, unordered_set<string>& st, string &temp_ans, vector<string>& ans){
        if(start>=s.size()){
            temp_ans.pop_back();
            ans.push_back(temp_ans);
            temp_ans.push_back(' ');
            return;
        }
        string curr = "";
        for(int idx=start;idx<s.size();idx++){
            curr += s[idx];
            if(st.find(curr)!=st.end()){
                for(int j=0;j<curr.size();j++)temp_ans+=curr[j];
                temp_ans.push_back(' ');
                solve(s,idx+1,st,temp_ans,ans);
                temp_ans.pop_back();
                for(int j=0;j<curr.size();j++)temp_ans.pop_back();
            }
        }
    }
   
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i=0;i<wordDict.size();i++)st.insert(wordDict[i]);
        vector<string> ans;
        string temp_ans = "";
        solve(s,0,st,temp_ans,ans);
        return ans;
    }
};

// Problem Link: https://leetcode.com/problems/word-break-ii/
// Input: s = "pineapplepenapple", wordDict = ["apple","pen","applepen","pine","pineapple"]
// Output: ["pine apple pen apple","pineapple pen apple","pine applepen apple"]
// Explanation: Note that you are allowed to reuse a dictionary word.
