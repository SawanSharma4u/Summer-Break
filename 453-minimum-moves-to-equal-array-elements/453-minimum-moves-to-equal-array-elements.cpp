class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = nums[0];
        int n = nums.size()-1;
        for(int i = 0; i <= n; i++){
            mn = min(nums[i], mn);
        }
        int ans = 0;
        for(int i = 0; i <= n; i++){
            ans += nums[i];
        }
        return max(ans-(mn*(n+1)), 0);
    }
    
};