class Solution {
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& t, int x, int y){
        if(x == t.size()) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y] = t[x][y] + min(solve(t, x+1, y), solve(t, x+1, y+1));
        return dp[x][y];
    }
public:
    int minimumTotal(vector<vector<int>>& t) {
        dp.resize(t.size()+1, vector<int>(t.size()+1, -1));
        return solve(t, 0, 0);
    }
};