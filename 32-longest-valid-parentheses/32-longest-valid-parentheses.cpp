class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> dp(s.length()+1, 0);
        int ans = 0;
        for(int i = 2; i <= s.length(); i++){
            if(s[i-1]==')'){
                if(s[i-2]=='('){
                    dp[i] = dp[i-2] + 2;
                }
                else if(i-dp[i-1]-2 >= 0 && s[i-dp[i-1]-2] == '('){
                    dp[i] = dp[i-1] + dp[i-dp[i-1]-2] + 2;
                }
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
};