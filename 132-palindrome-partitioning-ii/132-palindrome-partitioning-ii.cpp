class Solution {
    vector<int> dp;
    bool isPal(int i, int j, string& s){
        while(i<j){
            if(s[i]==s[j]){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    
    int helper(string& s, int i, int j){
        if(i==j) return 0;
        if(dp[i]!=-1) return dp[i];
        if(isPal(i, j, s)) return dp[i] = 0;
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            if(isPal(i, k, s)){
                int temp = 1 + helper(s, k+1, j);
                ans = min(ans, temp);
            }
        }
        return dp[i] = ans;
    }
public:
    int minCut(string s) {
        int n = s.length();
        dp.resize(n, -1);
        return helper(s, 0, n-1);
    }
};