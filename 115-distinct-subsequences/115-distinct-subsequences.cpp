class Solution {
    // int solve(string A, string B, vector<vector<int>> dp, int i, int j){
    //     if(j == A.length()){
    //         return 0;
    //     }
    //     if(i == B.length()-1){
    //         if(B[i]==A[j]){
    //             return 1 + solve(A, B, dp, i, j+1);
    //         }
    //     }
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(B[i]==A[j]){
    //         dp[i][j] = solve(A, B, dp, i+1, j+1) + solve(A, B, dp, i, j+1);
    //         return dp[i][j];
    //     }
    //     return dp[i][j] = solve(A, B, dp, i, j+1);
    // }
public:
    // int numDistinct(string A, string B) {
    //     vector<vector<int>> dp(B.length(), vector<int>(A.length(), -1));
    //     return solve(A, B, dp, 0, 0);
    // }
    int numDistinct(string s, string t) {
        int m = t.length(), n = s.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        for (int j = 0; j <= n; j++) dp[0][j] = 1;
        for (int j = 1; j <= n; j++)
            for (int i = 1; i <= m; i++)
                dp[i][j] = ((long)dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0))%1000000007;
        return dp[m][n];
    }
};