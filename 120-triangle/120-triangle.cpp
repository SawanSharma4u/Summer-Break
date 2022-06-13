class Solution {
//     vector<vector<int>> dp;
//     int solve(vector<vector<int>>& t, int x, int y){
//         if(x == t.size()) return 0;
//         if(dp[x][y]!=-1) return dp[x][y];
//         dp[x][y] = t[x][y] + min(solve(t, x+1, y), solve(t, x+1, y+1));
//         return dp[x][y];
//     }
// public:
//     int minimumTotal(vector<vector<int>>& t) {
//         dp.resize(t.size()+1, vector<int>(t.size()+1, -1));
//         return solve(t, 0, 0);
//     }
    public:
        int minimumTotal(vector<vector<int>>& t){
            vector<vector<int>> dp(t.size()+1, vector<int>(t.size()+1, INT_MAX));
            for(int i = 0; i < t.size()+1; i++){
                dp[0][i] = 0;
            }
            for(int i = 1; i <= t.size(); i++){
                for(int j = 1; j <= i; j++){
                    if(i == 1){
                        dp[i][j] = t[i-1][j-1];
                    }
                    else dp[i][j] = t[i-1][j-1] + min(dp[i-1][j], dp[i-1][j-1]);
                }
            }
            int ans = INT_MAX;
            int j = t.size();
            for(int i = 1; i <= t.size(); i++){
                ans = min(ans, dp[j][i]);
            }
            return ans;
        }
};