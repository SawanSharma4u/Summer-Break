class Solution {
    #define limit 1000000007
    vector<vector<int>> dp;
    int n , m;
    int help(vector<vector<int>>& grid, vector<vector<bool>>& visited, int i, int j){
        if(dp[i][j]!=-1) return dp[i][j];
        visited[i][j] = true;
        long ans = 1;
        if(i+1 < m && !visited[i+1][j] && grid[i+1][j] > grid[i][j]){
            ans += help(grid, visited, i+1, j);
            ans %= limit;
        }
        if(i-1 >= 0 && !visited[i-1][j] && grid[i-1][j] > grid[i][j]){
            ans += help(grid, visited, i-1, j);
            ans %= limit;
        }
        if(j+1 < n && !visited[i][j+1] && grid[i][j+1] > grid[i][j]){
            ans += help(grid, visited, i, j+1);
            ans %= limit;
        }
        if(j-1 >= 0 && !visited[i][j-1] && grid[i][j-1] > grid[i][j]){
            ans += help(grid, visited, i, j-1);
            ans %= limit;
        }
        visited[i][j] = false;
        return dp[i][j] = ans;
    }
public:
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        dp.resize(m, vector<int>(n, -1));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        long ans = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(dp[i][j]==-1){
                    ans += help(grid, visited, i, j);
                }
                else ans += dp[i][j];
                ans %= limit;
            }
            cout<<endl;
        }
        return ans;
    }
};