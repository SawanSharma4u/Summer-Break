class Solution {
public:
    int numSquares(int n) {
        int y = sqrt(n);
        vector<vector<int>> dp(y+1, vector<int>(n+1));
        for(int i = 0; i <= n; i++){
            dp[0][i] = INT_MAX;
        }
        for(int i = 0; i <= y; i++){
            dp[i][0] = 0;
        }
        for(int i = 1; i <= y; i++){
            for(int j = 1; j <= n; j++){
                if(i*i <= j){
                    dp[i][j] = min(1 + dp[i][j-i*i], dp[i-1][j]);
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[y][n];
    }
};