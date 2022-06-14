class Solution {
    vector<vector<int>> dp;
    int solve(int i, int j, string &A, string &B){
        if(i == A.size()) return B.size()-j;
        if(j == B.size()) return A.size()-i;

        if(dp[i][j]!=-1) return dp[i][j];

        if(A[i]==B[j]){
            return dp[i][j] = solve(i+1, j+1, A, B);
        }
        return dp[i][j] = 1 + min(solve(i+1, j+1, A, B), min(solve(i+1, j, A, B), solve(i, j+1, A, B)));
    }
    
public:
    int minDistance(string A, string B) {
        dp.resize(A.size(), vector<int>(B.size(), -1));
        return solve(0, 0, A, B);
    }
};