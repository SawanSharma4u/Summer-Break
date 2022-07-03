class Solution {
    #define m 1000000007;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long> dp(n+1);
        dp[0] = 0;
        dp[1] = 1;
        int i = 2;
        for(; i <= delay; i++){
            dp[i] = 0;
        }
        for(; i <= n; i++){
            long sum = 0;
            for(int j = 0; j < forget-delay; j++){
                if(i-delay-j >= 0){
                    sum += dp[i-delay-j];
                    sum %= m;
                }
            }
            dp[i] = sum;
        }
        long ans = 0;
        for(i = n; i > n-forget; i--){
            ans += dp[i];
            ans %= m;
        }
        return ans;
    }
};