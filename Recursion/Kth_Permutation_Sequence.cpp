class Solution {
public:
    vector<int>fact = {1,1,2,6,24,120,720,5040,40320,362880};
    
    string solve(int n, int k, vector<bool>& vis){
        if(n==0)return  "";
        int partsOfSize = fact[n-1];
        int num = k/partsOfSize + (k%partsOfSize != 0 ? 1 : 0);
        int rem = k%partsOfSize;
        if(rem == 0)rem += partsOfSize;
        // mark the element which we are using now as visisted.      
        int cnt=0;
        for(int i=1;i<=vis.size()-1;i++){
            if(vis[i]==false){
                cnt++;
                if(cnt==num){
                    vis[i]=true;
                    num=i;
                    break;
                }
            }
        }
        string ans = to_string(num);
        ans += solve(n-1,rem,vis);
        return ans;
    }
    
    string getPermutation(int n, int k) {
        vector<bool> vis(n+1,0);
        string ans = solve(n,k,vis);
        return ans;
    }
};

// Input: n = 4, k = 9
// Output: "2314"
