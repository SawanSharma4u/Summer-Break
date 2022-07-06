class Solution {
public:
    double champagneTower(int poured, int row, int glass) {
        double dp[101][101] = {{0}};
        dp[0][0] = poured;
        for(int i = 0; i < row; i++){
            for(int j = 0; j <= i; j++){
                dp[i+1][j] += max((dp[i][j] - 1)/2, double(0));
                dp[i+1][j+1] += max((dp[i][j] - 1)/2, double(0));
            }
        }
        return min(dp[row][glass], double(1));
    }
};