class Solution {
    vector<vector<bool>> arr;
    vector<vector<int>> dp;
    int helper(string s, int i, int j){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(arr[i][j]) return dp[i][j] = 0;
        int ans = INT_MAX;
        for(int k = i; k < j; k++){
            if(arr[i][k]){
                int temp = 1 + helper(s, k+1, j);
                ans = min(ans, temp);
            }
        }
        return dp[i][j] = ans;
    }
public:
    int minCut(string s) {
        int n = s.length();
        arr.resize(n, vector<bool>(n));
        dp.resize(n, vector<int>(n, -1));
        for(int i = 0; i < n; i++){
            for(int j = 0, k = i; j < n && k < n; j++, k++){
                if(k-j==0){
                    arr[j][k] = true;
                }
                else if(k-j == 1){
                    if(s[j]==s[k]) arr[j][k] = true;
                    else arr[j][k] = false;
                }
                else{
                    if(s[j]==s[k] && arr[j+1][k-1]) arr[j][k] = true;
                    else arr[j][k] = false;
                }
            }
        }
        return helper(s, 0, n-1);
    }
};