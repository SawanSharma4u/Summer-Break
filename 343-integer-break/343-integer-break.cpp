class Solution {
public:
    int integerBreak(int n) {
        if(n==2) return 1;
        int y = sqrt(n-1)+1;
        vector<vector<int>> dp(y+1, vector<int>(n+1));
        for(int i = 0; i < n+1; i++){
            dp[0][i] = 0;
        }
        for(int i = 0; i < y+1; i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i < y+1; i++){
            for(int j = 1; j < n+1; j++){
                if(i<=j){
                    dp[i][j] = max(i*dp[i][j-i], dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[y][n];
    }
};