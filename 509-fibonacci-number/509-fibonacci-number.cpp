class Solution {
public:
    int fib(int n) {
        if(n<=0) return 0;
        if(n<=2) return 1;
        int dp[31] = {0,1,1};
        int ans;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i-2]+dp[i-1];
            if(i==n) ans = dp[i];
        }
        return ans;
    }
};