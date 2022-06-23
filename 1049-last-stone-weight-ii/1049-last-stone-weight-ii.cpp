class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        if(stones.size()==1) return stones[0];
        int sum = 0;
        for(int i = 0; i < stones.size(); i++){
            sum += stones[i];
        }
        vector<vector<bool>> dp(stones.size()+1, vector<bool>(sum/2+1));
        for(int i = 0; i < sum/2+1; i++){
            dp[0][i] = false;
        }
        int n = stones.size();
        for(int i = 0; i <= n; i++){
            dp[i][0] = true;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= sum/2; j++){
                if(stones[i-1]<=j){
                    dp[i][j] = dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        int ans = INT_MAX;
        for(int i = 1; i <= sum/2; i++){
            if(dp[n][i]==true){
                ans = min(ans, sum-2*i);
            }
        }
        return ans;
    }
};