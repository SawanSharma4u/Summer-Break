class Solution {
    vector<int> dp;
    int helper(vector<int>& nums, int target){
        if(dp[target]!=-1) return dp[target];
        int res = 0;
        for(int i : nums){
            if(i <= target) res += helper(nums, target-i);
        }
        return dp[target] = res;
    }    
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        dp.resize(target+1, -1);
        dp[0] = 1;
        return helper(nums, target);
    }
};