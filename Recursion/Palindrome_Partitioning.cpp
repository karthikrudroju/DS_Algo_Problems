class Solution {
public:
    bool isPaline(string &t){
        int i=0,j=t.size()-1;
        while(i<j)if(t[i++]!=t[j--])return false;
        return true;
    }
    
    void solve(string &s, int start, vector<string> &temp, vector<vector<string>>& ans){
        if(start>=s.size()){
            ans.push_back(temp);
            return;
        }
        string t = "";
        for(int i=start;i<s.size();i++){
            t += s[i];
            if(isPaline(t)){
                temp.push_back(t);
                solve(s,i+1,temp,ans);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string>temp;
        solve(s,0,temp,ans);
        return ans;
    }
};

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
