class Solution {
    bool isPal(int i, int j, string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n+1, -1);
        dp[n] = 0;
        for(int i = n-1; i >= 0; i--){
            int ans = INT_MAX;
            for(int k = i; k < n; k++){
                if(isPal(i, k, s)){
                    int temp = 1 + dp[k+1];
                    ans = min(ans, temp);
                }
            }
            dp[i] = ans;
        }
        return dp[0]-1;
    }
};