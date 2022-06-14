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
        vector<int> cur(m + 1, 0);
        cur[0] = 1;
        for (int j = 1; j <= n; j++) { 
            int pre = 1;
            for (int i = 1; i <= m; i++) {
                int temp = cur[i];
                cur[i] = ((long)cur[i] + (t[i - 1] == s[j - 1] ? pre : 0))%1000000007;
                pre = temp;
            }
        }
        return cur[m];
    }
};