class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<bool> dp(n, false);
        dp[0] = true;
        for(int i = 1; i < n; i++){
            if(dp[i-1]==true){
                int c = min(nums[i-1], n-i);
                while(c){
                    dp[i+c-1] = true;
                    c--;
                }
            }
        }
        return dp[n-1];
    }
};